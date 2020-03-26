#include <iostream>
#include <fstream>
#include "List.h"
#include "Connected.h"
#include "WrongConnectionException.h"

using namespace std;
//        Задано список, який складається з відрізків li(p1,p2) i=1,…n
//        на площині. Утворити список, що містить всеможливі трійки відрізків, що
//        з’єднуються під прямим кутом. Вивести список в текстовий файл та на екран.
//        Передбачити обробку виключних ситуацій.

struct Check {
    static bool check(Line& a, Line& b, Line& c){
        if ((perpendicular(a, b) && perpendicular(a, c)) || (perpendicular(a, b) && perpendicular(b, c))) return true;
//        if ((perpendicular(b, a) && perpendicular(a, c)) || (perpendicular(b, a) && perpendicular(b, c))) return true;
//        if ((perpendicular(a, b) && perpendicular(c, a)) || (perpendicular(a, b) && perpendicular(c, b))) return true;
//        if ((perpendicular(b, a) && perpendicular(c, a)) || (perpendicular(b, a) && perpendicular(c, b))) return true;
        else return false;
    }
};


void read_file(List<Line> &l, string file_name){
    Line line;
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        while ( myfile >> line) {
            l.push_back(line);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

template<typename T>
void write_file(List<T> &connected, string file_name){
    ofstream myfile (file_name);
    if (myfile.is_open()) {
        myfile << "This are all 3-lines that are connected with angle 90.\n\n";
        for (int i = 0; i < connected.GetSize(); ++i) {
            myfile << connected[i];
        }
        myfile.close();
    }
    else cout << "Unable to open file";

}

template<typename T>
void build_connections(List<Line> &l, List<Connected<T>> &connected){
    Connected<Check> con;
    size_t s = l.GetSize();
    for (size_t i = 0; i < s-2; ++i) {
        for (size_t j = i+1; j < s-1; ++j) {
            for (size_t k = j+1; k < s; ++k) {
                try {
                    con.setLines(l[i], l[j], l[k]);
                    connected.push_back(con);
                } catch (const WrongConnectionException &s){
                    continue;
                }
            }
        }
    }
}

int main() {
    List<Line> l;
    read_file(l, "/Users/sophiyca/ClionProjects/final_templete/lines.txt");
    l.Show();
    List<Connected<Check>> connected;
    build_connections(l, connected);
    cout << "\nThis are all 3-lines that are connected with angle 90.\n\n";
    connected.Show();
    write_file(connected, "/Users/sophiyca/ClionProjects/final_templete/result.txt");
    return 0;
}
