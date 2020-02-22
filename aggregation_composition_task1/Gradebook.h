//
// Created by Sophia Shuvar on 22.02.20.
//

#ifndef AGGREGATION_COMPOSITION_TASK1_GRADEBOOK_H
#define AGGREGATION_COMPOSITION_TASK1_GRADEBOOK_H

#endif //AGGREGATION_COMPOSITION_TASK1_GRADEBOOK_H
#include <iostream>
#include "Zalik.h"
#include "Exam.h"

using namespace std;

class Gradebook{

private :
    long long number;
    int size;
    Probation **arr;

public:
    Gradebook(): number(0), size(0) ,arr(nullptr){};

    Gradebook(const Gradebook & a){
        size = a.size;
        number = a.number;
        arr = new Probation*[size];
        for(int i = 0; i < size; i++) arr[i] = a.arr[i];

    }

    ~Gradebook(){
        if(arr != nullptr) delete[]arr;
    }

    string toString(){
        string res = "Gradebook № " + to_string(number) + "\n";
        res += "--------------------------------------------------------------------------------\n";
        res += "| Subjects_____\t| Points\t| Lecture Surname\t| Assistant Surname\t| Grade\n";
        res += "--------------------------------------------------------------------------------\n";
        for(int i = 0; i < size; i++) res += arr[i]->toString() + "\n";
        res += "--------------------------------------------------------------------------------\n";
        return res;
    }

    friend ostream& operator<<(ostream& out, Gradebook& a) {
        out << a.toString();
        return out;
    }

    void input(istream & in){
        in >> number;
        in >> size;
        delete[]arr;
        arr = new Probation*[size];
        char c;
        Probation p;
        string l;
        string a;
        for (size_t i = 0; i < size; i++) {
            in >> c;
            in >> p;
            if (c == 'Z') {
                in >> l;
                arr[i] = new Zalik(p, l);
            } else {
                in >> l;
                in >> a;
                arr[i] = new Exam(p, l, a);
            }
        }
    }

    Probation *max_point(){
        Probation* max_p = arr[0];
        for (size_t i = 1; i < size; i++) if( max_p->getPoints() < arr[i]->getPoints()) max_p = arr[i];
        return max_p;
    }

    string max_point_check(){
        if (dynamic_cast<Exam*>(max_point())) return "Exam";
        else return "Not Exam";
    }

    int num_not_passed(){
        int n = 0;
        for (size_t i = 0; i < size; i++) if (arr[i]->check().compare("Not Passed") == 0) n += 1;
        return n;
    }

    double av_point(){
        double point = 0;
        for (size_t i = 0; i < size; i++) point+=arr[i]->getPoints();
        return point/size;
    }
};
