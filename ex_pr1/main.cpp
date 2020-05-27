#include <iostream>
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <algorithm>


#include "Header.h"

//    Завдання 1.Розробити типи для туристичних турiв.
//    Данi реєстрацiї мiстять назву туру i перелiк його екскурсiй,
//    на якi здiйснено реєстрацiю, а також назвутурфiрми.
//    Також є окрема категорiя турiв, де можна вибирати вид транс-порту.
//    Данi про реєстрацiю на екскурсiї в турах задано у двох файлах,вiдповiдно до категорiї туру.
//        1. Для кожної турфiрми вивести перелiки турiв iз перелiком зареєстро-ваних екскурсiй.
//           Усi перелiки виводити в лексикографiчному порядку.
//        2. Отримати рейтинг усiх екскурсiй вiдносно кiлькостi реєстрацiй.
//        3. Для кожної турфiрми знайти кiлькiсть турiв за кожним видом запропонованого транспорту.


template <typename T, typename K>
void read_file2(const string &file_name, T &r){
    ifstream fin(file_name);
    if (fin) copy(istream_iterator<K>(fin), istream_iterator<K>(), back_inserter(r));
    else throw "File not open exception\n";
}




template<typename T, typename K>
void write_list(const T &r, ostream &os, const char* pend = "\n"){
    ostream_iterator<K> ositer(os, pend);
    copy(r.begin(), r.end(), ositer);
}

void write_map_map_list(const map<string,map<string, vector<string>>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.first << " => ";
        for_each(el.second.begin(), el.second.end(), [&](const auto &e){os << e.first <<  " : " ;
            write_list<vector<string>, string>(e.second, os, " ");cout << "\n\t\t  ";}); os << "\n";});
}

void write_map_st_int(const multimap<int, string, greater <int>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.second << " => " << el.first << "\n";});
}

void write_map_map_st_int(const map<string, map<string, int>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.first << " => ";
        for_each(el.second.begin(), el.second.end(), [&](const auto &e){os << e.first <<  " : "  << e.second << "\n\t\t  ";});
        os << "\n";});
}



void task1(const vector<Tour*> &tours){
    map<string, map <string, vector<string>>> m;
    for (auto &k: tours) {
        auto s = k->getEcscursions();
        sort(s.begin(), s.end());
        m[k->getFirm()][k->getName()] = s;
    }
    write_map_map_list(m, cout);
}

template <class T1, class T2, class T3>
multimap<T2, T1, T3> swapPairs(const map<T1, T2> &m) {
    multimap<T2, T1, T3> m1;
    for (auto&& item : m) m1.emplace(item.second, item.first);
    return m1;
}

void task2(const vector<Tour*> &tours){
    map<string, int> m;
    for (auto &k: tours) for (auto &s: k->getEcscursions())m[s] += 1;
    multimap<int, string, greater <int>> m2 = swapPairs<string, int, greater <int>>(m);
    write_map_st_int(m2, cout);
}

void task3(const vector<Tour2> &tours){
    map<string, map<string, int>>m;
    for (auto &k: tours) m[k.getFirm()][k.getTransport()] += 1;
    write_map_map_st_int(m, cout);
}

int main() {
    vector<Tour> tours1;
    vector<Tour2> tours2;
    vector<Tour*> all_tours;
    read_file2<vector<Tour>, Tour>("/Users/sophiyca/ClionProjects/ex_pr1/data1.txt", tours1);
    read_file2<vector<Tour2>, Tour2>("/Users/sophiyca/ClionProjects/ex_pr1/data2.txt", tours2);


    for (int i = 0; i < tours1.size(); i++) all_tours.push_back(&tours1[i]);
    for (int i = 0; i < tours2.size(); i++) all_tours.push_back(&tours2[i]);


    for(Tour * el: all_tours){
        el->print();
        cout << "\n";
    }

    task1(all_tours);
    task2(all_tours);
    task3(tours2);
    return 0;
}