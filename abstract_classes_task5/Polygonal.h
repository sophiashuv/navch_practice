//
// Created by Sophia Shuvar on 03.03.20.
//

#ifndef ABSTRACT_CLASSES_TASK5_POLYGONAL_H
#define ABSTRACT_CLASSES_TASK5_POLYGONAL_H

#endif //ABSTRACT_CLASSES_TASK5_POLYGONAL_H
#pragma once
#include "Line.h"
#include "Point.h"
class Polygonal: public Line{
protected:
Point first;
Point second;
Point third;
public:
Polygonal() :first(0, 0), second(0, 0), third(0, 0){};
Polygonal(Point _first, Point _second, Point _third) :first(_first), second(_second), third(_third){};
Polygonal(const Polygonal& a) :first(a.first), second(a.second), third(a.third){};
~Polygonal() {};


void print(){
    cout << "first = " << first << ", second = " << second << ", third = " << third << "Length: " << length() << "\n";
}

double length(){
    return sqrt((first.getX() - second.getX())*(first.getX() - second.getX()) + (first.getY()
    - second.getY())*(first.getY() - second.getY())) + sqrt((third.getX() - second.getX())*(third.getX()
    - second.getX()) + (third.getY() - second.getY())*(third.getY() - second.getY()));
}

};