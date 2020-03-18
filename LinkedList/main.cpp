#include <iostream>
#include <forward_list>
//1.	Вставити у списку L після кожного елемента новий елемент Е.
//2.	Видалити зі списку L задану кількість елементів, починаючи із заданої позиції.

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
    return 0;
}
