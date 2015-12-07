/* 
 * File:   IAMedium.cpp
 * Author: vandorallen
 * 
 * Created on 4 décembre 2015, 18:18
 */

#include "IAMedium.hpp"
#include "IA.hpp"

IAMedium::IAMedium() {
}

IAMedium::~IAMedium() {
}

void IAMedium::miseEnMarche() {
    int cellNonVisitee;
    vector<direction> directions;
    while (robot.getCellsUnknown().size() != 0) {
        cellNonVisitee = celluleLaPlusProcheNonVisitee();
        directions = itineraireAvecAStar(cellNonVisitee);
        robot.effectuerDeplacements(directions);
    }
}

