/* 
 * File:   main.cpp
 * Author: E104607D
 *
 * Created on 28 septembre 2015, 16:13
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include "Polynome_Tab.h"
#include "Polynome_List.h"
#include "type.h"

using namespace std;

/*
 *    
 */
int main(int argc, char** argv) {
    Polynome_List t{3};
    
    cout << "Résolution avec x = 10" << endl;
    cout << t.resolve(10) << endl;
    return 0;
}

