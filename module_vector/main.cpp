#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
//Варіант 4
//1. Дано вектор цілих чисел. Знайти кількість елементів, які є симетричними.
//2. Дано два вектори дійсних чисел. Утворити новий вектор з елементів першого вектора, які також
//містяться в другому векторі.
//3. Дано два ветори дійсних чисел. Перемістити частину другого ветора, обмежену максимальним і
//мінімальним елементами, після останнього від’ємного елемента першого вектора.
using  namespace std;



/*
 * The function for filling vector with integers.
 */
void fill_vec(vector<int> &vec){
    cout << "Enter elements of vector or 'stop' to continue: ";
    string e;
    cin >> e;
    while (e != "stop"){
        vec.push_back(stoi(e));
        cin >> e;
    }
}


/*
 * The function prints vector.
 */
void show_vec(const vector<int> &vec) {
    for(int el: vec) cout << el << " ";
    cout << "\n";
}

/*
 * The function inserts all elms between max and min if second vec after a last відємне rl of first.
 */
void insert1( vector<int> &vec1, const vector<int> &vec2){
    int min = 1000000;
    int max = -100000;
    size_t min_i = 0;
    size_t max_i = 0;
    for (size_t i = 0; i < vec2.size(); ++i) {
        if (max < vec2[i]) {
            max = vec2[i];
            max_i = i;
        }
        if (min > vec2[i]) {
            min = vec2[i];
            min_i = i;
        }
    }
    for (size_t i = vec1.size()-1; i >= 0; i--) {
        if (vec1[i] < 0 && min_i < max_i){
            vec1.insert(vec1.begin() + i + 1, vec2.begin() + min_i, vec2.begin() + max_i + 1);
            return;
        }
        if (vec1[i] < 0 && max_i < min_i){
            vec1.insert(vec1.begin() + i +1, vec2.begin() + max_i, vec2.begin() + min_i + 1);
            return;
        }
    } cout << "There's no negative el \n";
}

/*
 * The function checks whether int is a simetric or not.
 */
bool check(int val){
    int n = val, digit, rev = 0;
    do {
        digit = val % 10;
        rev = (rev * 10) + digit;
        val = val / 10;
    } while (val != 0);
    if (n == rev)
        return true;
    else
        return false;

}

/*
 * The function checks whether vector is a simetric or not.
 */
int check_simetric(vector<int> &vec){
    int amount = 0;
    for (int el: vec){
        if (check(el)) amount++;
    }
    return amount;
}

/*
 * The function prints same elements in both vectors.
 */
void task2(vector<int> a1, vector<int> a2) {
    vector<int> b;
    for (int el1: a1) {
        bool f = false;
        for (int el2: a2) {
            if (el1 == el2) f = true;
        }
        if (f) b.push_back(el1);
    }
    show_vec(b);
}

//21 343 456 -787 67 1 4 6 stop
//7 67 21 1 7 456 stop


int main() {
    vector<int> vec1;
    vector<int> vec2;
    cout << "Fill first vector!\n";
    fill_vec(vec1);
    cout << "Simetric elements: " << check_simetric(vec1) << "\n";
    cout << "Fill second vector!\n";
    fill_vec(vec2);
    task2(vec1, vec2);
    insert1(vec1, vec2);
    show_vec(vec1);
    return 0;
}
