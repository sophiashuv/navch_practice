#include <iostream>
#include <list>
#include <string>
#include <iterator>

//Виконане завдання завантажити у вигляді одного файлу .cpp
//Утворити і заповнити з клавіатури 2 списки цілих чисел. Виконати наступні дії (не використовуючи алгоритми)
//- видалити з першого списку повторні входження елементів;
//- вставити у перший список перед першим від'ємним елементи другого списку,
//- усі від'ємні елементи першого списку перенести на його початок, зберігаючи їх порядок,
//- видалити з другого списку елементи, що містяться між максимальним і мінімальним елементами.

using namespace std;


/*
 * The function for filling list with integers.
 */
void fill_lst(list<int> &lst) {
    cout << "Enter elements of vector or 'stop' to continue: ";
    string e;
    cin >> e;
    while (e != "stop") {
        lst.push_back(stoi(e));
        cin >> e;
    }
}


/*
 * The function prints list.
 */
void show_lst(const list<int> &lst) {
    for (int el : lst) cout << el << " ";
    cout << "\n";
}


/*
 * The function erases all elements that occurres more than once.
 */
void unique(list<int> &lst) {
    for (auto it1 = lst.begin(); it1 != lst.end(); it1++) {
        for (auto it2 = next(it1, 1); it2 != lst.end(); it2++) {
            if (*it1 == *it2) {
                lst.erase(it2--);
            }
        }
    }
}


/*
 * The function inserts all elements of the second vector before a
 * first negative element of the first one.
 */
void insert_l2(list<int> &l1, const list<int> &l2) {
    for (auto it = l1.begin(); it != l1.end(); it++) {
        if (*it < 0) {
            l1.insert(it, l2.begin(), l2.end());
            break;
        }
    }
}


/*
 * The function moves all negative numbers to begin of the vector,
 * saving their location.
 */
void move_negative(list<int> &lst) {
    size_t c = 0;
    auto it = lst.end();
    while (c < lst.size()) {
        it--;
        if (*it < 0) {
            lst.push_front(*it);
            lst.erase(it--);
            it++;
        }c++;
    }
}


/*
 * The function erases all elements of list located before max
 * amd min elements of this list
 */
void remove(list<int> &lst) {
    auto min = lst.begin(), max = lst.begin();
    size_t min_i = 0, max_i = 0, i = 0;
    for (auto it = lst.begin(); it != lst.end(); it++) {
        if (*max < *it) {
            max = it;
            max_i = i;
        }
        if (*min > *it) {
            min = it;
            min_i = i;
        }
        i++;
    }
    lst.erase(++(max_i < min_i ? max : min), max_i > min_i ? max : min);
}


/*e.g input:
 * 1 2 -2 2 3 2 -2 4 -4 -3 3 3 3 2 stop
 * 1 3 4 10 3 stop
 */
int main() {
    list<int> l1 = { 1, 2, -2, 2, 3, 2, -2, 4, -4, -3, 3, 3, 3, 2 };
    list<int> l2 = { 1, 3, 4, 10, 3 };
    //    cout << "Fill first list!\n";
    //    fill_lst(l1);
    //    cout << "Fill second list!\n";
    //    fill_lst(l2);
    cout << "Lists after deleting same elements of the first list:\n";
    unique(l1);
    show_lst(l1);
    show_lst(l2);
    cout << "Lists after insertion all elements of the second lis before a first "
            "negative element of the first one:\n";
    insert_l2(l1, l2);
    show_lst(l1);
    show_lst(l2);
    cout << "Lists after moving all negative elements to begin of the first list:\n";
    move_negative(l1);
    show_lst(l1);
    show_lst(l2);
    cout << "Lists after erasing all elements of the second list between max and min:\n";
    remove(l2);
    show_lst(l1);
    show_lst(l2);
    system("pause");
    return 0;
}