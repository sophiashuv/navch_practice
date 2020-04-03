//
// Created by Sophia Shuvar on 31.03.20.
//

#ifndef EX_VAR1_GOLDCARD_H
#define EX_VAR1_GOLDCARD_H

#endif //EX_VAR1_GOLDCARD_H
#include <iostream>
#include "Card.h"

using namespace std;


class GoldCard : public Card{
protected:
    double sum2;
public:
    GoldCard(): Card(), sum2(0){}
    GoldCard(string _surname, long long _number, double _sum, double _sum2): Card( _surname, _number, _sum), sum2(_sum2){}
    GoldCard(const GoldCard &a): Card(a), sum2(a.sum2){}

    friend istream& operator>>(istream& in, GoldCard& a) {
        in >> (Card&)a;
        in >> a.sum2;
        return in;
    }

    virtual void print() override{
        Card :: print();
        cout << "; sum2: " << sum2;
    }

    bool is_bigger(GoldCard a){
        return sum + sum2 > a.sum + a.sum2;
    }

    friend bool operator ==(GoldCard& a, GoldCard& b){
        return a.sum + a.sum2 == b.sum + b.sum2;
    }

    virtual double sum_of_two()override{
        return sum + sum2;
    }
};