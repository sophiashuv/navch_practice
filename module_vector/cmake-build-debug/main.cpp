//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <iterator>
//#include <string>
////Варіант 4
////1. Дано вектор цілих чисел. Знайти кількість елементів, які є симетричними.
////2. Дано два вектори дійсних чисел. Утворити новий вектор з елементів першого вектора, які також
////містяться в другому векторі.
////3. Дано два ветори дійсних чисел. Перемістити частину другого ветора, обмежену максимальним і
////мінімальним елементами, після останнього від’ємного елемента першого вектора.
//using  namespace std;
//
//
//
///*
// * The function for filling vector with integers.
// */
//void fill_vec(vector<int> &vec){
//    cout << "Enter elements of vector or 'stop' to continue: ";
//    string e;
//    cin >> e;
//    while (e != "stop"){
//        vec.push_back(stoi(e));
//        cin >> e;
//    }
//}
//
//
///*
// * The function prints vector.
// */
//void show_vec(const vector<int> &vec) {
//    for(int el: vec) cout << el << " ";
//    cout << "\n";
//}
//
///*
// * The function inserts all elms between max and min if second vec after a last відємне rl of first.
// */
//void insert1( vector<int> &vec1, const vector<int> &vec2){
//    int min = 1000000;
//    int max = -100000;
//    size_t min_i = 0;
//    size_t max_i = 0;
//    for (size_t i = 0; i < vec2.size(); ++i) {
//        if (max < vec2[i]) {
//            max = vec2[i];
//            max_i = i;
//        }
//        if (min > vec2[i]) {
//            min = vec2[i];
//            min_i = i;
//        }
//    }
//    for (size_t i = vec1.size()-1; i >= 0; i--) {
//        if (vec1[i] < 0 && min_i < max_i){
//            vec1.insert(vec1.begin() + i + 1, vec2.begin() + min_i, vec2.begin() + max_i + 1);
//            break;
//        }
//        if (vec1[i] < 0 && max_i < min_i){
//            vec1.insert(vec1.begin() + i +1, vec2.begin() + max_i, vec2.begin() + min_i + 1);
//            break;
//        }
//        else cout << "ther's no min el \n";
//    }
//}
//
///*
// * The function checks whether int is a simetric or not.
// */
//bool check(int val){
//    int n = val, digit, rev = 0;
//    do {
//        digit = val % 10;
//        rev = (rev * 10) + digit;
//        val = val / 10;
//    } while (val != 0);
//    if (n == rev)
//        return true;
//    else
//        return false;
//
//}
//
///*
// * The function checks whether vector is a simetric or not.
// */
//int check_simetric(vector<int> &vec){
//    int amount = 0;
//    for (int el: vec){
//        if (check(el)) amount++;
//    }
//    return amount;
//}
//
///*
// * The function prints same elements in both vectors.
// */
//void task2(vector<int> a1, vector<int> a2) {
//    vector<int> b;
//    for (int el1: a1) {
//        bool f = false;
//        for (int el2: a2) {
//            if (el1 == el2) f = true;
//        }
//        if (f) b.push_back(el1);
//    }
//    show_vec(b);
//}
//// 1 2 3 4 1 -2 5 6 stop
////5 8 4 2 3 1 5 stop
//
////21 343 456 -787 67 1 4 6 stop
////7 67 21 1 7 456
//
//
//int main() {
//    vector<int> vec1;
//    vector<int> vec2;
//    cout << "Fill first vector!\n";
//    fill_vec(vec1);
//    cout << "Simetric elements: " << check_simetric(vec1) << "\n";
//    cout << "Fill second vector!\n";
//    fill_vec(vec2);
//    task2(vec1, vec2);
//    insert1(vec1, vec2);
//    show_vec(vec1);
//    return 0;
//}
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <list>
//Варіант 4
//1. Дано вектор цілих чисел. Знайти кількість елементів, які є симетричними.
//2. Дано два вектори дійсних чисел. Утворити новий вектор з елементів першого вектора, які також
//містяться в другому векторі.
//3. Дано два ветори дійсних чисел. Перемістити частину другого ветора, обмежену максимальним і
//мінімальним елементами, після останнього від’ємного елемента першого вектора.
using  namespace std;


void Line() {
    cout << "--------------------------------------------------------------------->" << endl;
}

void Print(list<int>& list_test) {
    for (int n : list_test) {
        cout << n << " ";
    }
    cout << endl;
}

void InsertNegative(list<int>& list_test) {
    list<int>::iterator i;
    size_t c = 0;
    list<int>::iterator counter = list_test.begin();
    for (list<int>::iterator i = list_test.begin(); i != list_test.end(); i++) {
        if (*i < 0 && i != list_test.begin()) {
            advance(i, c);
            list_test.erase(i);
            list_test.insert(counter, *i);
            i--;
        }
        c++;
    }
    cout << "List after transfering of negative elements to the front: " << endl;
    Print(list_test);
}

void Unique(list<int>& list_test) {
    int checker = list_test.size();
    list<int>::iterator i = list_test.begin();
    list<int>::iterator j = list_test.begin();
    for (i; i != list_test.end(); i++) {
        j = i;
        j++;
        for (j; j != list_test.end(); j++) {
            //cout << "i: " << *i << "j: " <<  *j << "\n";
            if(*j == *i) {
                list_test.erase(j--);
                //j--;
            }
        }
    }

//    for (list<int>::iterator i = list_test.begin(); i != list_test.end(); i++, counter1++) {
//        for (list<int>::iterator j = list_test.begin(); j != list_test.end(); j++, counter2++) {
//            if (*i == *j && counter2 > counter1) {
//                list_test.erase(i--);
//
//            }
//        }
//    }
//    if (checker == list_test.size()) {
//        cout << "There aren`t any numbers, which repeat" << endl;
//    }
    Print(list_test);
}

int main() {
    list<int> firstList;
    list<int> secondList;
    int size1, size2;
    cout << "Print amount of elements you want to push in first list: ";
    cin >> size1;
    cout << "Fill your list: ";
    for (size_t i = 0; i < size1; i++)
    {
        int number;
        cin >> number;
        firstList.push_back(number);
    }

    Unique(firstList);

    system("pause>>void");
}