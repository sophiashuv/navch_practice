//
// Created by Sophia Shuvar on 01.04.20.
//

#ifndef EX_VAR2_AZC_H
#define EX_VAR2_AZC_H

#endif //EX_VAR2_AZC_H
#include <iostream>
using namespace std;

class Azc{
protected:
    string marka;
    double price;
    double amount;

public:
    Azc(){
        marka = "";
        price = 0;
        amount = 0;
    }

    Azc(string _marka, double _price, double _amount) {
        marka = _marka;
        price = _price;
        amount = _amount;
    }

    Azc(const Azc& a) {
        marka = a.marka;
        price = a.price;
        amount = a.amount;
    }

    string GetMarka(){
        return marka;
    }

    friend istream& operator >>(istream & in,  Azc & b) {
        in >> b.marka >> b.price >> b.amount;
        return in;
    }

    virtual void print() {
        cout << "marka: " << marka << " price: " << price << " amount: " << amount;
    }

    virtual double platiz(){
        return price * amount;
    }

    friend bool operator >(Azc a, Azc b){
        return a.platiz() > b.platiz();
    }

    friend bool operator ==(Azc a, Azc b){
        return a.platiz() == b.platiz();
    }

};