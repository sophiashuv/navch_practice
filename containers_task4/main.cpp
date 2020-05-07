#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include "Header.h"

//        Розробити типи для облiку видачi пацiєнтам лiкiв в медзакладi вiдповiдно до призначень лiкаря.
//        Пацiєнт характеризується iменем i прiзвищемта реєстрацiйним номером.
//        Призначення характеризується реєстрацiйнимномером пацiєнта, датою, назвою лiкiв, дозою в мг i кiлькiстю прийомiву день.
//        Iнформацiя про пацiєнтiв подана окремим файлом. Призначеннятакож подано кiлькома окремими файлами. Отримати:
//        1. для кожного пацiєнта ( за iменем i прiзвищем) повний перелiк (безповторень) отриманих
//            лiкiв iз вказанням сумарної кiлькостi кожного пре-парату в мг;
//        2. для кожного дня розхiд виданих препаратiв у мг;
//        3. для кожного препарату загальну кiлькiсть вжитого.


using namespace std;

/*
 * The function for reading file.
 */
template <typename T>
void read_file(const string &file_name, vector<T> &r){
    ifstream fin(file_name);
    if (fin)copy(istream_iterator<T>(fin), istream_iterator<T>(), back_inserter(r));
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


void task1(map<string, map<string, int>> &results, const vector<Patient> &r, const vector<Appointment> &res) {
    for_each(r.begin(), r.end(), [&](auto &it) {
        for (auto &el: res)
            if (el.getNum() == it.getNum())
                results[it.getFullSurname()][el.getM_name()] += el.getDoza()* el.getAmount();
    });
}


void task2(map<string, double > &results, const vector<Patient> &r, const vector<Appointment> &res) {
    for(auto &el: res){
        results[el.getDate()] += el.getDoza()*el.getAmount();
    }
}

void task3(map<string, double> &results, const vector<Patient> &r, const vector<Appointment> &res) {
    for(auto &el: res){
        results[el.getM_name()] += el.getDoza()*el.getAmount();
    }
}

template <typename T>
void write_map(const T &results){
    for_each(results.begin(), results.end(), [](auto& t){cout << t.first << " => \n";
    for(auto e: t.second)cout << e.first << " : " << e.second << "\n"; cout << "\n";});
}


int main() {
    vector<Patient> r;
    vector<Appointment> res;
    read_file("/Users/sophiyca/ClionProjects/containers_task4/Patients.txt", r);
    read_file("/Users/sophiyca/ClionProjects/containers_task4/Appointments.txt", res);
    write<Patient, vector<Patient>>(r, cout);
    write<Appointment, vector<Appointment>>(res, cout);

    //TASK1
    cout << "-------------------TASK1-------------------\n";
    map<string, map<string, int>> results;
    task1(results, r, res);
    write_map(results);

    //TASK2
    cout << "-------------------TASK2-------------------\n";
    map<string, double > results2;
    task2(results2, r, res);
    for_each(results2.begin(), results2.end(), [](auto& t){cout << t.first << ": " << t.second << "\n";});

    //TASK3
    cout << "-------------------TASK3-------------------\n";
    map<string, double> results3;
    task3(results3, r, res);
    for_each(results3.begin(), results3.end(), [](auto& t){cout << t.first << ": " << t.second << "\n";});

    return 0;
}