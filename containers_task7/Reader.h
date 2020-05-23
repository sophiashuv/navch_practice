//
// Created by Sophia Shuvar on 23.05.20.
//

#ifndef CONTAINERS_TASK7_READER_H
#define CONTAINERS_TASK7_READER_H

#endif //CONTAINERS_TASK7_READER_H
using namespace std;
// Читач характеризується iменем, прiзвищем та реєстрацiйним номером

class Reader {
private:
    string name;
    string surname;
    int num;
public:
    Reader() : name(""), surname(""), num(0) {}

    Reader(string _name, string _surname, int _num, int _year, double _price): name(_name), surname(_surname), num(_num){}

    friend istream & operator>>(istream & is, Reader & a) {
        is >> a.name;
        is >> a.surname;
        is >> a.num;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Reader & a) {
        os << "name: " << a.name << ", surname: " << a.surname
           << ", num: " << a.num;
        return os;
    }

    friend bool operator <(const Reader & a, const Reader & b){
        return  (a.num < b.num);
    }

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }

    int getNum() const {
        return num;
    }
};