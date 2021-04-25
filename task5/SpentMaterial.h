
#ifndef TASK5_SPENTMATERIAL_H
#define TASK5_SPENTMATERIAL_H

#endif //TASK5_SPENTMATERIAL_H
#include <iostream>
#include <vector>

#include "Date.h"

using namespace std;

class SpentMaterial{
private:
    Date date;
    string title;
    double volume;
    double price;

public:
    SpentMaterial(){
        date = Date();
        title = "";
        volume = 0;
        price = 0;
    }

    SpentMaterial(Date _date, string _title, double _volume, double _price) {
        date = _date;
        title = _title;
        volume = _volume;
        price = _price;
    }

    SpentMaterial(const SpentMaterial& a) {
        date = a.date;
        title = a.title;
        volume = a.volume;
        price = a.price;
    }

    friend istream& operator >>(istream & in,  SpentMaterial & b) {
        in >> b.date >> b.title >> b.volume >> b.price;
        return in;
    }

    friend ostream & operator<<(ostream & os, const SpentMaterial & a) {
        os << "\tdate: " << a.date << " title: " << a.title << " volume: " << a.volume <<  " price: " << a.price << "\n";
        return os;
    }

    SpentMaterial& operator +=(const SpentMaterial& b){
        volume += b.volume;
        price += b.price;
        date = max(date, b.date);
        return *this;
    }

    friend bool operator ==(SpentMaterial a, SpentMaterial b){
        return a.title == b.title;
    }

    const Date &getDate() const {
        return date;
    }

    void setDate(const Date &date) {
        SpentMaterial::date = date;
    }

    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        SpentMaterial::title = title;
    }

    double getVolume() const {
        return volume;
    }

    void setVolume(double volume) {
        SpentMaterial::volume = volume;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        SpentMaterial::price = price;
    }

};
