/* 
 * File:   IABord.cpp
 * Author: E125757S
 * 
 * Created on 16 novembre 2015, 17:16
 */

#include "IABord.hpp"

IABord::IABord(Robot robot):IA(robot){}
IABord::~IABord(){}

/**
* \brief Le robot longe les bords de la carte.
* Méthode parcourant la carte en suivant les bords dans le sens des aiguilles d'une montre
* et en utilisant seulement les senseurs de contact (collision avec obstacle)
* @pre l'environnement à explorer est borné.
* @param cell L'id de la cellule dont le contenu sera retourné.
* */
IABord::miseEnMarche(){
    avancerHaut();
    int bordSuivi = 0;
    int cellDepart = getCell();
    int cellActuelle = -1;
    while(cellDepart != cellActuelle){
        switch bordSuivi {
            case 0: // le bord suivi est en haut du robot
                if (avancerHaut(1)){
                    bordSuivi = 3;
                }else if (!avancerDroite(1)){
                    avancerBas(1);
                    bordSuivi = 1;
                }
                break;
            case 1: // le bord suivi est à droite du robot
                if (avancerDroite(1)){
                    bordSuivi = 0;
                }else if (!avancerBas(1)){
                    avancerGauche(1);
                    bordSuivi = 2;
                }
                break;
            case 2: // le bord suivi est en bas du robot
                if (avancerBas(1)){
                    bordSuivi = 1;
                }else if (!avancerGauche(1)){
                    avancerHaut(1);
                    bordSuivi = 3;
                }
                break;
            case 3: // le bord suivi est à gauche du robot
                if (avancerGauche(1)){
                    bordSuivi = 2;
                }else if (!avancerHaut(1)){
                    avancerDroite(1);
                    bordSuivi = 0;
                }
                break;
        }
        cellActuelle = getCell();
    }
    
}

