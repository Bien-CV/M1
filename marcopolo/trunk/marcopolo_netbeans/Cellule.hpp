/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cellule.hpp
 * Author: dennisman
 *
 * Created on 7 décembre 2015, 09:40
 */

#ifndef CELLULE_HPP
#define CELLULE_HPP

class Cellule {
public:
    Cellule();
    Cellule(const Cellule& orig);
    virtual ~Cellule();
private:
    int type;
    // truc tmx ? 
    //si juste type, ca ne sert a rien de faire la classe cellule, autant tout mettre dans le tableau de la carte
    

};

#endif /* CELLULE_HPP */

