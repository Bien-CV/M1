/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carte.hpp
 * Author: dennisman
 *
 * Created on 7 décembre 2015, 09:33
 */

#ifndef CARTE_HPP
#define CARTE_HPP
#include<string>

class Carte {
public:
    Carte();
    Carte(const Carte& orig);
    virtual ~Carte
    
    void readTMX(std::string filename);
    
    
private:
    vector<Cellule> cells;
    int mapSize;
    

};

#endif /* CARTE_HPP */

