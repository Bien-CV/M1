/* 
 * File:   Polynome_List.cpp
 * Author: E104607D
 * 
 * Created on 28 septembre 2015, 16:15
 */

#include "Polynome_List.h"
using namespace std;

Polynome_List::Polynome_List() {
    real coef;
    cout << "Entrez le coef" << endl;
    cin >> coef;
    coefs.push_back(coef);
    size = 0;
}

Polynome_List::Polynome_List(real degree) {
    size = degree;
    real coef;
    for (real i = 0; i <= degree; ++i) {
        cout << "Coefficient de x^"<<(degree-i) << endl; 
        cin >> coef;
        coefs.push_back(coef);
    }
}

Polynome_List::Polynome_List(const Polynome_List& orig) {
}

Polynome_List::~Polynome_List() {
}

void Polynome_List::fill(real degree) {
    coefs.clear();
    size = degree;
    real coef;
    for (real i = 0; i <= degree; ++i) {
        cout << "Coefficient de x^"<<(degree-i) << endl; 
        cin >> coef;
        coefs.push_back(coef);
    }
}

real Polynome_List::resolve(real unknown) {
    list<real>::iterator i;
    if (size == 0) {
        return *coefs.begin();
    } 
    
    real result =  *coefs.begin()*unknown + *(coefs.begin()++);
    if (size == 1) return result;
    
    i = coefs.begin();
    i++; i++;
    while (i != coefs.end()){
        result = result*unknown + *i;
        ++i;
    }
    return result;
}

void Polynome_List::toString(void){
    
}
