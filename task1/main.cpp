#include <iostream>
#include "tasks.cpp"


int main() {
    int n;
    cout << "Enter amount of detals: ";
    cin >> n;
    auto *zakaz = input_array(n);
    print_concrete_data(zakaz, n);
    return 0;
}