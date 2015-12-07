/* 
 * File:   IA.cpp
 * Author: E129986P
 * 
 * Created on 16 novembre 2015, 17:16
 */

#include "IA.hpp"
#include "Robot.hpp"

#include <algorithm>

IA::IA(Robot robot) : _robot(robot) {
}

IA::~IA() {
}

IA::miseEnMarche() {
}

vector<int> IA::itineraireAvecAStar(int destination) {
}

int IA::celluleLaPlusProcheNonVisite() {
    int distanceMaxBord = max(IA::getCellDistance(IA::getCell(),0),IA::getCellDistance(IA::getCell(),1023));
    vector<int> cellulesprox;
    for(int i=1; i<=distanceMaxBord ; i++){
        cellulesprox = IA::getCelluleALaDistance(i);
        for(int j=0 ; j<cellulesprox.size() ; j++){
            if(IA::getCellContent(cellulesprox.at(j))==2){
                return cellulesprox.at(j);
            }
        }
    }
    return -1;
}

int IA::celluleLaPlusLoinNonVisitee(){
    
}

//----------Redefinition des methodes du robot----------

    int IA::getCellContent(int cell){
        return _robot.getCellContent(cell);
    }    
    
    int IA::getCell(){
        return _robot.getCell();
    }    
    
    int IA::getCellDistance(int cell1, int cell2){
        return _robot.getCellDistance(cell1,cell2);
    }    
    
    bool IA::isEmptyCell(int cell){
        return _robot.isEmptyCell(cell);
    }    
   
    bool IA::isObstacle(int cell){
        return _robot.isObstacle(cell);
    }    
    bool IA::isUnknown(int cell){
        return _robot.isUnknown(cell);
    }    
    
    bool IA::isOnSameLine(int cell1, int cell2){
        return _robot.isOnSameLine(cell1, cell2);
    }    
    vector<int> IA::getCelluleALaDistance(int distance){
        return _robot.getCelluleALaDistance(distance);
    }    

    int IA::getCellsDiscoveredSize(){
        return _robot.getCellsDiscoveredSize();
    }    

    int IA::getCellsUnknownSize(){
        return _robot.getCellsUnknownSize();
    }
    vector<int> IA::getCellsUnknown(){
        return _robot.getCellsUnknown();
    }
    vector<int> IA::getCellsDiscovered(){
        return _robot.getCellsDiscovered();
    }    

    int IA::getMapSize(){
        return _robot.getMapSize();
    }    

    int IA::moveTowardCell( int cell){
        return _robot.moveTowardCell( cell);
    }    

    int IA::avancerHaut(){
        return _robot.;
    }    

    int IA::avancerHaut(int nb){
        return _robot.avancerHaut(nb);
    }    

    int IA::avancerBas(){
        return _robot.avancerBas();
    }

    int IA::avancerBas(int nb){
        return _robot.avancerBas(nb);
    }    

    int IA::avancerGauche(){
        return _robot.avancerGauche();
    }    

    int IA::avancerGauche(int nb){
        return _robot.avancerGauche(nb);
    }    

    int IA::avancerDroite(){
        return _robot.avancerDroite();
    }    

    int IA::avancerDroite(int nb){
        return _robot.avancerDroite(nb);
    }    

    int IA::getDroiteCell(){
        return _robot.getDroiteCell();
    }    

    int IA::getDroiteCell(int cell){
        return _robot.getDroiteCell(cell);
    }    

    int IA::getGaucheCell(){
        return _robot.getGaucheCell();
    }    

    int IA::getGaucheCell(int cell){
        return _robot.getGaucheCell(cell);
    }    

    int IA::getBasCell(){
        return _robot.getBasCell();
    }    

    int IA::getBasCell(int cell){
        return _robot.getBasCell(cell);
    }    

    int IA::getHautCell(){
        return _robot.getHautCell();
    }    

    int IA::getHautCell(int cell){
        return _robot.getHautCell(cell);
    }    

    bool  IA::peutAllerADroite(){
        return _robot.peutAllerADroite();
    }
         
    bool  IA::peutAllerAGauche(){
        return _robot.peutAllerAGauche();
    }
         
    bool  IA::peutAllerEnBas(){
        return _robot.peutAllerEnBas();
    }
         
    bool  IA::peutAllerEnHaut(){
        return _robot.peutAllerEnHaut();
    }
    bool IA::effectuerDeplacements(vector<direction> directions){
        return _robot.effectuerDeplacements(directions);
    }
