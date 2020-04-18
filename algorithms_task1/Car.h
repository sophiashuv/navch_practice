//
// Created by Sophia Shuvar on 17.04.20.
//

#ifndef ALGORITHMS_TASK1_CAR_H
#define ALGORITHMS_TASK1_CAR_H

#endif //ALGORITHMS_TASK1_CAR_H
#pragma once

#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    int year;
    string colour;
    double price;

public:
    Car(): brand(""), year(0), colour(""), price(0){}
    Car(string _brand, int _year, string _colour, double _price): brand(_brand), year(_year), colour(_colour), price(_price){}

    friend istream & operator>>(istream & is, Car & a) {
        is >> a.brand;
        is >> a.year;
        is >> a.colour;
        is >> a.price;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Car & a) {
        os << a.brand << " " << a.year << " " << a.colour << " " << a.price;
        return os;
    }

    int getYear() const {
        return year;
    }

    const string &getBrand() const {
        return brand;
    }

    double getPrice() const {
        return price;
    }

    friend bool operator <(const Car &a,  Car b){
        return a.year < b.year;
    }

    friend double operator +(double d, const Car &a) {
        return  d + a.price;
    }
};