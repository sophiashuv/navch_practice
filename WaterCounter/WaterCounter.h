//
// Created by Sophia Shuvar on 24.04.20.
//

#ifndef WATERCOUNTER_WATERCOUNTER_H
#define WATERCOUNTER_WATERCOUNTER_H

#endif //WATERCOUNTER_WATERCOUNTER_H
#include <iostream>
#include <string>
using namespace std;

class WaterCounter {
private:
    int flat_num;
    int month_num;
    int curr_value;
    int prev_value;

public:
    WaterCounter(): flat_num(0), month_num(0), curr_value(0), prev_value(0){}
    WaterCounter(int _flat_num, int _month_num, int _curr_value, int _prev_value): flat_num(_flat_num),
                                month_num(_month_num), curr_value(_curr_value), prev_value(_prev_value){}

    friend istream & operator>>(istream & is, WaterCounter & a) {
        is >> a.flat_num;
        is >> a.month_num;
        is >> a.curr_value;
        is >> a.prev_value;
        return is;
    }

    friend ostream & operator<<(ostream & os, const WaterCounter & a) {
        os << "flat_num: " << a.flat_num << ", month_num: " << a.month_num
        << ", curr_value: " << a.curr_value << ", prev_value: " << a.prev_value;
        return os;
    }

    friend double operator +(double d, const WaterCounter &a) {
        return  d + a.curr_value + a.prev_value;
    }

    friend bool operator <(const WaterCounter &a,  WaterCounter b){
        return a.curr_value + a.prev_value < b.curr_value + b.prev_value;
    }

    friend bool operator ==(const WaterCounter &a, const WaterCounter &b){
        return a.curr_value + a.prev_value == b.curr_value + b.prev_value;
    }
};