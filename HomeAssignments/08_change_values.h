//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_08_CHANGE_VALUES_H
#define HOMEASSIGNMENTS_08_CHANGE_VALUES_H

#endif //HOMEASSIGNMENTS_08_CHANGE_VALUES_H


#include <iostream>
using namespace std;


void change_values(){
    double x, y;
    cout << "Enter x, y: " ;
    cin >> x >> y;
    double half_sum = (x + y) / 2.0;
    double twice_product = x * y * 2.0;
    if (x < y) {
        x = half_sum;
        y = twice_product;
    }
    else {
        y = half_sum;
        x = twice_product;
    }
    cout << "x = " << x << "\ny = " << y << "\n";
}

