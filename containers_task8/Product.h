//
// Created by Sophia Shuvar on 24.05.20.
//

#ifndef CONTAINERS_TASK8_PRODUCT_H
#define CONTAINERS_TASK8_PRODUCT_H

#endif //CONTAINERS_TASK8_PRODUCT_H
using namespace std;
// характеризуються iдентифiкацiйним номером, назвою, категорiєю та належнiстю до акцiйної групи (так/нi)

class Product {
private:
    int num;
    string name;
    string category;
    bool stock;

public:
    Product() : num(0), name(""), category(""), stock(0) {}

    Product(int _num, string _name, string _category, bool _stock): num(_num), name(_name), category(_category), stock(_stock){}

    friend istream & operator>>(istream & is, Product & a) {
        is >> a.num;
        is >> a.name;
        is >> a.category;
        is >> a.stock;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Product & a) {
        os << "num: " << a.num << "name: " << a.name << ", category: " << a.category
           << ", stock: " << a.stock;
        return os;
    }

//    friend bool operator <(const Reader & a, const Product & b){
//        return  (a.num < b.num);
//    }

    int getNum() const {
        return num;
    }

    const string &getName() const {
        return name;
    }

    const string &getCategory() const {
        return category;
    }

    bool isStock() const {
        return stock;
    }
};