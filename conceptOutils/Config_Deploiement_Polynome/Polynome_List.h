/* 
 * File:   Polynome_List.h
 * Author: E104607D
 *
 * Created on 28 septembre 2015, 16:15
 */

#ifndef POLYNOME_LIST_H
#define	POLYNOME_LIST_H
#include "Polynome.h"
#include "type.h"
#include <iostream>
#include <list>


class Polynome_List : public Polynome {
public:
    Polynome_List();
    Polynome_List(real degree);
    Polynome_List(const Polynome_List& orig);
    void fill(real degree);
    real resolve(real unknown);
    void toString(void);
    ~Polynome_List();
private:
    real size;
    std::list<real> coefs;
};

#endif	/* POLYNOME_LIST_H */

