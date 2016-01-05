//main.cpp

//g++ -std=c++11 -pthread -o main main.cpp
#include<cstdint>
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>

#include "semaphore.h"
using namespace std;

enum typeVestiaire{
    VIDE,
    FILLE,
    GARS
};

//------------------------------initialisation--------------------------------

typeVestiaire contenu = VIDE;
Semaphore sem_contenu = new Semaphore(1);
Semaphore EntreeDispo = new Semaphore(3);
int nbEntreeDispo = 3;
mutex display_mutex;

//------------------------------

struct Homme{
    Homme(int i) : id(i){}
    void operator()(void){
        bool in = false;
        //lock contenu
        P( sem_contenu);
        if (contenu == VIDE){
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<" et Je rentre en 1er" << endl;
        }
           
            contenu = GARS;    
            //lock nbEntreeDispo
            P( EntreeDispo);
            in = true;
            nbEntreeDispo--;
        }
        else if (contenu == GARS){
            //lock nbEntreeDispo
            P( EntreeDispo);
            {
                lock_guard<mutex> guard(display_mutex);
                cout << "je suis l'homme" << id <<" et je rentre" << endl;
            }
            in = true;
            nbEntreeDispo--;           
        }        
        //free contenu
        V( sem_contenu);
        this_thread:: sleep_for(chrono::seconds(2));
        if (in){
            //free baton
            V( EntreeDispo);
            {
                lock_guard<mutex> guard(display_mutex);
                cout << "je suis l'homme" << id <<" et je sors" << endl;
            }
            nbEntreeDispo++;
        }
        
        
    }
    int id;
};

struct Femme{
    Femme(int i) : id(i){}
    void operator()(void){
        
        cout << "je suis la femme" << id << endl;
        
    }
    int id;
};
/*
void entrer(){
    
}

void sortir(){

}
*/

int main(){
    
    
    
    vector<thread> allthreads;
    allthreads.push_back(thread(Homme(1)));
    allthreads.push_back(thread(Homme(2)));
    allthreads.push_back(thread(Homme(3)));
    allthreads.push_back(thread(Homme(4)));
    allthreads.push_back(thread(Homme(5)));
    allthreads.push_back(thread(Homme(6)));
    allthreads.push_back(thread(Homme(7)));
    allthreads.push_back(thread(Homme(8)));
    
    // on s'assure que le programme ne se termine que lorsque tous les threads ont fini
    for (auto& t : allthreads){
        t.join();
    }
    
    return 0;
}
