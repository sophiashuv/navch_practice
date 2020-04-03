#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Azc3.h"
using namespace std;


template <typename T>
vector<T> max_patix(const vector<T> &vec){
    vector<T> maximals;
    T max;
    for(T el: vec) if (el > max) max = el;
    for(T el: vec) if (el == max) maximals.push_back(el);
    return maximals;
}

template <typename T>
void read_file(const string file_name, vector<T> &c){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        T el;
        while (myfile >> el) c.push_back(el);
    }else cout << "Unable to open file";
}

vector<string> all_marks(vector<Azc2> &second_p){
    bool k = 0;
    vector<string> all_c;
    for(int i = 0; i < second_p.size(); i ++){
        for(int j = 0; j < i; j ++) if (second_p[i].GetMarka() == second_p[j].GetMarka()) k = 1;
        if (k == 0)  all_c.push_back(second_p[i].GetMarka());
        k =0;
    }
    return all_c;
}

double vartist(const vector<Azc2> &second_p, const string &mark){
    double sum = 0;
    for(Azc2 el: second_p) if (el.GetMarka() == mark)sum += el.platiz();
    return sum;
}

void vartist_all_marks(vector<Azc2> &second_p){
    vector<string> all_c = all_marks(second_p);
    for(string st: all_c) cout << st << " - " << vartist(second_p, st) << endl;
}


vector<string> all_marks2(vector<Azc*> &second_p){
    bool k = 0;
    vector<string> all_c;
    for(int i = 0; i < second_p.size(); i ++){
        for(int j = 0; j < i; j ++) if (second_p[i]->GetMarka() == second_p[j]->GetMarka()) k = 1;
        if (k == 0)  all_c.push_back(second_p[i]->GetMarka());
        k = 0;
    } return all_c;
}

double vartist2(vector<Azc*> &second_p, const string &mark){
    double sum = 0;
    for(Azc* el: second_p) if (el->GetMarka() == mark) sum += el->platiz();
    return sum;
}

void vartist_all_marks2(vector<Azc*> &second_p){
    vector<string> all_c = all_marks2(second_p);
    for(string st: all_c) cout << st << " - " << vartist2(second_p, st) << endl;
}

int Azc2::percentage = 35;
int Azc3::percentage = 75;

int main() {
    cout << "\n-------------------------task1------------------------------------------\n";
    int n;
    cout << "Enter amount: ";
    cin >> n;
    Azc el;
    vector<Azc> first_p;
    for ( int i = 0; i < n; i++) {
        cin >> el;
        first_p.push_back(el);
    }
    cout << "Azc: \n";
    for (Azc el: first_p) {
        el.print();
        cout << "\n";
    }

    vector <Azc> max =  max_patix<Azc>(first_p);
    cout << "\nMax is: \n";
    for (Azc el: max) {
        el.print();
        cout << " platiz: " << el.platiz() << "\n";
    }

    //-----------------------------------------
    cout << "\n-------------------------task2------------------------------------------\n";

    vector<Azc2> second_p;
    read_file<Azc2>("/Users/sophiyca/ClionProjects/ex_var2/azc2", second_p);
    cout << "\nAzc2: \n";
    for (Azc2 el: second_p){
        el.print();
        cout << "\n";
    }

    vector <Azc2> max2 =  max_patix<Azc2>(second_p);
    cout << "\nMax is: \n";
    for (Azc2 el: max2) {
        el.print();
        cout << " platiz: " << el.platiz() << "\n";
    }
    vartist_all_marks(second_p);

    //-----------------------------------------
    cout << "\n-------------------------task3------------------------------------------\n";

    vector<Azc3> third_p;
    read_file<Azc3>("/Users/sophiyca/ClionProjects/ex_var2/azc3", third_p);

    size_t size1 = first_p.size(), size2 = second_p.size(), size3 = third_p.size();
    vector <Azc*> all_p;
    for (int i = 0; i < size1; i++) all_p.push_back(&first_p[i]);
    for (int i = 0; i < size2; i++) all_p.push_back(&second_p[i]);
    for (int i = 0; i < size3; i++) all_p.push_back(&third_p[i]);
    for(Azc* el: all_p) {
        el->print();
        cout << " platiz: " << el->platiz() << "\n";
    }
    cout << "----------------------------------------\n";
    vartist_all_marks2(all_p);
}