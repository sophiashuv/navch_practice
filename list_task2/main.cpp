#include <iostream>
#include <list>
#include <iterator>

//      7.	Написати програму для роботи з ланцюговим двозв’язним списком. Реалізувати наступні операції над списком:
//      •	Знайти номер найменшого елемента списку;
//      •	Вставити в список новий елемент Е1 перед першим входженням елемента Е;
//      •	Додати в кінець списку L1 всі елементи списку L2.

using namespace std;


/*
 * The function for filling list with integers.
 */
void fill_lst(list<int> &lst) {
    cout << "Enter elements of vector or any other char to stop: ";
    int e;
    cin >> e;
    while (!cin.fail()) {
        lst.push_back(e);
        cin >> e;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // This line ignores the rest of the current line, up to '\n'.
}


/*
 * The function prints list.
 */
void show_lst(const list<int> &lst) {
    for (int el : lst) cout << el << " ";
    cout << "\n";
}


/*
 * The function finds index of the minimem list element
 */
size_t min_i(list<int> &lst) {
    auto min = lst.begin();
    size_t min_i = 0, i = 0;
    for (auto it = lst.begin(); it != lst.end(); it++) {
        if (*min > *it) {
            min = it;
            min_i = i;
        }
        i++;
    }
    return min_i;
}


/*
 * The function inserts one input element before another
 */
void insert(list<int> &l1) {
    int e, e1;
    cout << "Enter element before which insert: ";
    cin >> e;
    cout << "Enter element which to insert: ";
    cin >> e1;
    for (auto it = l1.begin(); it != l1.end(); it++)
        if (*it == e) l1.insert (it, e1);
    show_lst(l1);
}


/*
 * The function inserts l2 in the end of l1
 */
void insert_l2(list<int> &l1) {
    list<int> l2 = { 1, 3, 4, 10, 3 };
    //fill_lst(l2);
    l1.insert(l1.end(), l2.begin(), l2.end());
    show_lst(l1);
}


int main() {
    list<int> l1 = { 1, 2, -2, 2, 3, 2, -2, 4, -4, -3, 3, 3, 3, 2 };
    //fill_lst(l1);

    cout << "Min element is on position: " << min_i(l1) << endl;

    cout << "List after insertion: \n";
    insert(l1);

    cout << "List after insertion all element of second list in the end: \n";
    insert_l2(l1);

    return 0;
}