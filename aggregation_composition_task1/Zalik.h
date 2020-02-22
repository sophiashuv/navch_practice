//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef AGGREGATION_COMPOSITION_TASK1_ZALIK_H
#define AGGREGATION_COMPOSITION_TASK1_ZALIK_H

#endif //AGGREGATION_COMPOSITION_TASK1_ZALIK_H

#pragma once
#include "Probation.h"
#include <iostream>
using namespace std;

class Zalik:
        public Probation{
private:
    string surname;

public:
    Zalik() :Probation(), surname(""){};
    Zalik(string _subjectName, int _points, string _surname) :Probation(_subjectName, _points), surname(_surname){};
    Zalik(Probation s, string _surname) : Probation(s), surname(_surname){};
    Zalik(const Zalik & a) : Probation(a), surname(a.surname){};
    ~Zalik() {};

    friend istream& operator>>(istream& in, Zalik& a) {
        in >> (Probation&)a;
        in >> a.surname;
        return in;
    }

    friend ostream& operator<<(ostream& out, Zalik& a) {
        out << (Probation&)a << ", surname: " << a.surname << a.check();
        return out;
    }

    string check(){
        if (points > 50) return "Passed";
        else return "Not Passed";
    }

    string toString(){
        return Probation::toString() + "\t| " + surname + "\t\t| ___________\t\t| " + check();
    }

    friend bool operator >(Zalik &a, Zalik &b){
        return a.points > b.points;
    }

    Zalik& operator =(const Zalik&a) {
        if (this != &a) {
            subjectName = a.subjectName;
            surname = a.surname;
            points = a.points;
        }
        return *this;
    }
};