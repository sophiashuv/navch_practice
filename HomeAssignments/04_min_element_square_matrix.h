//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_MIN_ELEMENT_SQUARE_MATRIX_H
#define HOMEASSIGNMENTS_MIN_ELEMENT_SQUARE_MATRIX_H

#endif //HOMEASSIGNMENTS_MIN_ELEMENT_SQUARE_MATRIX_H

#include <iostream>
using namespace std;


double min_in_triangle(double ** mas, int n){
    double min = 10000000;

    for (int i = 0; i < ceil(n/2.0); ++i) {
        for (int j = 1; j < i + 2; ++j) {
            if (mas[i][n - j] < min) {
                min = mas[i][n - j];
            }
//            cout << mas[i][n - j] << " ";
        }
    }

    for (int i = n - 1; i > ceil(n/2.0) - 1; --i) {
        for (int j = i; j < n; ++j) {
            if (mas[i][j] < min) {
                min = mas[i][j];
            }
//            cout << mas[i][j] << " ";
        }
    }
    return min;
}

double ** fill_matrix(int n){
    double **mas = new double *[n];
    for (int i = 0; i < n; ++i) {
        mas[i] = new double[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mas[i][j];
        }
    }
    return mas;
}


void min_element_square_matrix(){
    int n;
    cout << "Enter num of lines: ";
    cin >> n;
    cout << "Enter matrix : \n";
    double **mas = fill_matrix(n);
    cout << "\nMin element in right triangle is " <<  min_in_triangle(mas, n) << "\n";
}