//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_07_MIN_MAX_H
#define HOMEASSIGNMENTS_07_MIN_MAX_H

#endif //HOMEASSIGNMENTS_07_MIN_MAX_H


#include <iostream>
using namespace std;


void min_max(){
    double x, y, z;
    cout << "Enter x, y, z: " ;
    cin >> x >> y >> z;
    double max_y_z = y > z ? y : z;
    double u = x < max_y_z ? x : max_y_z;
    cout << "u = " << u;
}
