#include<cstdint>
#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
#include<tbb/blocked_range.h>
#include "tbb/parallel_for.h"
//#include<tbb>

using namespace std;
using namespace tbb;

//g++ -Wall -o para_search search-seq-2cores.cpp -std=c++11 -ltbb

typedef blocked_range<int> range;
//-----------------class searchSeq-------------------

int main(int argc, char** argv){
	if(argc!=2){ // argument 0 = nom du prog, argument 1 = premier argument
		cout << "vous devez passez le mot à trouver en parametre" << endl;
		return 0;
	}
	
	


	string chaine = (string)argv[1];
	
	vector<string> dico;
	
	class searchSeq{
    public:
	    searchSeq(vector<string>& a, int v, string ch): T(a), len(v), chaine(ch){}
	    void operator()(const range& r) const{
	      int cpt,i;
		    for(string ligne : T)
		    {
			    if(ligne.size()==len){
				    cpt = 0;
				    for(i = 0; i<len;++i){
					    if(  chaine[i]=='.' or ligne[i] ==chaine[i]){
						    cpt++;
					    }else{
						    break;
					    }
				    }
				    if(cpt==len){
					    cout<<ligne<<endl;
				    }
			    }
	      		
		    }
	    }
    private:
	    vector<string>& T;
	    int len;
	    string chaine;
	
};

  string line;
	ifstream sowpods ("sowpods.txt");
	if(sowpods.is_open()){
		int indice =0;
		while ( getline (sowpods,line) )
    	{
    		dico.push_back(line);
    	}
    sowpods.close();
  	}
  	
  	const int sz = 267750;
    
	//compteur
    auto begin = std::chrono::high_resolution_clock::now();
    	
	  int len= chaine.size();

	
   	parallel_for(range(0,sz,267750/2), searchSeq(dico, len, chaine));	
	
	
	
	
	
	cout << "occurences pour le mot "<<argv[1] << endl;
	
	auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << "ms" << std::endl;

   
//---------------------nouveau main-----------------------

	return 1;
}
