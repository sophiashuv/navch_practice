#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <map>
#include <algorithm>
using namespace std;

//    Завдання 2.
//    Розробити типи для обслуговування замовлень в iнтернетмаґазинi.
//    Замовник характеризується iменем, прiзвищем, мiсцем проживання та реєстрацiйним номером.
//    Товар характеризується облiковим номером, назвоютовару i цiною за одиницю.
//    Замовлення характеризується реєстрацiйнимномером замовника, облiковим номером товару i кiлькiстю одиниць.
//    Iнфор-мацiя про замовникiв та товари подана окремими файлами. Замовленнятакож подано кiлькома окремими файлами.
//    Отримати:
//        1. для кожного замовника ( за iменем i прiзвищем) повний перелiк (безповторень) товарiв iз
//            вказанням кiлькостi кожного товару у форматi< товар - кiлькiсть замовлених одиниць >;
//        2. рейтинг замовникiв за загальною сумою у форматi< прiзвище, iм’я - загальна сума за всi замовлення>;
//        3. для кожного товару його кiлькiсть у форматi<назва товару - кiлькiсть замовлених одиниць>;
//        4. для кожного мiсця проживання загальну суму замовлень.

class Сustomer {
protected:
    string name;
    string surname;
    string location;
    int c_num;

public:
    Сustomer(){}

    friend istream & operator>>(istream & is, Сustomer & a) {
        is >> a.name >> a.surname >> a.location >> a.c_num;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Сustomer & a) {
        os << "name: " << a.name << ", surname: " << a.surname << ", location: " << a.location << ", c_num: " << a.c_num  ;
        return os;
    }

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }

    const string &getLocation() const {
        return location;
    }

    int getNum() const {
        return c_num;
    }
};

//Товар характеризується облiковим номером, назвоютовару i цiною за одиницю.
class Product {
protected:
    int p_num;
    string name;
    double price;

public:
    Product(){}

    friend istream & operator>>(istream & is, Product & a) {
        is >> a.p_num >> a.name >> a.price;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Product & a) {
        os << "p_num: " << a.p_num << ", name: " << a.name << ", price: " << a.price;
        return os;
    }

    int getNum() const {
        return p_num;
    }

    const string &getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    friend bool operator <(const Product & a, const Product & b){
        return  (a.p_num < b.p_num);
    }
};

//Замовлення характеризується реєстрацiйнимномером замовника, облiковим номером товару i кiлькiстю одиниць.
class Order {
protected:
    int c_num;
    int t_num;
    int amount;

public:
    Order(){}

    friend istream & operator>>(istream & is, Order & a) {
        is >> a.c_num >> a.t_num >> a.amount;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Order & a) {
        os << "c_num: " << a.c_num << ", t_num: " << a.t_num << ", amount: " << a.amount;
        return os;
    }

    int getC_num() const {
        return c_num;
    }

    int getT_num() const {
        return t_num;
    }

    int getAmount() const {
        return amount;
    }
};

/*
 * Function reads from file
 */
template <typename T, typename K>
void read_file(const string &file_name, T &r){
    ifstream fin(file_name);
    if (fin) copy(istream_iterator<K>(fin), istream_iterator<K>(), back_inserter(r));
    else throw "File not open exception\n";
}


/*
 * Functions to read needed containers
 */
template<typename T, typename K>
void write_list(const T &r, ostream &os, const char* pend = "\n"){
    ostream_iterator<K> ositer(os, pend);
    copy(r.begin(), r.end(), ositer);
}

void write_map_st_map_int(const map<string, map <Product,int>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.first << " => ";
        for_each(el.second.begin(), el.second.end(), [&](const auto &e){os << e.first <<  " -- "  << e.second << "\n\t\t  ";});
        os << "\n";});
}

template <typename T>
void write_map_st_int(const map<string, T> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.first << " => " << el.second << "\n";});
}

/*
 * Functions for tasks representations
 */
void task1(const vector<Сustomer> &customers, const vector<Product> &products, const vector<Order> &orders){
    map<string, map <Product,int>> m;
    for (auto &o: orders) {
        for (auto &p: products) {
            for (auto &c: customers) {
                if(o.getC_num() == c.getNum() && o.getT_num() == p.getNum())
                    m[c.getName() + " " + c.getSurname()][p] += o.getAmount();
            }
        }

    }
    write_map_st_map_int(m, cout);
}


void task2(const vector<Сustomer> &customers, const vector<Product> &products, const vector<Order> &orders){
    map<string, double> m;
    for (auto &o: orders) {
        for (auto &p: products) {
            for (auto &c: customers) {
                if(o.getC_num() == c.getNum() && o.getT_num() == p.getNum())
                    m[c.getName() + " " + c.getSurname()] += o.getAmount()*p.getPrice();
            }
        }

    }
    write_map_st_int(m, cout);
}

void task3(const vector<Product> &products, const vector<Order> &orders){
    map<string, int> m;
    for (auto &o: orders) {
        for (auto &p: products) {
            if(o.getT_num() == p.getNum())m[p.getName()] += o.getAmount();
        }
    }
    write_map_st_int(m, cout);
}


void task4(const vector<Сustomer> &customers, const vector<Order> &orders){
    map<string, int> m;
    for (auto &c: customers) {
        for (auto &o: orders) {
            if(o.getT_num() == c.getNum())m[c.getLocation()] += o.getAmount();
        }
    }
    write_map_st_int(m, cout);
}


using namespace std;
int main() {
    vector<Сustomer> customers;
    vector<Product> products;
    vector<Order> orders;
    read_file<vector<Сustomer>, Сustomer>("/Users/sophiyca/ClionProjects/ex_pr2/customers.txt", customers);
    read_file<vector<Product>, Product>("/Users/sophiyca/ClionProjects/ex_pr2/products.txt", products);
    read_file<vector<Order>, Order>("/Users/sophiyca/ClionProjects/ex_pr2/orders.txt", orders);
    read_file<vector<Order>, Order>("/Users/sophiyca/ClionProjects/ex_pr2/orders2.txt", orders);
    write_list<vector<Сustomer>, Сustomer>(customers, cout);
    cout << "\n ------------------\n";
    write_list<vector<Product>, Product>(products, cout);
    cout << "\n ------------------\n";
    write_list<vector<Order>, Order>(orders, cout);
    cout << "\n ------------------\n";

    // Tasks
    task1(customers, products, orders);
    cout << "\n ------------------\n";
    task2(customers, products, orders);
    cout << "\n ------------------\n";
    task3(products, orders);
    cout << "\n ------------------\n";
    task4(customers, orders);
    return 0;
}