/* 
 * File:   IAUpAndDown.cpp
 * Author: vandorallen
 * 
 * Created on 30 novembre 2015, 16:20
 */

#include "IAUpAndDown.hpp"

IAUpAndDown::IAUpAndDown() {
}

IAUpAndDown::~IAUpAndDown() {
}

/**
 * @brief Le robot va dans le coin sud ouest de la carte, puis démarre son exploration en allant de haut en bas, et en se décallant à chaque aller retour
 * @pre l'environnement à explorer doit etre borné.
 * @return 
 */
IAUpAndDown::miseEnMarche() {
    while (robot.peutAllerEnBas() || robot.peutAllerAGauche() ) {
        while(robot.avancerBasUneFois());
        while(robot.avancerGaucheUneFois());
    }
    //On suppose que désormais le robot est dans le coin SO
    while (robot.peutAllerEnHaut()|| robot.peutAllerADroite() ) {
        while(robot.allerHautUneFois());
        allerADroite();
        while(robot.allerBasUneFois());
    }
}

