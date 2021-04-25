#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>

#include "Subscriber.h"


template <typename T>
void read_file(const string file_name, vector<T> &c){
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

void Task1(vector<Subscriber> &c){
    cout << "\n-------TASK1-------\n";
    cout << "All subscribers:\n\n";
    for (auto &el: c) {
        cout << el;
    }
}

void Task2(vector<Subscriber> &c, ofstream &myfile){
    myfile << "-------TASK2-------\n";
    map<string, vector<Subscriber>> adreses;
    for (auto &el: c) {
        adreses[el.getAdress()].push_back(el);
    }

    for (auto &el: adreses) {
        myfile << el.first << " => ";
        for (auto &el2 : el.second)
            el2.print(myfile);
        myfile << "\n";
    }
}

void Task3(vector<Subscriber> &c, ofstream &myfile){
    myfile << "-------TASK3-------\n";
    cout << "Enter some first phone numbers: ";
    string nums;
    cin >> nums;
    myfile << "All phones that begins from " << nums << ": \n";
    for (auto &el: c) {
        for (auto &phone: el.getPhone()) {
            if (phone.getNum().rfind(nums, 0) == 0) {
                myfile << el;
            }
        }
    }

}

int main() {
    vector<Subscriber> subscribers;
    read_file<Subscriber>("/Users/sophiyca/CLionProjects/task7/subscribers.txt", subscribers);

    ofstream myfile;

    Task1(subscribers);
    myfile.open ("/Users/sophiyca/CLionProjects/task7/result1.txt");
    Task2(subscribers, myfile);

    ofstream myfile2;
    myfile2.open ("/Users/sophiyca/CLionProjects/task7/result2.txt");
    Task3(subscribers, myfile2);

    return 0;
}