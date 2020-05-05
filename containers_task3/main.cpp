#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include "Header.h"

//        Завдання 2.
//        Розробити типи для змагання з бiгу по маршруту, який складається з кiлькох етапiв.
//        Бiгун характеризується iменем i прiзвищем, а також номе-ром.
//        Результат на етапi характеризується номером бiгуна, часом промiжного фiнiшу на етапi
//        ( у секундах вiд початку змагання), номером етапу i йогопротяжнiстю (в км).
//        Вiдомо, що не всi добiгли до фiнiшу. Iнформацiя пробiгунiв i результати з етапiв подано окремими файлами. Отримати:
//           1. iмена i прiзвища трьох бiгунiв, якi очолювали бiг на кожному етапi;
//           2. iмена i прiзвища бiгунiв, якi пробiгли весь маршрут, вiдповiдно до загального рейтингу;
//           3. для кожного бiгуна етап, де вiн мав найбiльшу середню швидкiсть i величину цiєї швидкостi.

using namespace std;

/*
 * The function for reading file.
 */
template <typename T>
void read_file(const string &file_name, vector<T> &r){
    ifstream fin(file_name);
    if (fin) {
        copy(istream_iterator<T>(fin), istream_iterator<T>(), back_inserter(r));
    }
    else throw "File not open exception\n";
}

/*
 * The function writes a Sequence container using
 * ostream_iterator.
 */
template <typename T, typename K>
void write(const K &r, ostream &os){
    ostream_iterator<T> ositer(os, "\n");
    copy(r.begin(), r.end(), ositer);
}

/*
 * Comparator for task1
 */
struct comp {
    bool operator() (const pair<int, Runner>& lhs, const pair<int, Runner>& rhs) const {
        return lhs.first < rhs.first;
    }
};

/*
 * Comparator for task2
 */
struct comp2 {
    bool operator() (const pair<string, double>& lhs, const pair<string, double>& rhs) const {
        return lhs.second > rhs.second;
    }
};


/*
 * The function writes result for task1
 */
template <typename T>
void write_map(const T &results){
    for_each(results.begin(), results.end(), [](auto& t){cout << t.first << ": \n";
        auto k = t.second.begin();
        for (int i = 0; i < 3; ++i) {
            cout << k->first << " : " << k->second.getName()  << " " <<  k->second.getSurname() << "\n"; k++;
        } cout << "\n";
    });
}


void task1(map<string, set<pair<int, Runner>, comp>> &results, const vector<Runner> &r, const vector<Result> &res){
    for_each(res.begin(), res.end(), [&](auto & it){ results[it.getStage()].insert(
            make_pair(it.getTime(), *find_if(r.begin(), r.end(), [&it](auto &el){return el.getNum() == it.getNum();})));});
}


void task2(const map<string, set<pair<int, Runner>, comp>> &results){
    auto last = (--results.end())->second;
    for_each(last.begin(), last.end(), [](const auto &k){ cout << k.first << " : " <<
    k.second.getName() << " " << k.second.getSurname() << "\n";});
}


/*
 * The function writes result for task2
 */
template <typename T>
void write_map2(const T &results){
    for_each(results.begin(), results.end(), [](auto& t){cout << t.first << ": \n";
    cout << t.second.begin()->first << " : " << t.second.begin()->second << "\n";
    });
}


void task3(map<Runner, set<pair<string, double>, comp2>> &result, const vector<Runner> &r, const vector<Result> &res){
    for(auto &i: r){
        for(auto &k: res){
            if (k.getNum() == i.getNum()){
                double e_time = k.getTime(), e_num = k.getE_num();
                if (e_num != 1) e_time -= find_if(res.begin(), res.end(), [&](auto &el){return el.getNum() == i.getNum() && el.getE_num() == k.getE_num()-1;})->getTime();
                result[i].insert(make_pair(k.getStage(), k.getSpeed(e_time)));
            }
        }
    }
}



int main() {
    vector<Runner> r;
    vector<Result> res;
    read_file("/Users/sophiyca/ClionProjects/containers_task3/runners", r);
    read_file("/Users/sophiyca/ClionProjects/containers_task3/stages", res);
    write<Runner, vector<Runner>>(r, cout);
    write<Result, vector<Result>>(res, cout);

    //TASK1
    cout << "-------------------TASK1-------------------\n";
    map<string, set<pair<int, Runner>, comp>> results;
    task1(results, r, res);
    write_map(results);

    //TASK2
    cout << "-------------------TASK2-------------------\n";
    task2(results);

    //TASK3
    cout << "\n-------------------TASK3-------------------\n";
    map<Runner, set<pair<string, double>, comp2>> result;
    task3(result, r, res);
    write_map2(result);
    return 0;
}