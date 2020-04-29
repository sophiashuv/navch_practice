//
// Created by Sophia Shuvar on 29.04.20.
//

#ifndef CONTAINERS_TASK2_HEADER_H
#define CONTAINERS_TASK2_HEADER_H

#endif //CONTAINERS_TASK2_HEADER_H
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Sportsman {
private:
    string name;
    string surname;
    int num;

public:
    Sportsman(){}
    Sportsman(string _name, string _surname, int _num): name(_name), surname(_surname), num(_num){}

    friend istream & operator>>(istream & is, Sportsman & a) {
        is >> a.name >> a.surname >> a.num ;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Sportsman & a) {
        os << "name: " << a.name << ", surname: " << a.surname
           << ", num: " << a.num ;
        return os;
    }

    int getNum() const{
        return num;
    }

    friend bool operator <(const Sportsman & a, const Sportsman & b){
        if (a.surname == b.surname) return a.name == b.name;
        return a.surname < b.surname;
    }

};

struct classcomp {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.first - lhs.second > rhs.first - rhs.second;
    }
};


class Sport {

private:
    pair<string, multimap<pair<int, int>, Sportsman, classcomp>> m;
    vector<Sportsman> sportsmen;


public:
    Sport(vector<Sportsman> _sportsmen): sportsmen(_sportsmen){}

    friend istream & operator>>(istream & is, Sport & a) {
        string sport;
        Sportsman s;
        multimap<pair<int, int>, Sportsman, classcomp> k;
        int am = 0, num = 0, p1 = 0, shtraf = 0;
        is >> sport >> am;
        for (int i = 0; i < am; i++) {
            is >> num >> p1 >> shtraf;
            auto it = find_if(a.sportsmen.begin(), a.sportsmen.end(), [&](const auto &e){return e.getNum() == num;});
            if(it != a.sportsmen.end()) {
                k.insert(make_pair(make_pair(p1,shtraf), *it));
                a.m.first = sport;
                a.m.second = k;

            }
        }
        return is;
    }

    friend ostream & operator<<(ostream & os, const Sport & a) {
        os << a.m.first << " => ";
        auto it = a.m.second.begin();
        (a.m.second.size() > 3) ? advance(it, 3) : advance(it, a.m.second.size());
        for_each(a.m.second.begin(), it, [&](const auto &el){
            os << el.first.first - el.first.second <<  " : " << el.second << "\n\t\t  ";});
        os << "\n";
        return os;
    }

    pair<int, int> getPoints(const int &sportman_num) const{
        auto it = find_if(m.second.begin(), m.second.end(), [&](const auto &el){return el.second.getNum() == sportman_num;});
        return it == m.second.end() ? pair<int, int>() : it->first;
    }

    string getSport() const{
        return m.first;
    }

    int gerRealPoints(const int &sportman_num) const{
        return getPoints(sportman_num).first - getPoints(sportman_num).second;
    }

/*
 * TODO: a method to erase shtrafnic by his num from Sport class
 */

//    void erase_sportsman(const int &sportsman_num){
//        remove_if(m.second.begin(), m.second.end(), FindAttribute2(sportsman_num));

//        ----------------------
//        for (auto el = m.second.begin(); el != m.second.end(); ) {
//            if (el->second.getNum() == sportsman_num) {
//                el = m.second.erase(el);
//                break;
//            }
//            else el++;
//        }
//    }
};
