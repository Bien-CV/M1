//ballsfirst.cpp

//g++ -std=c++11 -pthread -o ballsfirst ballsfirst.cpp
#include "semaphore.h"
#include<cstdint>
#include<iostream>
#include<vector>
#include<thread>
#include<mutex>


using namespace std;

enum typeVestiaire{
    VIDE,
    FILLE,
    GARS
};

//------------------------------initialisation--------------------------------

typeVestiaire contenu = VIDE;
Semaphore sem_contenu(1);
Semaphore EntreeDispo(3);
int nbEntreeDispo = 3;
mutex display_mutex;
int id = 0;
//------------------------------


void Homme(){
  id ++;
  while(true){
    bool in = false;
    
    
    //-------------ENTREE-------------------------------------
    //verif rapide du nombre d'entrées dispo
    if (nbEntreeDispo ==3){
      P(EntreeDispo);// on prend une place
      P(sem_contenu); //on verouille la pancarte du contenu pour que personne n'y touche
      nbEntreeDispo--;
      if(nbEntreeDispo == 2){ // on est clairement le premier a entrer.
        contenu = GARS;
        V(sem_contenu);
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<" et je rentre en 1er" << endl;
        }
        in = true;
      }else if(contenu==GARS){ // quelqu'un vient juste de rentrer et c'est un homme.
        V(sem_contenu);
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<" et je rentre presque en 1er" << endl;
        }
        in = true;
      }else{ //quelqu un vient juste de rentrer et ce n'est pas un homme
        V(sem_contenu);
        V(EntreeDispo);
        nbEntreeDispo++;
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<" et je viens de me faire griller par une femme" << endl;
        }
      }       
    }else if (nbEntreeDispo > 0 and contenu !=FILLE){
      P(EntreeDispo);// on prend une place
      P(sem_contenu); //on verouille la pancarte du contenu pour que personne n'y touche
      nbEntreeDispo--;
      if(contenu == GARS){
        V(sem_contenu);
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<" et je rentre" << endl;
        }
        in = true;
      }else{
         V(sem_contenu);
         V(EntreeDispo);
         nbEntreeDispo++;
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<", tous les hommes sont sortis et je viens de me faire griller par une femme" << endl;
        }
      }
    }
    
    
    
    //----------------SORTIE--------------------------------
    this_thread::sleep_for(chrono::seconds(2));
    if(in){
      V(EntreeDispo);
      nbEntreeDispo++;
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis l'homme" << id <<" et je sors" << endl;
        }
        
    }
  }
}

void Femme(){
  id++;
  while(true){
    bool in = false;
    
    
    //-------------ENTREE-------------------------------------
    //verif rapide du nombre d'entrées dispo
    if (nbEntreeDispo ==3){
      P(EntreeDispo);// on prend une place
      P(sem_contenu); //on verouille la pancarte du contenu pour que personne n'y touche
      nbEntreeDispo--;
      if(nbEntreeDispo == 2){ // on est clairement le premier a entrer.
        contenu = FILLE;
        V(sem_contenu);
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis la femme" << id <<" et je rentre en 1er" << endl;
        }
        in = true;
      }else if(contenu==FILLE){ // quelqu'un vient juste de rentrer et c'est un homme.
        V(sem_contenu);
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis la femme" << id <<" et je rentre presque en 1er" << endl;
        }
        in = true;
      }else{ //quelqu un vient juste de rentrer et ce n'est pas un homme
        V(sem_contenu);
        V(EntreeDispo);
        nbEntreeDispo++;
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis la femme" << id <<" et je viens de me faire griller par un homme" << endl;
        }
      }       
    }else if (nbEntreeDispo > 0 and contenu !=GARS){
      P(EntreeDispo);// on prend une place
      P(sem_contenu); //on verouille la pancarte du contenu pour que personne n'y touche
      nbEntreeDispo--;
      if(contenu == GARS){
        V(sem_contenu);
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis la femme" << id <<" et je rentre" << endl;
        }
        in = true;
      }else{
         V(sem_contenu);
         V(EntreeDispo);
         nbEntreeDispo++;
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis la femme" << id <<", tous les hommes sont sortis et je viens de me faire griller par un homme" << endl;
        }
      }
    }
    
    
    
    //----------------SORTIE--------------------------------
    this_thread::sleep_for(chrono::seconds(3));
    if(in){
      V(EntreeDispo);
      nbEntreeDispo++;
        {
            lock_guard<mutex> guard(display_mutex);
            cout << "je suis la femme" << id <<" et je sors" << endl;
        }
    }
  }
}


int main(){
    
    
    
    vector<thread> allthreads;
    allthreads.push_back(thread(Homme));
    allthreads.push_back(thread(Homme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Homme));
    allthreads.push_back(thread(Homme));
    allthreads.push_back(thread(Homme));
    allthreads.push_back(thread(Homme));

    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Femme));
    allthreads.push_back(thread(Homme));
    allthreads.push_back(thread(Homme));
    
    
    // on s'assure que le programme ne se termine que lorsque tous les threads ont fini
    for (auto& t : allthreads){
        t.join();
    }
    
    return 0;
}

        
