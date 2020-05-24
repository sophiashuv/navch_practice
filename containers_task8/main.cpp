#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include "Product.h"
#include "Tariff.h"
#include "Solled.h"

//    Завдання 1.
//    Розробити типи для облiку продаж товарiв у супермаркетi. Асортимент подано перелiком товарiв,
//    якi характеризуються iдентифiкацiйним номером, назвою, категорiєю та належнiстю до
//    акцiйної групи (так/нi). Цiни товарiв визначаються тарифiкацiйним перелiком,
//    де кожному iдентифiкацiйному номеру поставлено у вiдповiднiсть цiну за одиницю товару.
//    Прирозрахунках реальна цiна акцiйного товару становить половину тарифної.
//    Данi продаж характеризуються iдентифiкацiйним номером проданого товару та кiлькiстю одиниць.
//    Асортимент та тарифи подано окремими файлами.Продажi також подано кiлькома окремими файлами.
//    Отримати:
//        1. у кожнiй категорiї ПРОДАНИХ товарiв для кожної назви виручену суму у форматi < назва товару - сума >;
//        2. для кожної категорiї ПРОДАНИХ товарiв виручену суму у форматi< категорiя - сума >;
//        3. у кожнiй категорiї ПРОДАНИХ товарiв назви товарiв з найбiльшою вирученою сумою у форматi
//                < назва товару - сума >;
//        4. загальну суму ПРОДАНИХ товарiв.

template <typename T, typename K>
void read_file(const string &file_name, T &r){
    ifstream fin(file_name);
    if (fin)copy(istream_iterator<K>(fin), istream_iterator<K>(), back_inserter(r));
    else throw "File not open exception\n";
}

template <typename T, typename K>
void write(const T &r, ostream &os){
    ostream_iterator<K> ositer(os, "\n");
    copy(r.begin(), r.end(), ositer);
}

void write_map_map(map<string, map<string, double>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.first << " => "; for_each(el.second.begin(), el.second.end(),
                                                                                         [&](const auto &e){os << e.first <<  " : " << e.second << "\n\t\t\t  ";});  os << "\n";});
}

void write_multimap_d(multimap<double, string, greater<>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.second << " => " << el.first << "\n";});
}


void task1(map<string, map<string, double>> &m,  vector<Product> products, vector<Tariff> tariffs, vector<Sold> sell){
    for(auto &s: sell) {
        for(auto &t: tariffs) {
            for(auto &p: products) {
                if(s.getNum() == p.getNum() && s.getNum() == t.getNum())
                    m[p.getCategory()][p.getName()] +=  p.isStock()?(s.getAmount()*(t.getPrice() * 0.5)):(s.getAmount()*t.getPrice());
            }
        }
    }
}


void task2(multimap<double, string, greater<>> &m, const map<string, map<string, double>> &m0){
    for (auto &el: m0) {
        m.insert(make_pair(accumulate(begin(el.second), end(el.second), 0,
                                      [](int v, const pair<string, int> &p) {return v + p.second;}), el.first));
    }
}

void task3(const map<string, map<string, double>> &m0){
    for (auto &el: m0) {
        cout << el.first << " => ";
        for (auto &el2 : el.second) if (el2.second == el.second.begin()->second) cout << el2.first << " : " << el2.second <<  "\n\t\t\t  ";
        cout << "\n";
    }
}

void task4(multimap<double, string, greater<>> &m){
       cout << "Sum of all products: " << accumulate(begin(m), end(m), 0, [](int v, const pair<double, string> &p) {return v + p.first;});

}


int main() {
    vector<Product> products;
    vector<Tariff> tariffs;
    vector<Sold> sell;
    read_file<vector<Product>, Product>("/Users/sophiyca/ClionProjects/containers_task8/products.txt", products);
    read_file<vector<Tariff>, Tariff>("/Users/sophiyca/ClionProjects/containers_task8/tariffs.txt", tariffs);
    read_file<vector<Sold>, Sold>("/Users/sophiyca/ClionProjects/containers_task8/sell1.txt", sell);
    read_file<vector<Sold>, Sold>("/Users/sophiyca/ClionProjects/containers_task8/sell2.txt", sell);
    write<vector<Product>, Product>(products, cout);
    cout << "\n---------------\n";
    write<vector<Tariff>, Tariff>(tariffs, cout);
    cout << "\n---------------\n";
    write<vector<Sold>, Sold>(sell, cout);

    cout << "\n---------------TASK1---------------\n\n";
    map<string, map<string, double>> map1;
    task1(map1, products, tariffs, sell);
    write_map_map(map1, cout);

    cout << "\n---------------TASK2---------------\n\n";
    multimap<double, string, greater<>> map2;
    task2(map2, map1);
    write_multimap_d(map2, cout);

    cout << "\n---------------TASK3---------------\n\n";
    task3(map1);

    cout << "\n---------------TASK4---------------\n\n";
    task4(map2);
    return 0;
}