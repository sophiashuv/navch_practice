//
// Created by Andriy Duda on 13.11.20.
//


#ifndef HOMEASSIGNMENTS_03_ARRAY_TASKS_H
#define HOMEASSIGNMENTS_03_ARRAY_TASKS_H

#endif //HOMEASSIGNMENTS_03_ARRAY_TASKS_H

#include <iostream>
using namespace std;


double min_in_array(double * arr, int n){
    double min_el = arr[0];
    for (int i = 1; i < n; ++i) {
        if (min_el >  arr[i]){
            min_el = arr[i];
        }
    }
    return min_el;
}

void sum_between_two_positives(double * arr, int n){
    int first_positive_index; bool is_positive = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            first_positive_index = i;
            is_positive = true;
            break;
        }
    }
    if (is_positive){
        int last_positive_index;
        for (int i = n - 1; i > 0; --i) {
            if (arr[i] > 0) {
                last_positive_index = i;
                break;
            }
        }

        int sum = 0;
        for (int j = first_positive_index + 1; j < last_positive_index; ++j) {
            sum += arr[j];
        }

        cout << "Sum of elements located between " << arr[first_positive_index] << " and " << arr[last_positive_index]
             << " is " << sum << "\n";
    }
    else {
        cout << "There's no positive numbers in array\n";
    }
}


void array_tasks(){
    int n;
    cout << "\nEnter amount of elements in array: ";
    cin >> n;
    cout << "\nEnter elements of array: ";
    double *arr = new double[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "\nMin element in array is: " << min_in_array(arr, n) << "\n";
    sum_between_two_positives(arr, n);
}