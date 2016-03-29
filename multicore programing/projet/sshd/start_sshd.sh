#!/bin/bash
#
# Création d'une paire de clée host pour le daemon ssh
# Et démmarage du deamon sshd
# 
#---------------------------------------------

BASE_CONFIG=~/.ssh/sshd
SSHD=/usr/sbin/sshd
SSHD_PORT=2222

#---------------------------------------------
get_config_option() {
        option="$1"

        [ -f $BASE_CONFIG/sshd_config ] || return
        # TODO: actually only one '=' allowed after option
        perl -lne 's/\s+/ /g; print if s/^\s*'"$option"'[[:space:]=]+//i' \
           $BASE_CONFIG/sshd_config
}

host_keys_required() {
                # No HostKey directives at all, so the server picks some
                # defaults depending on the setting of Protocol.
                protocol="$(get_config_option Protocol)"
                [ "$protocol" ] || protocol=1,2
                if echo "$protocol" | grep 1 >/dev/null; then
                        echo $BASE_CONFIG/ssh_host_key
                fi
                if echo "$protocol" | grep 2 >/dev/null; then
                        echo $BASE_CONFIG/ssh_host_rsa_key
                        echo $BASE_CONFIG/ssh_host_dsa_key
                fi

}


create_key() {
        msg="$1"
        shift
        hostkeys="$1"
        shift
        file="$1"
        shift

        if echo "$hostkeys" | grep -x "$file" >/dev/null && \
           [ ! -f "$file" ] ; then
                echo -n $msg
                ssh-keygen -q -f "$file" -N '' "$@"
                echo
                if type restorecon >/dev/null 2>&1; then
                        restorecon "$file.pub"
                fi
        fi
}


create_keys() {
 
	hostkeys="$(host_keys_required)"

        create_key "Creating SSH1 key; this may take some time ..." \
                "$hostkeys" $BASE_CONFIG/ssh_host_key -t rsa1

        create_key "Creating SSH2 RSA key; this may take some time ..." \
                "$hostkeys" $BASE_CONFIG/ssh_host_rsa_key -t rsa
        create_key "Creating SSH2 DSA key; this may take some time ..." \
                "$hostkeys" $BASE_CONFIG/ssh_host_dsa_key -t dsa
}


echo "o Copie du fichier sshd_config "
rm -rf $BASE_CONFIG
mkdir -p $BASE_CONFIG
cp sshd_config $BASE_CONFIG/
echo "o Generation des clees host"
create_keys 
echo "o Demarrage du serveur sshd sur le port $SSHD_PORT"
$SSHD -f $BASE_CONFIG/sshd_config -p $SSHD_PORT

