/* 
 * File:   Polynome.h
 * Author: E104607D
 *
 * Created on 28 septembre 2015, 16:16
 */

#ifndef POLYNOME_H
#define	POLYNOME_H
#include "type.h"

class Polynome {
public:
    //Polynome();
    virtual void fill(real degree) = 0;
    virtual real resolve(real unknown) = 0;
    virtual void toString(void) = 0;
    //virtual ~Polynome() = 0;
private:

};

#endif	/* POLYNOME_H */

