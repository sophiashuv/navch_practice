//
// Created by Sophia Shuvar on 24.03.20.
//

#ifndef FINAL_TEMPLETE_CONNECTED_H
#define FINAL_TEMPLETE_CONNECTED_H

#endif //FINAL_TEMPLETE_CONNECTED_H
#pragma once
#include "Line.h"
#include "WrongConnectionException.h"

template<typename T>
class Connected {
private:
    Line first;
    Line second;
    Line third;

public:
    Connected() :first(), second(), third(){};
    Connected(Line _first, Line _second, Line _third) {setLines(_first, _second, _third);}
    Connected(const Connected& a) {setLines(a.first, a.second, a.third);}
    ~Connected() {};

    void setLines(Line _first, Line _second, Line _third){
        if(!T::check(_first, _second, _third)) throw WrongConnectionException("Angle is not 90!\n");
        else {
            this->first = _first;
            this->second = _second;
            this->third = _third;
        }
    }

    friend ostream & operator<<(ostream & os, Connected & a) {
        os << "l1: "<< a.first << "l2: " << a.second << "l3: " << a.third << "\n";
        return os;
    }
};