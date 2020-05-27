//
// Created by Sophia Shuvar on 27.05.20.
//

#ifndef EX_PR1_HEADER_H
#define EX_PR1_HEADER_H

#endif //EX_PR1_HEADER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//   Данi реєстрацiї мiстять назву туру i перелiк його екскурсiй, на якi здiйснено реєстрацiю, а також назвутурфiрми.
class Tour {
protected:
    string name;
    string firm;
    vector<string> ecscursions;


public:
    Tour(){}

    ~Tour(){ecscursions.clear();};

    friend istream & operator>>(istream & is, Tour & a) {
        //if(!a.actors.empty()) (a.actors).clear();
        unsigned el = 0; string actor;
        is >> a.name >> a.firm >>  el;
        a.ecscursions.resize(el);
        for (size_t i = 0; i < el; i++) is >> a.ecscursions[i];
        return is;
    }


    friend ostream & operator<<(ostream & os, const Tour & a) {
        os << "name: " << a.name << ", firm: " << a.firm << ", ecscursions: ";

        for (auto& i : a.ecscursions) os << i << " ";
        return os;
    }

    virtual void print(){
        cout << "name: " << name << ", firm: " << firm << ", ecscursions: ";
        for (auto& i : ecscursions) cout << i << " ";
    }

    const string &getName() const {
        return name;
    }

    const string &getFirm() const {
        return firm;
    }

    const vector<string> &getEcscursions() const {
        return ecscursions;
    }

    void setFirm(const string &firm) {
        Tour::firm = firm;
    }

};


class Tour2 : public Tour{
protected:
    string transport;


public:
    Tour2(){}

    friend istream & operator>>(istream & is, Tour2 & a) {
        is >> (Tour&)a;
        is >> a.transport;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Tour2 & a) {
        os << (Tour&)a;
        os << ", transport: " << a.transport;
        return os;
    };

    virtual void print() override{
        Tour:: print();
        cout << ", transport: " << transport;
    }

     const string &getTransport() const{
        return transport;
    }

};