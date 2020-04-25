#include <iostream>
#include <fstream>
#include <map>

//        2.	Використати контейнер map або multimap для зберігання автобусних рейсів
//        (ключ – номер автобуса, значення – прізвище водія та номер маршруту).
//        Реалізувати наступне: введення даних з файлу; виведення всіх елементів контейнера на екран;
//        видалення та модифікацію елементів контейнера; пошук за номером автобуса та за прізвищем водія.

using namespace std;


/*
 * The function reads .txt file. and fills vector with words.
 */
void read_file(const string &file_name, map<string, pair<string, int>> &my_map){
    ifstream fin(file_name);
    if (fin) {
        string number;
        string surname;
        int num;
        while (fin >> number >> surname >> num){
            my_map[number] = pair<string, int>(surname, num);
        }
    }
    else throw "File not open exception\n";
}

/*
 * The function writes a mapmap<string, pair<string, int>>.
 */
void write_map(map<string, pair<string, int>> &my_map){
    for (auto it = my_map.begin(); it != my_map.end(); ++it) {
        cout << it->first << " => " << it->second.first << " : " << it->second.second << "\n";
    }
}


/*
 * The function modifies a map<string, pair<string, int>> by key.
 */
void modification(map<string, pair<string, int>> &my_map){
    cout << "\nModify: \nEnter number from file which to modify:\n";
    string number;
    cin >> number;
    cout << "Enter new surname and num:\n";
    string surname;
    int num;
    cin >> surname >> num;
    my_map[number] =  pair<string, int>(surname, num);
}


/*
 * The function erases an item from map<string, pair<string, int>> by key.
 */
void remove_item(map<string, pair<string, int>> &my_map){
    cout << "\nErase: \nEnter number from file which to Erase:\n";
    string number;
    cin >> number;
    my_map.erase(number);
}

/*
 * The search an item from map<string, pair<string, int>> by key.
 */
void search_by_number(map<string, pair<string, int>> &my_map){
    cout << "\nSearch by number: \nEnter number from file which to Search:\n";
    string number;
    cin >> number;
    auto it = my_map.find(number);
    if (it != my_map.end()) cout << it->first << " => " << it->second.first << " : " << it->second.second << "\n";
    else cout << "There's no such number!";
}

/*
 * The search an item from map<string, pair<string, int>> by first
 * parameter in a value.
 */
void search_by_surname(map<string, pair<string, int>> &my_map){
    cout << "\nSearch by surname: \nEnter surname from file which to Search:\n";
    string surname;
    cin >> surname;
    auto it = find_if(my_map.begin(), my_map.end(), [surname](const auto& m) {return m.second.first == surname;});
    if(it != my_map.end()) cout << it->first << " => " << it->second.first << " : " << it->second.second << "\n";
    else cout << "There's no such surname!";
}


int main() {
    try {
        map<string, pair<string, int>> my_map;
        read_file("/Users/sophiyca/ClionProjects/stl_miltimap/Data.txt", my_map);
        write_map(my_map);

        // MODIFICATION
        modification(my_map);
        write_map(my_map);

        // REMOVAL
        remove_item(my_map);
        write_map(my_map);

        // SEARCH1
        search_by_number(my_map);

        // SEARCH2
        search_by_surname(my_map);

    } catch (const char* ex) {
        cout << ex;
    }
    return 0;
}