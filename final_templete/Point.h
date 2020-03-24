//
// Created by Sophia Shuvar on 24.03.20.
//

#ifndef FINAL_TEMPLETE_POINT_H
#define FINAL_TEMPLETE_POINT_H
#endif //FINAL_TEMPLETE_POINT_H


#pragma once
#include <math.h>
#include <iostream>
#include <string>
using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    Point(int _x, int _y): x(_x), y(_y){}
    Point(const Point& a) :x(a.x), y(a.y){};

    friend istream & operator>>(istream & is, Point & a) {
        is >> a.x;
        is >> a.y;
        return is;
    }

    friend bool operator==(const Point & a, const Point & b) {
        return a.x == b.x && a.y == b.y;
    }

    friend ostream & operator<<(ostream & os, const Point & a) {
        os << "(" << a.x << "; " << a.y << ")";
        return os;
    }

    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

};

