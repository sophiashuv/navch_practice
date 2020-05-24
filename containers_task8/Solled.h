//
// Created by Sophia Shuvar on 24.05.20.
//

#ifndef CONTAINERS_TASK8_SOLLED_H
#define CONTAINERS_TASK8_SOLLED_H

#endif //CONTAINERS_TASK8_SOLLED_H
using namespace std;
// Данi продаж характеризуються iдентифiкацiйним номером проданого товару та кiлькiстю одиниць.

class Sold {
private:
    int num;
    int amount;

public:
    Sold() : num(0), amount(0) {}

    Sold(int _num, int _amount): num(_num), amount(_amount){}

    friend istream & operator>>(istream & is, Sold & a) {
        is >> a.num;
        is >> a.amount;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Sold & a) {
        os << "num: " << a.num << ", amount: " << a.amount;
        return os;
    }

//    friend bool operator <(const Reader & a, const Product & b){
//        return  (a.num < b.num);
//    }

    int getNum() const {
        return num;
    }

    int getAmount() const {
        return amount;
    }

};