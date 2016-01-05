/* 
 * File:   Polynome_Tab.h
 * Author: E104607D
 *
 * Created on 28 septembre 2015, 16:14
 */

#ifndef POLYNOME_TAB_H
#define	POLYNOME_TAB_H
#include "Polynome.h"
#include "type.h"
#include <vector>
#include <iostream>

class Polynome_Tab : public Polynome {
public:
    Polynome_Tab();
    Polynome_Tab(real degree);
    Polynome_Tab(const Polynome_Tab& orig);
    real resolve(real unknown);
    void fill(real degree);
    void toString(void);
    ~Polynome_Tab();
private:
    real size; //degree
    std::vector<real> coefs;
};

#endif	/* POLYNOME_TAB_H */

