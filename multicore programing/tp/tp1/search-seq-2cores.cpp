#include<cstdint>
#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>
#include<tbb/blocked_range.h>
#include<tbb/parallel_for.h>
using namespace std;
using namespace tbb;

typedef blocked_range<int> range;
//-----------------class searchSeq-------------------
class searchSeq{
public:
	searchSeq(vector<string>& a), double v): T(a), val(v){}
	void operator()(const range& r) const{
		for (int i=r.begin(); i!=r.end();++i){
			// coeur de la fct
		}
	}
private:
}
int main(int argc, char** argv){
	if(argc!=2){ // argument 0 = nom du prog, argument 1 = premier argument
		cout << "vous devez passez le mot à trouver en parametre" << endl;
		return 0;
	}
	
	


	int cpt,i;
	string chaine = (string)argv[1];
	string line;
	vector<string> dico;
	
	ifstream sowpods ("sowpods.txt");
	if(sowpods.is_open()){
		int indice =0;
		while ( getline (sowpods,line) )
    	{
    		dico.push_back(line);
    	}
    sowpods.close();
  	}
    
    
	
	//compteur
    auto begin = std::chrono::high_resolution_clock::now();
    	
	int len= chaine.size();

	for(string line : dico)
	{
		if(line.size()==len){
			cpt = 0;
			for(i = 0; i<len;++i){
				if(  chaine[i]=='.' or line[i] ==chaine[i]){
					cpt++;
				}else{
					break;
				}
			}
			if(cpt==len){
				cout<<line<<endl;
			}
		}
  		
	}
   		
	
	
	
	
	
	cout << "occurences pour le mot "<<argv[1] << endl;
	
	auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end-begin).count() << "ms" << std::endl;
   

	return 1;
}
