//
// Created by Sophia Shuvar on 06.05.20.
//

#ifndef CONTAINERS_TASK4_HEADER_H
#define CONTAINERS_TASK4_HEADER_H

#endif //CONTAINERS_TASK4_HEADER_H
using namespace std;

class Patient {
private:
    string name;
    string surname;
    int num;

public:
    Patient(){}
    Patient(string _name, string _surname, int _num): name(_name), surname(_surname), num(_num){}

    friend istream & operator>>(istream & is, Patient & a) {
        is >> a.name >> a.surname >> a.num ;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Patient & a) {
        os << "name: " << a.name << ", surname: " << a.surname
           << ", num: " << a.num ;
        return os;
    }

    int getNum() const{
        return num;
    }

    friend bool operator <(const Patient & a, const Patient & b){
        if (a.surname == b.surname) return a.name < b.name;
        return a.surname < b.surname;
    }

    friend bool operator ==(const Patient &a, const Patient &b){
        return a.num == b.num;
    }

    Patient operator=(const Patient &r) {
        name = r.name, surname = r.surname, num = r.num;
        return *this;
    }

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }

    const string &getFullSurname() const {
        string r = name + " " + surname;
        return r;
    }

};

class Appointment {
private:
    int num;
    string date;
    string m_name;
    float doza;
    int amount;

public:
    Appointment(){}
    Appointment(int _num, string _date, string _m_name, float _doza, int _amount): num(_num), date(_date), m_name(_m_name), doza(_doza),amount(_amount) {}

    friend istream & operator>>(istream & is, Appointment & a) {
        is >> a.num >> a.date >> a.m_name >>  a.doza >> a.amount;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Appointment & a) {
        os << "num: " << a.num << ", date: " << a.date
           << ", m_name: " << a.m_name << ", doza: " << a.doza << ", amount: " << a.amount;
        return os;
    }

    friend bool operator ==(const Appointment &a, const Appointment &b){
        return a.num == b.num;
    }

    Appointment operator=(const Appointment &r) {
        num = r.num, date = r.date, m_name = r.m_name, doza = r.doza, amount = r.amount;
        return *this;
    }

    int getNum() const {
        return num;
    }

    const string &getDate() const {
        return date;
    }

    const string &getM_name() const {
        return m_name;
    }

    float getDoza() const {
        return doza;
    }

    int getAmount() const {
        return amount;
    }
};