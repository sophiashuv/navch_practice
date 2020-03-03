//
// Created by Sophia Shuvar on 03.03.20.
//

#ifndef ABSTRACT_CLASSES_TASK5_SEGMENT_H
#define ABSTRACT_CLASSES_TASK5_SEGMENT_H

#endif //ABSTRACT_CLASSES_TASK5_SEGMENT_H
#pragma once
#include "Line.h"
#include "Point.h"
class Segment: public Line{
protected:
    Point first;
    Point second;
public:
    Segment() :first(0, 0), second(0, 0){};
    Segment(Point _first, Point _second) :first(_first), second(_second){};
    Segment(const Segment& a) :first(a.first), second(a.second){};
        ~Segment() {};

    void print(){
        cout << "first = " << first << ", second = " << second <<  "Length: " << length() << "\n";
    }
    double length(){
        return sqrt((first.getX() - second.getX())*(first.getX() - second.getX())
        + (first.getY() - second.getY())*(first.getY() - second.getY()));
    }
};