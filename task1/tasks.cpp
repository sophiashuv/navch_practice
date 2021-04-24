#include <iostream>
#include "Detal.h"

using namespace std;

Detal * input_array(int n){
    auto *zakaz = new Detal[n];
    for (int i = 0; i < n; i++)
        while (true) {
            try {
                cin >> zakaz[i];
                break;
            } catch (const char *msg) {
                cout << msg << endl;
                cout << "Try one more time!" << endl;
            }
        }
    return zakaz;
}

void print_concrete_data(Detal * zakaz, int n, Sort sort=sort1){
    Date date;
    cout << "Enter date (y m d): ";
    cin >> date;
    for (int i = 0; i < n; i++){
        if (zakaz[i].getSort() == sort && zakaz[i].getDate() > date)
            cout << zakaz[i];
    }
}