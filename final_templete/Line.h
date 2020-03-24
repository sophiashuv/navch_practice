//
// Created by Sophia Shuvar on 24.03.20.
//

#ifndef FINAL_TEMPLETE_LINE_H
#define FINAL_TEMPLETE_LINE_H

#endif //FINAL_TEMPLETE_LINE_H
#pragma once
#include "Point.h"

class Line {
protected:
    Point first;
    Point second;
public:
    Line() :first(0, 0), second(0, 0){};
    Line(Point _first, Point _second) :first(_first), second(_second){};
    Line(const Line& a) :first(a.first), second(a.second){};
    ~Line() {};

    friend ostream & operator<<(ostream & os, Line & a) {
        os << "first = " << a.first << ", second = " << a.second << " Vector Coordinates: " << a.coords() << "\n";
        return os;
    }

    friend istream & operator>>(istream & is, Line & a) {
        is >> a.first;
        is >> a.second;
        return is;
    }

    const Point &getFirst() const {
        return first;
    }

    const Point &getSecond() const {
        return second;
    }

    Point coords(){
        Point p(first.getX() - second.getX(), first.getY() - second.getY());
        return p;
    }

    friend bool perpendicular(Line & a, Line & b){
        if(a.coords().getX() * b.coords().getX() + a.coords().getY() * b.coords().getY() == 0) {
            if (a.getFirst() == b.getFirst() || a.getFirst() == b.getSecond() ||
            a.getSecond() == b.getFirst() || a.getSecond() == b.getSecond()) return true;
            else return false;
        }
        else return false;
    }
};