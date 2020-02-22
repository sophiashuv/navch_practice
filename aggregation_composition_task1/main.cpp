#include <iostream>

#include <fstream>
#include "Gradebook.h"

int main() {
    Gradebook g;
    ifstream myfile("/Users/sophiyca/ClionProjects/aggregation_composition_task1/gradebook.txt");
    if (myfile.is_open()) {
        g.input(myfile);
    } else cout << "Unable to open file";
    cout << g.toString();
    cout << "Max point: \n" + g.max_point()->toString() + " - " + g.max_point_check() << "\n";
    cout << "Amount of not passed probations: " << to_string(g.num_not_passed()) + "\n";
    cout << "Average point is: " << g.av_point();
}