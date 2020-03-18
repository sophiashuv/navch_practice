#include <iostream>
#include <list>

//1.	Дано два непорожніх двозв’язних списки L1 та L2 . Вставити всі елементи першого списку перед
//заданим елементом другого, зберігаючи порядок.

using namespace std;

void fill_list( list<int> &L){
    cout << "Enter elements of list or 'stop' to continue: ";
    string e;
    cin >> e;
    while (e != "stop"){
        L.push_back(stoi(e));
        cin >> e;
    }
}

void show_list(list <int> L) {
    list <int> :: iterator it;
    for(it = L.begin(); it != L.end(); ++it) cout << '\t' << *it;
}

int main() {
    list<int> L1; list<int> L2;
    cout << "Fill first list\n";
    fill_list(L1);
    cout << "Fill second list\n";
    fill_list(L2);
    cout << "Enter element:";
    int el;
    cin >> el;
    list <int> :: iterator it;
    for(it = L2.begin(); it != L2.end(); ++it) {
        if (*it == el) {
            list <int> :: iterator i;
            for(i = L1.begin(); i != L1.end(); ++i) L2.insert(it, *i);
        }
    }
    show_list(L2);
    return 0;
}