
#include <fstream>


#include "Polygonal.h"
#include "Segment.h"

using namespace std;


Line ** read_file2(string file_name, int n){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        Line **c = new Line* [n];
        char name;
        Point p1;
        Point p2;
        Point p3;
        for (size_t i = 0; i < n; i++) {
            myfile >> name;
            if (name == 'S') {
                myfile >> p1;
                myfile >> p2;
                c[i] = new Segment (p1, p2);

            }
            else {
                myfile >> p1;
                myfile >> p2;
                myfile >> p3;
                c[i] = new Polygonal (p1, p2, p3);
            }
        }
        return c;
    }else cout << "Unable to open file";
}




void sort_by_len(Line ** all, int n){
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            if(all[i]->length() > all[j]->length()) swap(all[i], all[j]);
}

int main() {
    int n = 6;
    Line **all = read_file2("/Users/sophiyca/ClionProjects/abstract_classes_task5/text.txt", n);
    for (int i = 0; i < n; i++) all[i]->print();
    cout<< "----------------------------------------\n";
    sort_by_len(all, n);
    for (int i = 0; i < n; i++) all[i]->print();
    cout<< "----------------------------------------\n";
    int k = 6;
    for (int i = 0; i < n; i++) if (dynamic_cast<Polygonal*>(all[i]) && all[i]->length() > k) all[i]->print();
    return 0;
}