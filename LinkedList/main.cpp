#include <iostream>
#include <list>
//1.	Вставити у списку L після кожного елемента новий елемент Е.
//2.	Видалити зі списку L задану кількість елементів, починаючи із заданої позиції.

using namespace std;

void showlist(list <int> L) {
    list <int> :: iterator it;
    for(it = L.begin(); it != L.end(); ++it) cout << '\t' << *it;
    cout << '\n';
}

void task1(list <int> &L, string &e){
    cout << "-----------------task1-----------------\n";
    cout << "Enter elements of list to be added  or 'stop' to continue: ";
    cin >> e;
    list<int>::iterator it = L.begin();
    advance(it, 1);
    for (it; it != L.end(); it++){
        if (e == "stop") break;
        L.insert(it, stoi(e));
        cin >> e;
    }
    L.insert(it, stoi(e));
    showlist(L);
}

void task2(list <int> &L){
    cout << "-----------------task2-----------------\n";
    int n, p;
    try {
        cout << "Enter num of elements to be poped: ";
        cin >> n;
        cout << "Enter position of first elements to be poped: ";
        cin >> p;
        if (n > L.size() || p > L.size() || n+p > L.size()) throw "You entered wrong parameters!\n";
        list<int>::iterator itr1, itr2;
        itr1 = L.begin();
        itr2 = L.begin();
        advance(itr1, p);
        advance(itr2, p+n);
        L.erase(itr1, itr2);
        showlist(L);
    } catch(const char* &e) {
        cout << e;
    }
}

int main() {
    list<int> L;
    cout << "Enter elements of list or 'stop' to continue: ";
    string e;
    cin >> e;
    while (e != "stop"){
        L.push_back(stoi(e));
        cin >> e;
    }
    showlist(L);
    task1(L, e);
    task2(L);
    return 0;
}