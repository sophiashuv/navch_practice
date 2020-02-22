//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef VIRTUAL_FUNCTIONS_SUBSCRIBER_H
#define VIRTUAL_FUNCTIONS_SUBSCRIBER_H

#endif //VIRTUAL_FUNCTIONS_SUBSCRIBER_H
#pragma once

#include <iostream>
using namespace std;


class Subscriber{
protected:
    string name;
    string surname;
    int age;
public:
    Subscriber() : name(""), surname(""), age(0){};
    Subscriber(string _name, string _surname, int _age) : name(_name), surname(_surname), age(_age){};
    Subscriber(const Subscriber & a) : name(a.name), surname(a.surname), age(a.age){};
    ~Subscriber() {};

    friend istream& operator>>(istream& in, Subscriber& a) {
        in >> a.name;
        in >> a.surname;
        in >> a.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, Subscriber& a) {
        out << "name: " << a.name << ", surname: " << a.surname << ", age" << a.age;
        return out;
    }

    virtual void print(){
        cout << "name: " << name << ", surname: " << surname << ", age: " << age;
    }

    Subscriber& operator =(const Subscriber&a) {
        if (this != &a) {
            name = a.name;
            surname = a.surname;
            age = a.age;
        }
        return *this;
    }

    int getAge() const {
        return age;
    }
};