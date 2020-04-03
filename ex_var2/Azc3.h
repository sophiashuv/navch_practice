//
// Created by Sophia Shuvar on 01.04.20.
//

#ifndef EX_VAR2_AZC3_H
#define EX_VAR2_AZC3_H

#endif //EX_VAR2_AZC3_H

#include "Azc2.h"
#include <iostream>

using namespace std;

class Azc3 : public Azc {
    static int percentage;
public:
    Azc3 () : Azc(){};
    Azc3 (string _marka, double _price, double _amount) : Azc(_marka, _price, _amount){};
    Azc3(const Azc3& a) : Azc(a){};

    friend istream& operator>>(istream& in, Azc3& b) {
        in >> (Azc&)b;
        return in;
    }

    void print() override {
        Azc::print();
        cout << " percentage: " << percentage;
    }

    double platiz() override{
        return price * amount - price * amount * percentage/100;
    }

    friend bool operator >(Azc3 a, Azc3 b){
        return a.platiz() > b.platiz();
    }

    friend bool operator ==(Azc3 a, Azc3 b){
        return a.platiz() == b.platiz();
    }
};
