#include <iostream>
#include <fstream>
#include <iterator>
#include <set>
#include <map>

//        Виконати завдання, використовуючи асоціативні контейнери stl.
//        1. Дано текст з малих латинських літер, слова відокремлені пропусками, в кінці крапка. Вивести
//           в алфавітному порядку ті голосні, які є в кожному слові.
//        2. В текстовому файлі знаходяться дані про собак в такому форматі: порода- кличка ( і породи і
//           клички можуть повторюватись). Зчитати дані у контейнер, вивести на консоль для кожної породи
//           список кличок собак цієї породи(у алфавітному порядку). Видалити з контейнера всіх собак із
//           заданою кличкою.

using namespace std;


/*
 * The function prints a set of char
 */
template <typename T>
void write(const T &w){
    if (w.empty()) cout << "Empty container";
    else for (auto it = w.begin(); it != w.end(); ++it) cout << *it << ' ';
    cout << '\n';
}


/*
 * The function prints a map (map<string, set<string>>).
 */
void write(const map<string, set<string>> &m){
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << " => ";
        write(it->second);
    }
}


/*
 * The function reads text from file and leaves in set vowels only those
 * vowels that occures in all words.
 */
void task1(const string &file_name, set<char> &vowels){
    ifstream fin(file_name);
    set<char>word;

    if (fin) {
        char c;
        while (!fin.eof( )) {
            fin.get(c);
            if (vowels.empty() || c == '.') break;
            if (c == ' ') {
                for (auto it = vowels.begin(); it != vowels.end();)
                    if (word.find(*it) == word.end()) it = vowels.erase(it);
                    else ++it;
                word.clear();
            }
            word.insert(c);
        }
    }
    else throw "File not open exception\n";
}


/*
 * The function reads dogs from file, fills a map with dogs breeds
 * and dogs names.
 */
void task2(const string &file_name,  map<string, set<string>> &m){
    ifstream fin(file_name);
    if (fin) {
        string breed;
        string name;
        while (fin >> breed >> name) m[breed].insert(name);
    }
    else throw "File not open exception\n";
}


/*
 * The function deletes an input dog name.
 */
void task3(map<string, set<string>> &m){
    string name;
    cout << "\nEnter dog name which to erase: ";
    cin >> name;
    for (auto it = m.begin(); it != m.end();) {
        if (it->second.find(name) != it->second.end()) {
            if (it->second.size() == 1) it = m.erase(it);
            else {
                it->second.erase(name);
                ++it;
            }
        } else ++it;
    }
}


int main() {
    try{

        // TASK1
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        task1("/Users/sophiyca/ClionProjects/stl_map/text.txt", vowels);
        cout << "Common vowels are: ";
        write(vowels);

        // TASK2
        map<string, set<string>> m;
        task2("/Users/sophiyca/ClionProjects/stl_map/dogs.txt", m);
        cout << "\nMap of dogs: \n";
        write(m);

        // TASK3
        task3(m);
        cout << "Map of dogs with a deleted dog name: \n";
        write(m);

    } catch (const char* ex) {
        cout << ex;
    }

    return 0;
}
