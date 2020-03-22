#include <iostream>
#include <forward_list>
//1.	Вставити у списку L після кожного елемента новий елемент Е.
//2.	Видалити зі списку L задану кількість елементів, починаючи із заданої позиції.
//3.	Поміняти місцями перший і останній елементи непорожнього списку L.
//4.	Видалити зі списку L після кожного елемента Е один елемент, якщо такий елемент існує і не дорівнює Е.
//5.	Вставити у вказану позицію списку L новий елемент Е.


using namespace std;

void showlist(forward_list <int> L) {
    forward_list <int> :: iterator it;
    for(it = L.begin(); it != L.end(); ++it) cout << '\t' << *it;
    cout << '\n';
}

void task1(forward_list <int> &L, string &e, size_t &size){
    cout << "-----------------task1-----------------\n";
    cout << "Enter elements of list to be added  or 'stop' to continue: ";
    auto it = L.cbegin();
    for (it; it != L.cend(); ++it){
        cin >> e;
        if (e == "stop") break;
        L.insert_after(it, stoi(e));
        size++;
        ++it;
    }
    showlist(L);
}

void task2(forward_list <int> &L, size_t &size){
    cout << "-----------------task2-----------------\n";
    int n, p;
    try {
        cout << "Enter num of elements to be poped: ";
        cin >> n;
        cout << "Enter position of first elements to be poped: ";
        cin >> p;
        if (n > size || p - 1 > size || n + p > size) throw "You entered wrong parameters!\n";
        forward_list<int>::iterator itr1, itr2;
        itr1 = L.begin();
        itr2 = L.begin();
        advance(itr1, p-1);
        advance(itr2, p+n);
        L.erase_after(itr1, itr2);
        size -= n;
        showlist(L);
    } catch(const char* &e) {
        cout << e;
    }
}

void task3(forward_list <int> &L, size_t &size){
    cout << "-----------------task3-----------------\n";
    auto i1 = L.begin();
    auto i2 = L.begin();
    advance(i2, size - 1);
    std::iter_swap(i1, i2);
    showlist(L);
}

void task4(forward_list <int> &L, size_t &size){
    cout << "-----------------task4-----------------\n";
    int elem;
    cin >> elem;
    auto it = L.cbegin();
    auto it2 = L.cbegin();
    ++it2;
    while (it2 != L.cend()){
        if (*it == elem && *it2 != elem) {
            ++it2;
            ++it2;
            it = L.erase_after(it);
            size--;

        }
        else {
            ++it;
            ++it2;
        }
    }
    showlist(L);
}

void task5(forward_list <int> &L, size_t &size){
    cout << "-----------------task5-----------------\n";
    int p, el;
    try {
        cout << "Enter position of element: ";
        cin >> p;
        cout << "Enter element: ";
        cin >> el;
        if (p - 1 > size) throw "You entered wrong parameters!\n";
        forward_list<int>::iterator itr1;
        itr1 = L.begin();
        advance(itr1, p-1);
        L.insert_after(itr1, el);
        size ++;
        showlist(L);
    } catch(const char* &e) {
        cout << e;
    }
}

int main() {
    size_t size = 0;
    forward_list<int> L;
    cout << "Enter elements of list or 'stop' to continue: ";
    string e;
    cin >> e;
    while (e != "stop"){
        L.push_front(stoi(e));
        size++;
        cin >> e;
    }
    showlist(L);
    task1(L, e, size);
    task2(L, size);
    task3(L, size);
    task4(L, size);
    task5(L, size);
    return 0;
}
