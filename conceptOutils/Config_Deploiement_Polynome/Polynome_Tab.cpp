/* 
 * File:   Polynome_Tab.cpp
 * Author: E104607D
 * 
 * Created on 28 septembre 2015, 16:14
 */

#include "Polynome_Tab.h"

using namespace std;

Polynome_Tab::Polynome_Tab() {
    coefs.resize(1);
    real coef;
    cout << "Entrez le coef" << endl;
    cin >> coef;
    size = 0;
}

Polynome_Tab::Polynome_Tab(real degree) {
    size = degree;
    real coef;
    for (real i = 0; i <= degree; ++i) {
        cout << "Coefficient de x^"<<(degree-i) << endl; 
        cin >> coef;
        coefs.push_back(coef);
    }
}

Polynome_Tab::Polynome_Tab(const Polynome_Tab& orig) {
}

Polynome_Tab::~Polynome_Tab() {
}

real Polynome_Tab::resolve(real unknown) {
    if (size == 0) {
        return coefs.at(0);
    } 
    real result(coefs.at(0)*unknown+coefs.at(1));
    for (real i = 2; i <= this->size; ++i) {
        result = result*unknown + coefs.at(i);
    }
    return result;
}

void Polynome_Tab::fill(real degree){
    coefs.clear();
    real coef;
    for (real i = 0; i <= degree; ++i) {
        cout << "Coefficient de x^"<<(degree-i) << endl; 
        cin >> coef;
        this->coefs.push_back(coef);
    }
}

void Polynome_Tab::toString(void) {
    for (real i = 0; i <= size; ++i) {
        (i != size)? cout << coefs.at(i) << "*x^" << (size-i) << " + " : cout << coefs.at(i) << "*x^" << (size-i) << endl;
    }
}


