//
// Created by Sophia Shuvar on 03.03.20.
//

#ifndef ABSTRACT_CLASSES_TASK5_POINT_H
#define ABSTRACT_CLASSES_TASK5_POINT_H

#endif //ABSTRACT_CLASSES_TASK5_POINT_H
#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    Point(int _x, int _y): x(_x), y(_y){}

    double Lenght(Point & a) {
        return sqrt((a.x - x)*(a.x - x) + (a.y - y)*(a.y - y));
    }

    string toString(){
        return "(" + to_string(x) + ", " + to_string(y) + "), ";
    }

    friend istream & operator>>(istream & is, Point & a)
    {
        is >> a.x;
        is >> a.y;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Point & a)
    {
        os << "(" << a.x << "; " << a.y << " )";
        return os;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }
};