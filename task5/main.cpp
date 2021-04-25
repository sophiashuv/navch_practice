#include <iostream>

#include <fstream>
#include <string>
#include <deque>
#include <numeric>

#include "Spending.h"


template <typename T>
void read_file(const string file_name, deque<T> &c){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        T el;
        try {
            while (myfile >> el)
                c.push_back(el);
        } catch (const char *msg) {
            cout << msg << endl;
        }
    }
    else cout << "Unable to open file";
}

void Task1(deque<Spending> &c){
    cout << "\n-------TASK1-------\n";
    cout << "All spendings:\n\n";
    for (int i=0; i < c.size(); ++i) {
        cout << c[i];
    }
    cout << endl;
}

void Task2(deque<Spending> &c, ofstream &myfile){
    myfile << "-------TASK2-------\n";
    deque<Spending> united = deque<Spending>();
    for (int i = 0; i < c.size(); ++i) {
        if (find(united.begin(), united.end(), c[i]) == united.end()){
            united.push_back(c[i]);
        }
        else {
            for (auto &m: c[i].getMaterials())
                (*find(united.begin(), united.end(), c[i])).add_material(m);
        }
    }
    sort (united.begin(), united.end());

    for (int i=0; i < united.size(); ++i)
        myfile << united[i];
    myfile << endl;
}


void Task3(deque<Spending> &c, ofstream &myfile){
    myfile << "-------TASK3-------\n";
    deque<SpentMaterial> total = deque<SpentMaterial>();
    for (int i = 0; i < c.size(); ++i) {
        for (auto &m: c[i].getMaterials()) {
            if (find(total.begin(), total.end(), m) == total.end()) {
                total.push_back(m);
            } else {
                (*find(total.begin(), total.end(), m)) += m;
            }
        }
    }

    for (int i=0; i < total.size(); ++i)
        myfile << total[i];
    myfile << endl;
    double p = 0;
    double v = 0;

    for (int i=0; i < total.size(); ++i) {
        p += total[i].getPrice();
        v += total[i].getVolume();
    }
    myfile << "Total price: " << p << "\nTotal Volume: " << v;

}



int main() {

    deque<Spending> spendings;
    read_file<Spending>("/Users/sophiyca/CLionProjects/task5/data.txt", spendings);
    ofstream myfile;
    myfile.open ("/Users/sophiyca/CLionProjects/task5/result1.txt");
    ofstream myfile2;
    myfile2.open ("/Users/sophiyca/CLionProjects/task5/result2.txt");

    Task1(spendings);
    Task2(spendings, myfile);
    Task3(spendings, myfile2);
    return 0;
}