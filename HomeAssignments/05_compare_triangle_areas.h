//
// Created by Andriy Duda on 15.11.20.
//

#ifndef HOMEASSIGNMENTS_05_COMPARE_TRIANGLE_AREAS_H
#define HOMEASSIGNMENTS_05_COMPARE_TRIANGLE_AREAS_H

#endif //HOMEASSIGNMENTS_05_COMPARE_TRIANGLE_AREAS_H
#include <iostream>
using namespace std;

double dis_between_p(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}


double triangle_area(double a, double b, double c){
    if ((a + b <= c) || a + c <= b || b + c <= a) {
        cout << "Not a valid triangle";
        return -1;
    }
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}




void compare_areas(){
    double *x_points = new double[9];
    double *y_points = new double[9];
    double *areas = new double[3];

    for (int i = 0; i < 3; ++i) {
        cout << "\nEnter triangle " << i + 1 << ":\n" ;
        for (int j = 0; j < 3; ++j) {
            cout << "Point" << j + 1<< ": ";
            cin >> x_points[(i)*3 + j] >> y_points[(i)*3 + j];
        }
        double d1 = dis_between_p(x_points[i * 3], y_points[i * 3], x_points[i * 3 + 1], y_points[i * 3 + 1]);
        double d2 = dis_between_p(x_points[i * 3 + 1], y_points[i * 3 + 1], x_points[i * 3 + 2], y_points[i * 3 + 2]);
        double d3 = dis_between_p(x_points[i * 3 + 2], y_points[i * 3 + 2], x_points[i * 3], y_points[i * 3]);

        areas[i] = triangle_area(d1, d2, d3);
        if (areas[i] == -1) return;
    }


    bool max_indexes[] = {false, false, false};
    if (areas[0] > areas[1]) {
        if (areas[0] > areas[2]) max_indexes[0] = true;
        else if (areas[0] < areas[2]) max_indexes[2] = true;
        else  {max_indexes[0] = true; max_indexes[2] = true;}
    }
    else if (areas[0] < areas[1]) {
        if (areas[1] > areas[2]) max_indexes[1] = true;
        else if (areas[1] < areas[2]) max_indexes[2] = true;
        else  {max_indexes[1] = true; max_indexes[2] = true;}
    }
    else {
        if (areas[1] > areas[2]) {max_indexes[1] = true; max_indexes[0] = true;}
        else if (areas[1] < areas[2]) max_indexes[2] = true;
        else {max_indexes[0] = true; max_indexes[1] = true; max_indexes[2] = true;}
    }

    cout << "Max areas:\n";
    for (int k = 0; k < 3; ++k) {
        if (max_indexes[k]){
            cout << "Area = " << areas[k] << "\n";
            cout << "Points: \n";
            for (int i = 0; i < 3; ++i) {
                cout << x_points[k*3 + i] << " " << y_points[k*3 + i] << "\n";
            }
            cout << "\n";
        }
    }
}