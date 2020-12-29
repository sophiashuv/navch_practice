//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_11_COUNT_SUM_H
#define HOMEASSIGNMENTS_11_COUNT_SUM_H

#endif //HOMEASSIGNMENTS_11_COUNT_SUM_H


#include <iostream>
using namespace std;


void count_sum(){
    int n;
    double x = 1, y = 1, sum = 0;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        sum += x/(1.0 + abs(y));
        y += x;
        x = 0.3*x;
    }
    cout << "Sum = " << sum;
}
