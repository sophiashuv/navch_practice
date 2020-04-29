#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include "Header.h"


//        Завдання 1.Розробити типи для змаганнь, якi включають кiлька видiв спорту.
//        Спортс-мен характеризується iменем i прiзвищем, а також номером.
//        Iнформацiя прорезультат з кожного виду – назва виду, номер спортсмена,
//        кiлькiсть балiв iкiлькiсть штрафiв, причому спортсмен знiмався зi змагань,
//        якщо сумарнакiлькiсть штрафiв перевищувала 10 % вiд сумарної кiлькостi балiв.
//        Вiдомо,що не всi спортсмени змагалися у всiх видах. Iнформацiя про спортсменiвта
//        результати змагань поданi окремими файлами. Отримати:
//        1. iмена i прiзвища переможцiв з кожного виду спорту, пiдсумковим розультатом є рiзниця балiв i штрафiв;
//        2. iмена i прiзвища спортсменiв за рейтингом результатiв усiх змагаь;
//        3. для кожного спортсмена (за алфавiтним порядком прiзвищ) рейтингза балами у кожному видi, де вiн змагався.

/*
 * The function for reading file from file data.txt.
 */
void read_file_data(const string &file_name, vector<Sport> &m, vector<Sportsman> &sp){
    ifstream fin(file_name);
    if (fin) {
        Sport sport(sp);
        while (fin >> sport){
            m.push_back(sport);
        }
    }
    else throw "File not open exception\n";
}

/*
 * The function for reading file from file sportmans.txt.
 */
void read_file_sportsman(const string &file_name, vector<Sportsman> &m){
    ifstream fin(file_name);
    if (fin) {
        Sportsman sportsman;
        while (fin >> sportsman){
            m.push_back(sportsman);
        }

    }
    else throw "File not open exception\n";
}

/*
 * A template function to print a container.
 */
template <typename T, typename S>
void write_vec(const T &vec, ostream &os){
    ostream_iterator<S> ositer(os, "\n");
    copy(vec.begin(), vec.end(), ositer);
}

/*
 * The function cleans Shtafnics from containers
 */
void clear_shtraf(vector<Sportsman> &s, vector<Sport> &m){
    int sum_p = 0, sum_s = 0;
    for (auto el = s.begin(); el != s.end(); ) {
        for (const auto &el2 : m) {
            sum_p += el2.getPoints(el->getNum()).first;
            sum_s += el2.getPoints(el->getNum()).second;
        }
        if (sum_p * 0.1 < sum_s) {
            //for (auto &el2 : m) el2.erase_sportsman(el->getNum());
            el = s.erase(el);
        }
        else el++;
        sum_p = 0, sum_s = 0;
    }
}

/*
 * The function insert a sum of sportsmen points in all sports and
 * their info (from bigger points yo lover) in a multimap
 */
void task2(vector<Sportsman> &s, vector<Sport> &m, multimap<int, Sportsman, greater <int>>&rating){
    int sum = 0;
    for (auto & el : s) {
        for_each(m.begin(), m.end(), [&](const auto &el2){ sum += el2.gerRealPoints(el.getNum());});
        rating.insert(make_pair(sum, el));
        sum = 0;
    }
}

/*
 * The function insert all sportsmen with all sports they
 * took part(sorted from max points to lover) into a map.
 */
void task3(vector<Sportsman> &s, vector<Sport> &m, map<Sportsman, map<int, string>> &r){
    map<int, string> k;
    for (auto & el : s) {
        for (auto & el2 : m) if (el2.getPoints(el.getNum())!= pair<int, int>()) k[el2.gerRealPoints(el.getNum())] = el2.getSport();
        r[el] = k;
        k.clear();
    }
}


int main() {
    try {
        ofstream myfile;
        myfile.open ("/Users/sophiyca/ClionProjects/containers_task2/result.dat");
        vector<Sportsman> s;
        read_file_sportsman("/Users/sophiyca/ClionProjects/containers_task2/sportsman.txt", s);
        vector<Sport> m;
        read_file_data("/Users/sophiyca/ClionProjects/containers_task2/data.txt", m, s);
        write_vec< vector<Sportsman>, Sportsman>(s, myfile);
        myfile << "\n------------------\n";
        write_vec< vector<Sport>, Sport>(m, myfile);


        //Task1
        clear_shtraf(s, m);
        myfile << "\n------------------\n";

        // do this because of problems with erase_sportsman
        m.clear();
        read_file_data("/Users/sophiyca/ClionProjects/containers_task2/data.txt", m, s);
        myfile << "\nTASK1\n";
        write_vec< vector<Sport>, Sport>(m, myfile);


        //Task2
        myfile << "\n------------------\n";
        myfile << "\nTASK2\n";
        multimap<int, Sportsman, greater <int>>rating;
        task2(s, m, rating);
        for_each(rating.begin(), rating.end(), [&myfile](const auto &el){myfile << el.first << " => " << el.second << "\n";});


        //Task3
        myfile << "\n\n------------------\n";
        myfile << "\nTASK3\n";
        map<Sportsman, map<int, string>> r;
        task3(s, m, r);
        for_each(r.begin(), r.end(), [&](const auto &e){myfile << e.first << " => ";
            for_each(e.second.begin(), e.second.end(),
                    [&myfile](const auto &el){myfile << el.first << " : " << el.second << "   ";});
            myfile << "\n";});

    } catch (const char* ex) {
        cout << ex;
    }

    return 0;
}