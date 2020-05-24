//
// Created by Sophia Shuvar on 24.05.20.
//

#ifndef CONTAINERS_TASK8_TARIFF_H
#define CONTAINERS_TASK8_TARIFF_H

#endif //CONTAINERS_TASK8_TARIFF_H
using namespace std;
// де кожному iдентифiкацiйному номеру поставлено у вiдповiднiсть цiну за одиницю товару

class Tariff {
private:
    int num;
    double price;

public:
    Tariff() : num(0), price(0) {}

    Tariff(int _num, double _price): num(_num), price(_price) {}

    friend istream & operator>>(istream & is, Tariff & a) {
        is >> a.num;
        is >> a.price;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Tariff & a) {
        os << "num: " << a.num << ", price: " << a.price;
        return os;
    }

//    friend bool operator <(const Reader & a, const Product & b){
//        return  (a.num < b.num);
//    }

    int getNum() const {
        return num;
    }

    double getPrice() const {
        return price;
    }
};