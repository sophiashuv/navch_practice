#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "WaterCounter.h"


/*
 * The function reads .txt file using istream_iterator.
 * Returns vector of WaterCounters.
 */
vector<WaterCounter> read_file(const string &file_name){
    ifstream fin(file_name);
    if (fin) {
        istream_iterator<WaterCounter> isiter(fin), pend;
        vector<WaterCounter> students(isiter, pend);
        return students;
    }
    else throw "File not open exception\n";
}


/*
 * The function writes a vector of WaterCounters using
 * ostream_iterator.
 */

void write(const vector<WaterCounter> &students, ostream &os){
    ostream_iterator<WaterCounter> ositer(os, "\n");
    copy(students.begin(), students.end(), ositer);
}


int main() {
    try {

        vector<WaterCounter> water_vec = read_file("/Users/sophiyca/ClionProjects/WaterCounter/water.txt");
        // TASK1
        cout << "Table: ";
        write(water_vec, cout);

        // TASK2
        cout << "\nSum of all water amount = " << accumulate(water_vec.begin(), water_vec.end(), 0);

        // TASK3
        cout << "\nMax:\n";
        auto max_e = max_element(water_vec.begin(), water_vec.end());
        while(max_e != water_vec.end()) {
            cout << *max_e << "\n";
            max_e = find(++max_e, water_vec.end(), *(--max_e));
        }

    } catch (const char* ex) {
        cout << ex;
    }

    return 0;
}