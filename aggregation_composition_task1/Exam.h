//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef AGGREGATION_COMPOSITION_TASK1_EXAM_H
#define AGGREGATION_COMPOSITION_TASK1_EXAM_H

#endif //AGGREGATION_COMPOSITION_TASK1_EXAM_H

#pragma once
#include <iostream>
#include "Probation.h"
using namespace std;

class Exam:
        public Probation{

private:
    string l_surname;
    string a_surname;

public:
    Exam() : Probation(), l_surname(""), a_surname(""){};
    Exam(string _subjectName, int _points, string l, string a) : Probation(_subjectName, _points), l_surname(l), a_surname(a){};
    Exam(Probation s, string l, string a) : Probation(s), l_surname(l), a_surname(a){};
    Exam(const Exam & a) : Probation(a), l_surname(a.l_surname), a_surname(a.a_surname){};
    ~Exam() {};

    friend istream& operator>>(istream& in, Exam& a) {
        in >> (Probation&)a;
        in >> a.l_surname;
        in >> a.a_surname;
        return in;
    }

    friend ostream& operator<<(ostream& out, Exam& a) {
        out << (Probation&)a  << ", l_surname: " << a.l_surname << ", a_surname: " << a.a_surname << a.check();
        return out;
    }

    string check(){
        if (points >= 90) return "Perfect";
        else if (points >= 71 && points <= 89) return "Good";
        else if (points >= 51 && points <= 70) return "Satisfactory";
        else return "Not Passed";
    }

    string toString(){
        return Probation::toString() + "\t| " + l_surname + "\t\t| " + a_surname + "\t\t| " + check();
    }

    friend bool operator >(Exam &a, Exam &b){
        return a.points > b.points;
    }

    Exam& operator =(const Exam&a) {
        if (this != &a) {
            subjectName = a.subjectName;
            l_surname = a.l_surname;
            a_surname = a.a_surname;
            points = a.points;
        }
        return *this;
    }
};