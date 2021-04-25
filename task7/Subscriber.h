
#ifndef TASK7_SUBSCRIBER_H
#define TASK7_SUBSCRIBER_H

#endif //TASK7_SUBSCRIBER_H

#include <iostream>
#include <vector>

#include "Phone.h"
using namespace std;

class Subscriber{
protected:
    string surname;
    string name;
    string middlename;
    string adress;
    vector<Phone> phone;

public:
    Subscriber(){
        surname = "";
        name = "";
        middlename = "";
        adress = "";
        phone =  vector<Phone>();
    }

    Subscriber(string _surname, string _name, string _middlename, string _adress,  vector<Phone> _phone) {
        surname = _surname;
        name = _name;
        middlename = _middlename;
        adress = _adress;
        phone = _phone;
    }

    Subscriber(const Subscriber& a) {
        surname = a.surname;
        name = a.name;
        middlename = a.middlename;
        adress = a.adress;
        phone = a.phone;
    }

    friend istream& operator >>(istream & in,  Subscriber & b) {
        int am;
        in >> b.surname >> b.name >> b.middlename >> b.adress >> am;
        b.phone = vector<Phone>(am);
        for (int i = 0; i < am; ++i) {
            in >> b.phone[i];
        }
        return in;
    }

    virtual void print(ofstream &myfile) {
        myfile << "\n\t\t\t  Subscriber: " << surname << " " << name << " " << middlename <<  "\n\t\t\t  adress: " << adress << "\n\t\t\t  phone: ";
        for (auto p: phone)
            myfile << p << " ";
        myfile << "\n";
    }

    friend ostream & operator<<(ostream & os, const Subscriber & a) {
        os << "Subscriber: " << a.surname << " " << a.name << " " << a.middlename <<  "\nadress: " << a.adress << "\nphone: ";
        for (auto p: a.phone)
            os << p << " ";
        os << "\n\n";
        return os;
    }


    friend bool operator >(Subscriber a, Subscriber b){
        return a.adress > b.adress;
    }

    friend bool operator <(Subscriber a, Subscriber b){
        return a.adress < b.adress;
    }

    const string &getSurname() const {
        return surname;
    }

    void setSurname(const string &surname) {
        Subscriber::surname = surname;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Subscriber::name = name;
    }

    const string &getMiddlename() const {
        return middlename;
    }

    void setMiddlename(const string &middlename) {
        Subscriber::middlename = middlename;
    }

    const string &getAdress() const {
        return adress;
    }

    void setAdress(const string &adress) {
        Subscriber::adress = adress;
    }

    const vector<Phone> &getPhone() const {
        return phone;
    }

    void setPhone(const vector<Phone> &phone) {
        Subscriber::phone = phone;
    }

};