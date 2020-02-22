//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef VIRTUAL_FUNCTIONS_PREPAYMENT_H
#define VIRTUAL_FUNCTIONS_PREPAYMENT_H

#endif //VIRTUAL_FUNCTIONS_PREPAYMENT_H
#pragma once

#include <iostream>
#include "Subscriber.h"

class Prepayment :
        public Subscriber
{
protected:
    bool app;
    int amount;
public:
    Prepayment() :Subscriber(), app(0), amount(0){};
    Prepayment(string _name, string _surname, int _age, bool _app, int _amount) : Subscriber(_name, _surname, _age),app(_app), amount(_amount){};
    Prepayment(Subscriber s, bool _app, int _amount) : Subscriber(s), app(_app), amount(_amount){};
    Prepayment(const Prepayment& a) :Subscriber(a), app(a.app), amount(a.amount){};
    ~Prepayment() {};

    friend istream& operator>>(istream& in, Prepayment& a) {
        in >> (Subscriber&)a;
        in >> a.app;
        in >> a.amount;
        return in;
    }

    friend ostream& operator<<(ostream& out, Prepayment& a) {
        out << (Subscriber&)a << ", app: "<< a.app << ", amount: " << a.amount;
        return out;
    }

    void print() override{
        Subscriber::print();
        cout << ", app: "<< app << ", amount: " << amount << "\n";
    }

    Prepayment& operator =(const Prepayment&a) {
        if (this != &a) {
            name = a.name;
            surname = a.surname;
            age = a.age;
            app = a.app;
            amount = a.amount;
        }
        return *this;
    }
};