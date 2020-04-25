//
// Created by Sophia Shuvar on 24.04.20.
//

#ifndef STL_CONTAINERS_HEADER_H
#define STL_CONTAINERS_HEADER_H

#endif //STL_CONTAINERS_HEADER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Computer {
private:
    string firm_name;
    string category;
    string p_type;
    long long  num;
    vector<string> dod_com;

public:
    Computer(){}
    Computer(string _firm_name, string _category, string _p_type, long long _num,  vector<string> _dod_com): firm_name(_firm_name),
    category(_category), p_type(_p_type), num(_num), dod_com(_dod_com){}
    ~Computer(){dod_com.clear();};

    friend istream & operator>>(istream & is, Computer & a) {
        if(!a.dod_com.empty()) (a.dod_com).clear();
        unsigned el = 0;
        is >> a.firm_name >> a.category >> a.p_type >> a.num >> el;
        a.dod_com.resize(el);
        for (size_t i = 0; i < el; i++) is >> a.dod_com[i];
        return is;
    }


    friend ostream & operator<<(ostream & os, const Computer & a) {
        os << "firm_name: " << a.firm_name << ", category: " << a.category
           << ", p_type: " << a.p_type << ", num: " << a.num << ", dod_com: ";

        for (auto& i : a.dod_com) os << i << " ";
        return os;
    }

    const string &getFirm_name() const {
        return firm_name;
    }

    const string &getCategory() const {
        return category;
    }

    const string &getP_type() const {
        return p_type;
    }

    long long int getNum() const {
        return num;
    }

    const vector<string> &getDod_com() const {
        return dod_com;
    }

    friend bool operator <(const Computer &a,  Computer b){
        if (a.firm_name == b.firm_name)
            if(a.category == b.category)
                if(a.p_type == b.p_type)
                    return (a.num < b.num);
                else return a.p_type < b.p_type;
            else return a.category < b.category;
        else return a.firm_name < b.firm_name;
    }
};

