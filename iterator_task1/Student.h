//
// Created by Sophia Shuvar on 16.04.20.
//

#ifndef ITERATOR_TASK1_STUDENT_H
#define ITERATOR_TASK1_STUDENT_H

#endif //ITERATOR_TASK1_STUDENT_H
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string surname;
    string name;
    string faculty;
    int group;
    double grade;

public:
    Student(): surname(""), name(""), faculty(""), group(0), grade(0){}
    Student(string _surname, string _name, string _faculty, int _group, double _grade): surname(_surname),
    name(_name), faculty(_faculty), group(_group), grade(_grade){}

    const string &getFaculty() const {
        return faculty;
    }

    const double &getGrade() const {
        return grade;
    }

    friend istream & operator>>(istream & is, Student & a) {
        is >> a.surname;
        is >> a.name;
        is >> a.faculty;
        is >> a.group;
        is >> a.grade;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Student & a) {
        os << a.surname << " " << a.name << " " << a.faculty << " " << a.group << " - " << a.grade;
        return os;
    }

    friend bool operator <(const Student &a, const Student &b){
        return a.surname < b.surname;
    }

};