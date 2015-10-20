#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([polynome], [1.0.0], [dennis.bordet@etu.univ-nantes.fr])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_ARG_WITH(float,[--with-float on fait le programme avec des floats au lieu des doubles],
float=${with-float}, float=no)
if test $float=yes;then
    AC_DEFINE(WITH_FLOAT, 1, [on met les floats])
fi

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
