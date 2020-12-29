//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_06_ABS_SUM_H
#define HOMEASSIGNMENTS_06_ABS_SUM_H

#endif //HOMEASSIGNMENTS_06_ABS_SUM_H


#include <iostream>
using namespace std;


void abs_sum(){
    int n;
    double a, sum = 0;
    cout << "Enter amount: ";

    while (!(cin >> n) || n < 0) {
        cin.clear();
        while (cin.get() != '\n') continue;
        cout << "Enter amount: ";
    }

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        while (!(cin >> a)){
            cin.clear();
            while (cin.get() != '\n') continue;}
        sum += abs(a);
    }

    cout << "\nSum: " << sum << ".\n";
}
