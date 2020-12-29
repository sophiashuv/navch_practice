//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_09_FIND_ANOTHER_H
#define HOMEASSIGNMENTS_09_FIND_ANOTHER_H

#endif //HOMEASSIGNMENTS_09_FIND_ANOTHER_H


#include <iostream>
using namespace std;


void find_another(){
    double x, y, z, t;
    cout << "Enter x, y, z, t: " ;
    cin >> x >> y >> z >> t;

    double m = x == y ? (x == z ? t : z) : (x == z ? y : x);
    cout << m;
}
