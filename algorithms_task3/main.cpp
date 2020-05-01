#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cmath>

//        Зчитати з файлу список цілих чисел (кількість елементів не менша 10).
//        Використовуючи алгоритми та об’єкти-функції (або лямбда-вирази) виконати наступні дії :
//          1) збільшити всі елементи на парних позиціях на задане число;
//          2) замінити всі парні елементи на останній елемент послідовності;
//          3) видалити всі елементи, які є числами Фібоначчі;
//          4) перемістити всі елементи списку, які знаходяться між першим і останнім
//             симетричними елементами, на його початок, при цьому зберегти порядок інших елементів;
//          5) відсортувати всі елементи у порядку зростання за сумою цифр.
//        • Симетричні – числа-паліндроми, наприклад, 121, 88, 6, 54345

using namespace std;


/*
 * The function reads .txt file using istream_iterator.
 * Returns list of students.
 */
list<int> read_file(const string &file_name) {
    ifstream fin(file_name);
    if (fin) {
        istream_iterator<int> isiter(fin), pend;
        list<int> l(isiter, pend);
        return l;
    }
    else throw "File not open exception\n";
}


/*
 * The function writes a list of integers using
 * ostream_iterator
 */
void write(const list<int> &l, ostream &os) {
    ostream_iterator<int> ositer(os, " ");
    copy(l.begin(), l.end(), ositer);
}


/*
 * The function adds an input num to all elements on
 * even positions.
 */
void task1(list<int> &l) {
    int num;
    cout << "Enter number: ";
    cin >> num;
    int i = 0;
    for_each(l.begin(), l.end(), [&](int &el) {if (!(i % 2)) el += num; i++; });
}


/*
 * The function replaces all even elements of list with
 * last element.
 */
void task2(list<int> &l) {
    int k = l.back();
    for_each(l.begin(), l.end(), [&](int &el) {if (!(el % 2)) el = k; });
}


/*
 * The function removes all numbers of list that are
 * Fibonacci (if and only if 5N^2 + 4 or 5N^2 – 4 is a square number).
 */
void task3(list<int> &l) {
    l.erase(remove_if(l.begin(), l.end(), [](int &n) { int x = 5 * (int)pow(n, 2) + 4;
        return ((int)sqrt(x) * (int)sqrt(x) == x) || ((int)sqrt(x - 8) * (int)sqrt(x - 8) == x - 8); }), l.end());
}


struct is_Simetric {
    bool operator() (const int &el) {
        int x = el, rev = 0;
        while (x != 0) {
            rev = (rev * 10) + x % 10;
            x /= 10;
        }
        return el == rev;
    }
};


/*
 * The function moves range between first and last palindrome
 * number of list to begin.
 */
void task4(list<int> &l) {
    auto it1 = find_if(l.begin(), l.end(), is_Simetric());
    auto it2 = find_if(l.rbegin(), l.rend(), is_Simetric());
    if (it1 != l.end()) if(--it2.base() != it1) l.splice(l.begin(), l, ++it1, --it2.base());
}

/*
 * The function sort list compering sum of digits of elements.
 */
void task5(list<int> &l) {
    function<int(int)> sum = [&](int n) {return (n / 10 < 1) ? n : n % 10 + sum(n / 10);};
    stable_sort(l.begin(), l.end(), [&](const int& value1, const int& value2) {return sum(abs(value1)) < sum(abs(value2));});

    //l.sort([&](const int& value1, const int& value2) {return sum(abs(value1)) < sum(abs(value2)); });
}


int main() {
    list<int> l = read_file("/Users/sophiyca/ClionProjects/algorithms_task3/integers.txt");
    write(l, cout);

    auto func_vector = {task1, task2, task3, task4, task5};
    int i = 1;
    for_each(func_vector.begin(), func_vector.end(), [&l, &i](auto f){
        cout <<  "\n-----------------------------------\nTASK " << i << ":\n"; i++; f(l); write(l, cout); });
    system("pause");
    return 0;
}