//
// Created by Sophia Shuvar on 31.03.20.
//

#ifndef EX_VAR1_CARD_H
#define EX_VAR1_CARD_H

#endif //EX_VAR1_CARD_H
#include <iostream>

using namespace std;

class Card{
protected:
    string surname;
    long long number;
    double sum;

public:
    Card(): surname(""), number(0000000000), sum(0){}
    Card(string _surname, long long _number, double _sum): surname(_surname), number(_number), sum(_sum){}
    Card(const Card &a): surname(a.surname), number(a.number), sum(a.sum){}

    long long GetNumber(){
        return number;
    }

    friend istream &operator >> (istream &is, Card& a){
        is >> a.surname >> a.number >> a.sum;
        return is;
    }

    virtual void print() {
        cout << "surname: " << surname << "; number: " << number << "; sum: " << sum;
    }

    bool is_bigger(Card a){
        return sum > a.sum;
    }

    friend bool operator ==(Card& a, Card& b){
        return a.sum == b.sum;
    }

    virtual double sum_of_two(){
        return sum;
    }
};
