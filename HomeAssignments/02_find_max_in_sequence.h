//
// Created by Andriy Duda on 13.11.20.
//


#ifndef HOMEASSIGNMENTS_02_FIND_MAX_IN_SEQUENCE_H
#define HOMEASSIGNMENTS_02_FIND_MAX_IN_SEQUENCE_H

#endif //HOMEASSIGNMENTS_02_FIND_MAX_IN_SEQUENCE_H
#include <iostream>
using namespace std;


void find_max_in_sequence(){
    double STOP = 0, element = 0;
    cout << "Enter sequence with 0 in the end: ";
    cin >> element;
    double max_el = element;
    while (element != STOP){
        if (max_el < element){
            max_el = element;
        }
        cin >> element;
    }
    cout << max_el;
}