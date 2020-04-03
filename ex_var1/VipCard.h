//
// Created by Sophia Shuvar on 31.03.20.
//

#ifndef EX_VAR1_VIPCARD_H
#define EX_VAR1_VIPCARD_H

#endif //EX_VAR1_VIPCARD_H
#include <iostream>
#include "GoldCard.h"

using namespace std;

class VipCard : public GoldCard{
    static double percentage;
public:
    VipCard(): GoldCard(){}
    VipCard(string _surname, long long _number, double _sum, double _sum2): GoldCard( _surname, _number, _sum, _sum2){}
    VipCard(const VipCard &a): GoldCard(a){}

    friend istream& operator>>(istream& in, VipCard& a) {
        in >> (GoldCard&)a;
        return in;
    }

    void print() override{
        GoldCard :: print();
        cout << "; percentage: " << percentage;
    }

    bool is_bigger(VipCard a){
        return (sum + sum2)*percentage < (a.sum + a.sum2)*a.percentage;
    }

    friend bool operator ==(VipCard& a, VipCard& b){
        return (a.sum + a.sum2)*a.percentage == (b.sum + b.sum2)*b.percentage;
    }

    virtual double sum_of_two() override{
        return sum + sum2 - ((sum + sum2)*percentage/100);
    }
};