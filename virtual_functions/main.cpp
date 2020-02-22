#include <iostream>
#include <fstream>
#include <string>

#include "Prepayment.h"
#include "Subscriber.h"
#include "Contract.h"

using namespace std;

Subscriber ** read_file(string file_name, int n){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        Subscriber **c = new Subscriber* [n];
        char name;
        Subscriber s;
        bool p1;
        int p2;
        for (size_t i = 0; i < n; i++) {
            myfile >> name;
            myfile >> s;
            if (name == 'C') {
                myfile >> p1;
                myfile >> p2;
                c[i] = new Contract(s, p1, p2);
            }
            else {
                myfile >> p1;
                myfile >> p2;
                c[i] = new Prepayment(s, p1, p2);
            }
        } return c;
    }else cout << "Unable to open file";
}

void sort_by_age(Subscriber ** all, int n){
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        if(all[i]->getAge() > all[j]->getAge()) swap(all[i], all[j]);
}

int main() {
    int n = 7;
    Subscriber ** all = read_file("/Users/sophiyca/ClionProjects/virtual_functions/Text.txt", n);
    sort_by_age(all, n);
    for (int i = 0; i < n; i++) all[i]->print();
    return 0;
}