//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef AGGREGATION_COMPOSITION_TASK1_PROBATION_H
#define AGGREGATION_COMPOSITION_TASK1_PROBATION_H

#endif //AGGREGATION_COMPOSITION_TASK1_PROBATION_H
#pragma once

#include <iostream>
using namespace std;


class Probation{
protected:
    string subjectName;
    int points;

public:
    Probation() : subjectName(""), points(0){};
    Probation(string _subjectName, int _points) : subjectName(_subjectName), points(_points){};
    Probation(const Probation & a) : subjectName(a.subjectName), points(a.points){};
    ~Probation(){};

    friend istream& operator>>(istream& in, Probation& a) {
        in >> a.subjectName;
        in >> a.points;
        return in;
    }

    friend ostream& operator<<(ostream& out, Probation& a) {
        out << "subjectName: " << a.subjectName << ", points" << a.points << a.check();
        return out;
    }

    virtual string check(){}

    virtual void print(){
        cout << "subjectName: " << subjectName << ", points: " << points;
    }

    virtual string toString(){
        return "| " + subjectName + "\t| " + to_string(points) + "\t";
    }

    friend bool operator >(Probation &a, Probation &b){
        return a.points > b.points;
    }

    Probation& operator =(const Probation&a) {
        if (this != &a) {
            subjectName = a.subjectName;
            points = a.points;
        }
        return *this;
    }

    int getPoints() const {
        return points;
    }
};