#include<cstdint>
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char** argv){
	if(argc!=2){ // argument 0 = nom du prog, argument 1 = premier argument
		cout << "vous devez passez le mot à trouver en parametre" << endl;
		return 0;
	}
	
	
	//-------------------prog-------------------
	
	//-------------------analyse du param-----------------
	
	
	/*for(auto i : chaine){
		cout << i << endl;
	}
	*/
	
	
	
	ifstream sowpods ("sowpods.txt");
	
	
	int cpt,i;
	string chaine = (string)argv[1];
	string line;	
	int len= chaine.size();
	if(sowpods.is_open()){
		while ( getline (sowpods,line) )
    	{
    		if(line.size()==len){
				cpt = 0;
				for(i = 0; i<len;++i){
					if(line[i] ==chaine[i] or chaine[i]=='.'){
						cpt++;
					}
				}
				if(cpt==len){
					cout<<line<<endl;
				}
    		}
      		
    	}
   		sowpods.close();
  	}
	
	
	
	
	
	cout << "occurences pour le mot "<<argv[1] << endl;
	return 1;
}
