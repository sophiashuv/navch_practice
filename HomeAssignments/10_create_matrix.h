//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_10_CREATE_MATRIX_H
#define HOMEASSIGNMENTS_10_CREATE_MATRIX_H

#endif //HOMEASSIGNMENTS_10_CREATE_MATRIX_H


#include <iostream>
using namespace std;


void print_matrix(double **matrix, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void create_matrix(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    double **matrix = new double *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
    }

    for (int i = 0; i < ceil(n/2.0); ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i && j < n-i-1) {
                matrix[i][j] = 0;
                matrix[n - i-1][j] = 0;
            }
            else {
                matrix[i][j] = 1;
                matrix[n - i-1][j] = 1;
            }
        }
    }

    print_matrix(matrix, n);

}
