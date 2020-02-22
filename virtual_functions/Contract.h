//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef VIRTUAL_FUNCTIONS_CONTRACT_H
#define VIRTUAL_FUNCTIONS_CONTRACT_H

#endif //VIRTUAL_FUNCTIONS_CONTRACT_H
#pragma once

#include <iostream>
#include "Subscriber.h"

class Contract :
        public Subscriber
{
protected:
    bool app;
    int years;
public:
    Contract() :Subscriber(), app(0), years(0){};
    Contract(string _name, string _surname, int _age, bool _app, int _years) :Subscriber(_name, _surname, _age),app(_app), years(_years){};
    Contract(Subscriber s, bool _app, int _years) : Subscriber(s), app(_app), years(_years){};
    Contract(const Contract& a) :Subscriber(a), app(a.app), years(a.years){};
    ~Contract() {};

    friend istream& operator>>(istream& in, Contract& a) {
        in >> (Subscriber&)a;
        in >> a.app;
        in >> a.years;
        return in;
    }

    friend ostream& operator<<(ostream& out, Contract& a) {
        out << (Subscriber&)a << ", app: "<< a.app << ", years: " << a.years;
        return out;
    }

    virtual void print() override{
        Subscriber::print();
        cout << ", app: "<< app << ", years: " << years << "\n";
    }

    Contract& operator =(const Contract&a) {
        if (this != &a) {
            name = a.name;
            surname = a.surname;
            age = a.age;
            app = a.app;
            years = a.years;
        }
        return *this;
    }
};