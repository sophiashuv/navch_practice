
#ifndef TASK7_PHONE_H
#define TASK7_PHONE_H

#endif //TASK7_PHONE_H

#include <iostream>
using namespace std;

class Phone{
private:
    string num;

public:
    Phone(){
        num = "";
    }

    Phone(string _num) {
        this->setNum(_num);
    }

    Phone(const Phone& a) {
        num = a.num;
    }

    static bool validate_phone(const string &phone){
        char dash = '-';

        if (phone.length() != 12)
           return true;

        return phone[3] != dash || phone[7] != dash;
    }

    void setNum(const string &phone) {
        if (!this->validate_phone(phone)){
            num = phone;
        }
        else throw "Invalid phone num!";
    }

    const string &getNum() const {
        return num;
    }

    friend istream& operator >>(istream & in,  Phone & b) {
        string n;
        in >> n;
        b.setNum(n);
        return in;
    }

    friend ostream & operator<<(ostream & os, const Phone & a) {
        os << a.num;
        return os;
    }

};