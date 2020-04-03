//
// Created by Sophia Shuvar on 01.04.20.
//

#ifndef EX_VAR2_AZC2_H
#define EX_VAR2_AZC2_H

#endif //EX_VAR2_AZC2_H

#include "Azc.h"
#include <iostream>
using namespace std;

class Azc2 : public Azc{
    static int percentage;
    int num;

public:
    Azc2 () : Azc(), num(0){};
    Azc2 (string _marka, double _price, double _amount, int _num) : Azc(_marka, _price, _amount), num(_num){};
    Azc2(const Azc2& a) : Azc(a), num(a.num){};

    friend istream& operator>>(istream& in, Azc2& b) {
        in >> (Azc&)b;
        in >> b.num;
        return in;
    }

    void print() override{
        Azc::print();
        cout << " num: "<< num << " percentage: " << percentage;
    }

    double platiz() override{
        return price * amount - price * amount * percentage/100;
    }

    friend bool operator >(Azc2 a, Azc2 b){
        return a.platiz() > b.platiz();
    }

    friend bool operator ==(Azc2 a, Azc2 b){
        return a.platiz() == b.platiz();
    }
};