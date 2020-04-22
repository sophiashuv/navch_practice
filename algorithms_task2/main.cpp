#include <iostream>
#include <list>
#include <fstream>
#include <cmath>
#include <functional>
#include <iterator>
#include <algorithm>

//    2.	Зчитати з файлу список цілих чисел (кількість елементів не менша 10).
//        Використовуючи алгоритми та об’єкти функцій виконати наступні дії та результати зберегти у файл:
//        1) піднести всі парні елементи до заданого степеня;
//        2) утворити новий список перемноживши відповідні елементи двох списків на парних позиціях та віднявши на непарних позиціях;
//        3) вивести всі можливі перестановки перших трьох елементів списку;
//        4) вилучити з послідовності дублікати за правилом: поруч не повинні знаходитись елементи які відрізняються на одиницю;
//        5) Згенерувати послідовність з заданою кількістю елементів на основі доданків ряду

using namespace std;


/*
 * The function reads .txt file using istream_iterator.
 * Returns list of students.
 */
list<int> read_file(const string &file_name){
    ifstream fin(file_name);
    if (fin) {
        istream_iterator<int> isiter(fin), pend;
        list<int> l(isiter, pend);
        return l;
    }
    else throw "File not open exception\n";
}


/*
 * The function writes a Container of Students using
 * ostream_iterator
 */
template <typename C, typename T>
void write(const C &l, ostream &os){
    ostream_iterator<T> ositer(os, " ");
    copy(l.begin(), l.end(), ositer);
}


/*
 * The function exponents all even elements.
 * And writes list in file.
 */
void pow_even(list<int> &l, ostream &os){
    int exp;
    cout << "\nEnter exponentiation: ";
    cin >> exp;
    for_each(l.begin(),l.end(), [&exp](int &el){if (!(el % 2)) el = (int)pow(el, exp);});
    write<list<int>, int>(l, os);
}

/*
 * 2) form new list by multiplying corresponding even elements from two
 * lists and subtracting odd elements.
 * And writes list in file.
 */
void new_list(list<int> &l, ostream &os){
    list<int> l2 = {1, 3, 4 ,6, 7, 5, 4, 67, 456, 1, 3, 4 ,6};
    list<int> result;
    write<list<int>, int>(l2, os);
    os << "\n";
    int index = -1;
    transform(l.begin(), l.end(), l2.begin(), back_inserter(result), [&index](const int &x, const int &y){
        index++;
        return (index % 2) ? x - y : x * y;});
    write<list<int>, int>(result, os);
}

/*
 * The function prints all possible permutations of first 3 elements of the list
 * And writes list in file.
 */
void permutations(list<int> &l, ostream &os){
    auto it = l.begin();
    advance(it, 3);
    function<int(int)> factorial = [&](int n){ return (n==1 || n==0) ? 1: n * factorial(n - 1);};
    int f = factorial(3);
    for (int i = 0; i < f; ++i) {
        os << *l.begin() << ' ' << *++l.begin() << ' ' << *++(++l.begin()) << '\n';
        next_permutation(l.begin(), it);
    }
}

/*
 * The function removes all duplicates according to the rule:
 * if the element differ by 1, they shouldn't be positioned
 * next to each other
 * And writes list in file.
 */
void remove_dublicates(list<int> &l, ostream &os){
    l.unique([&](int &a, int &b){ return abs(a - b) == 1;});
    write<list<int>, int>(l, os);
}

/*
 * The function generates new list based on rule in document.
 * And writes list in file.
 */
void generate_list(ostream &os){
    int n = 8;
    double x = 0.5;
    list<double > result(n);
    int i = -1;
    generate(result.begin(), result.end(), [&](){return ++i == 0 ? x: x += (pow(-1, i) * pow(x, (2 * i) + 1))/(2 * i + 1);});
    write<list<double>, double>(result, os);
}



int main() {
    list<int> l = read_file("/Users/sophiyca/ClionProjects/algorithms_task2/digits.txt");
    write<list<int>, int>(l, cout);
    ofstream myfile;
    myfile.open ("/Users/sophiyca/ClionProjects/algorithms_task2/result.txt");

    //  TASK1, TASK2, TASK3, TASK4
    auto func_v = {pow_even, new_list, permutations, remove_dublicates};
    int task = 1;
    for_each(func_v.begin(), func_v.end(), [&](auto el){
        myfile << "TASK " << task << "\n";
        el(l, myfile);
        myfile << "\n--------------------------\n\n";
        task++; });

    //      TASK5
    myfile << "TASK 5\n";
    generate_list(myfile);
    myfile << "\n--------------------------\n\n";

    return 0;
}