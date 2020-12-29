#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;


double ** fill_matrix(int n, int m){
    double **mas = new double *[n];
    for (int i = 0; i < n; ++i) {
        mas[i] = new double[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mas[i][j];
        }
    }
    return mas;
}


string* read_file(string file_name, int n){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        string *words = new string[n];
        for (int i = 0; i < n; i++) myfile >> words[i];
        return words;
    }
    else {
        cout << "Unable to open file";
        return 0;
    }

}


void task1(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int r = 1;
    while (pow(2, r) <= n){
        r++;
    }
    cout << "r = " << r << "\n";
}


void task2(){
    int n, m;
    cout << "Enter num of lines and rows: ";
    cin >> n >> m;
    cout << "Enter matrix : \n";
    double **mas = fill_matrix(n, m);
    double **mas2 = new double *[n];
    for (int i = 0; i < n; ++i) {
        mas2[i] = new double[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (j != m - 1) {
                mas2[i][j] = mas[i][j] + mas2[i][j+1];
            }
            else {
                mas2[i][j] = mas[i][j];
            }
        }
    }

    cout << "New matrix: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mas2[i][j] << " ";
        }
        cout << "\n";
    }
}


void task3(){
    int words_am;
    int position = -1;
    cout << "Enter amount of words: ";
    cin >> words_am;
    string * words = read_file("words.txt", words_am);
    for (int i = 0; i < words_am; ++i) {
        if (i != 1 and words[i] == words[1]) {
            position = i;
        }
    }
    if (position != -1) cout << "Word " << words[1] << " occurs at position 2 and " << position + 1 << "\n";
    else cout << "Word " << words[1] << " occurs only at position 1\n";
}


class Tovar{
private:
    string name;
    int grn_am;
    int coins_am;
public:
    Tovar(){
        name = "";
        grn_am = 0;
        coins_am = 0;
    }

    Tovar(string _name, int _grn_am, int _coins_am){
        name = _name;
        grn_am = _grn_am;
        coins_am = _coins_am;
    }

    Tovar(const Tovar & a){
        name = a.name;
        grn_am = a.grn_am;
        coins_am = a.coins_am;
    }

    ~Tovar() {};

    friend istream& operator>>(istream& in, Tovar& a) {
        in >> a.name;
        in >> a.grn_am;
        in >> a.coins_am;
        return in;
    }

    double getPrice() {
        return double(grn_am) + double(coins_am)/100.0;
    }

    friend ostream& operator<<(ostream& out, Tovar& a) {
        out << "Name: " << a.name << "  price: " << a.getPrice();
        return out;
    }

    friend bool operator <(const Tovar &a,  Tovar b){
        return a.name < b.name;
    }

};


Tovar* read_tovar(string file_name, int n){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        Tovar *t = new Tovar[n];
        for (int i = 0; i < n; i++) {
            myfile >> t[i];
        }
        return t;
    }
    else {
        cout << "Unable to open file";
        return 0;
    }

}


void task4(){
    int n;
    cout << "Enter amount of tovar in txt file: ";
    cin >> n;
    Tovar * tovars = read_tovar("tovar.txt", n);
    cout << "\n------------------------------------------\n";
    cout << "The most expensive tovar: ";
    double p = 0;
    Tovar most_expensive;
    for (int i = 0; i < n; ++i) {
        if (tovars[i].getPrice() > p) {
            most_expensive = tovars[i];
            p = tovars[i].getPrice();
        }
    }
    cout << most_expensive << " \n";

    cout << "\n------------------------------------------\n";
    cout << "Sorted array: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tovars[i] < tovars[j])
                swap(tovars[i], tovars[j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << tovars[i] << "\n";
    }
}


int main() {
    int n;
    while (true) {
        cout << "\nENTER NUMBER OF TASK: ";
        cin >> n;
        switch (n) {
            case 1: {
                task1();
                continue;
            }
            case 2: {
                task2();
                continue;
            }
            case 3: {
                task3();
                continue;
            }
            case 4: {
                task4();
                continue;
            }
            default:
                break;
        }

        system("pause");
        return 0;
    }
}