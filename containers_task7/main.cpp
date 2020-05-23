#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include "Reader.h"
#include "Book.h"
#include "Order.h"

template <typename T, typename K>
void read_file(const string &file_name, T &r){
    ifstream fin(file_name);
    if (fin)copy(istream_iterator<K>(fin), istream_iterator<K>(), back_inserter(r));
    else throw "File not open exception\n";
}

void write_map_map(map<string, map<string, int>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.first << " => "; for_each(el.second.begin(), el.second.end(),
                                                                                         [&](const auto &e){os << e.first <<  " : " << e.second << "\n\t\t\t\t    ";});  os << "\n";});
}

void write_multimap_int(multimap<int, string, greater<>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.second << " => " << el.first << "\n";});
}

void write_map_int(map<string, int> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.first << " => " << el.second << "\n";});
}

void write_map_pair(map<string, pair<int, int>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.first << " => +:" << el.second.first << " , -: " << el.second.second << "\n";});
}

void task1(map<string, map<string, int>> &m, const vector<Reader>& readers, const vector<Book>& books, const vector<Order>& orders){
    for(auto &r: readers) {
        for(auto &o: orders) {
            for(auto &b: books) {
                if(o.getBook_id() == b.getB_num() && o.getReader_id() == r.getNum()) m[r.getName() + " " + r.getSurname()][b.getAuthor()]+=1;
            }
        }
    }
}

void task2(multimap<int, string, greater<>> &m, const map<string, map<string, int>> &m0){
    for (auto &el: m0) {
        m.insert(make_pair(accumulate(begin(el.second), end(el.second), 0,
                                      [](int v, const pair<string, int> &p) {return v + p.second;}), el.first));
    }
}

void task3(map<string, int> &m, const vector<Book>& books, const vector<Order>& orders){
    for (auto &b: books)
        for (auto &o: orders) if (b.getB_num() == o.getBook_id()) m[b.getAuthor() + " " + b.getName()]+=1;
}

void task4(map<string, pair<int, int>> &m, const vector<Order>& orders){
    for (auto &o: orders)
        if (o.isDone() == 1) m[o.getDate()].first +=1;
        else  m[o.getDate()].second +=1;
}


int main() {
    vector<Reader> readers;
    vector<Book> books;
    vector<Order> orders;
    read_file<vector<Reader>, Reader>("/Users/sophiyca/ClionProjects/containers_task7/readers.txt", readers);
    read_file<vector<Book>, Book>("/Users/sophiyca/ClionProjects/containers_task7/books.txt", books);
    read_file<vector<Order>, Order>("/Users/sophiyca/ClionProjects/containers_task7/orders1.txt", orders);
    read_file<vector<Order>, Order>("/Users/sophiyca/ClionProjects/containers_task7/oders2.txt", orders);

    cout << "TASK1\n";
    map<string, map<string, int>> map1;
    task1(map1, readers, books, orders);
    write_map_map(map1, cout);

    cout << "\n-------------------\n\nTASK2\n";
    multimap<int, string, greater<>> map2;
    task2(map2, map1);
    write_multimap_int(map2, cout);

    cout << "\n-------------------\n\nTASK3\n";
    map<string, int> map3;
    task3(map3, books, orders);
    write_map_int(map3, cout);

    cout << "\n-------------------\n\nTASK4\n";
    map<string, pair<int, int>> map4;
    task4(map4, orders);
    write_map_pair(map4, cout);

    return 0;
}