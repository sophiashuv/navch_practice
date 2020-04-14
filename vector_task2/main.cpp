#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


//22.	Задано масив цілих чисел. Обчислити кількість елементів масиву,
//які задовольняють умову  2^k < ak < k!, і вивести їх на екран.

/*
 * The function for filling vector with integers.
 */
void fill_vec(vector<int> &int_arr) {
    cout << "Enter elements of vector or any other char to stop: ";
    int e;
    cin >> e;
    while (!cin.fail()) {
        int_arr.push_back(e);
        cin >> e;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // This line ignores the rest of the current line, up to '\n'.
}

/*
 * The function prints vector.
 */
void show_vec(const vector<int> &vec) {
    for(int el: vec) cout << el << " ";
    cout << "\n";
}


/*
 * The function for counting factorial.
 */
int factorial(const int count){
    int factorial = 1;
    for(int i = 1; i <= count; ++i)
        factorial *= i;
    return factorial;
}


int main() {
    vector<int> int_arr;
    fill_vec(int_arr);
    show_vec(int_arr);
    int count = -1, amount = 0;
    for_each (int_arr.begin(), int_arr.end(),  [&count, &amount](const int d) {
        count++;
        //cout << count << " -> " << d << " " << pow(2, count) << " " <<  factorial(count) << endl;
        if ((d > pow(2, count)) && (d < factorial(count))) {
            amount++;
            cout << d << " ";
        }
    });
    cout << "\namount: " << amount;
    return 0;
}