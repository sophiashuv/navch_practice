//
// Created by Sophia Shuvar on 05.05.20.
//

#ifndef CONTAINERS_TASK3_HEADER_H
#define CONTAINERS_TASK3_HEADER_H

#endif //CONTAINERS_TASK3_HEADER_H
using namespace std;

class Runner {
private:
    string name;
    string surname;
    int num;

public:
    Runner(){}
    Runner(string _name, string _surname, int _num): name(_name), surname(_surname), num(_num){}

    friend istream & operator>>(istream & is, Runner & a) {
        is >> a.name >> a.surname >> a.num ;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Runner & a) {
        os << "name: " << a.name << ", surname: " << a.surname
           << ", num: " << a.num ;
        return os;
    }

    int getNum() const{
        return num;
    }

    friend bool operator <(const Runner & a, const Runner & b){
        if (a.surname == b.surname) return a.name < b.name;
        return a.surname < b.surname;
    }

    friend bool operator ==(const Runner &a, const Runner &b){
        return a.num == b.num;
    }

    Runner operator=(const Runner &r) {
        name = r.name, surname = r.surname, num = r.num;
        return *this;
    }

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }
};


class Result {
private:
    int num;
    float time;
    int e_num;
    float length;

public:
    Result(){}
    Result(int _num, float _time, int _e_num, float _length): num(_num), time(_time), e_num(_e_num), length(_length){}

    friend istream & operator>>(istream & is, Result & a) {
        is >> a.num >> a.time >> a.e_num >>  a.length;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Result & a) {
        os << "num: " << a.num << ", time: " << a.time
           << ", e_num: " << a.e_num << ", length: " << a.length;
        return os;
    }

    string getStage() const{
        return "Stage " + to_string(e_num);
    }

    friend bool operator ==(const Result &a, const Result &b){
        return a.num == b.num && a.e_num == b.e_num;
    }

    Result operator=(const Result &r) {
        num = r.num, time = r.time, e_num = r.e_num, length = r.length;
        return *this;
    }

    int getNum() const {
        return num;
    }

    float getTime() const {
        return time;
    }

    double getSpeed(double &t) const{
        return length/t;
    }

    int getE_num() const {
        return e_num;
    }

};