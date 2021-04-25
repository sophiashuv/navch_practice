#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;


/*
 * The function for filling list with integers.
 */
void fill_lst(list<int> &lst) {
    cout << "Enter elements of list or any other char to stop: ";
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


void task1(list<int> &lst) {
    auto first = lst.front();
    lst.pop_front();
    lst.push_back(first);
    show_lst(lst);
}

/*
 * The function inserts first el of list at ut's end
 */
void task2(list<int> &lst) {
    int el;
    cout << "Enter el: ";
    cin >> el;
    int first_ind = 0;
    auto last_ind = lst.size() - 1;

    auto it1 = lst.begin();
    auto it2 = lst.rbegin();
    for (;it1 != lst.end(); it1++, first_ind++) {
        if (*it1 == el) {
            break;
        }
    }
    for (;it2 != lst.rend(); it2++, last_ind--) {
        if (*it2 == el) {
            break;
        }
    }

    if (first_ind != last_ind){
        reverse(it1, (it2++).base());
    }

    show_lst(lst);
}


void task3(list<int> &l1) {
    list<int> l2 = { 1, 3, 4, 10, 3 };
    //fill_lst(l2);

    int el;
    cout << "Enter el: ";
    cin >> el;

    auto it1 = l1.begin();
    for (;it1 != l1.end(); it1++) {
        if (*it1 == el) {
            l1.insert(++it1, l2.begin(), l2.end());
            break;
        }
    }
    show_lst(l1);
}



int main() {
    list<int> l1 = { 1, 2, -2, 2, 3, 2, -2, 4, -4, -3, 3, 3, 3, 2 };
    show_lst(l1);
//    fill_lst(l1);

    cout << "Task1: ";
    task1(l1);

    cout << "Task2: \n";
    task2(l1);

    cout << "Task3: \n";
    task3(l1);


    return 0;
}