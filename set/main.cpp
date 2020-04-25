#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

//        22.	Дано текст з латинських букв, що закінчується крапкою. Надрукувати в алфавітном
//        у порядку (по одному разу) всі приголосні букви, які входять лише в одне слово;
//        всі голосні (a, e, i, o, u), які зустрічаються хоча б в одному слові не менше двох разів.

using namespace std;


/*
 * The function reads .txt file. and fills vector with words.
 */
void read_file(const string &file_name, vector<string> &words){
    ifstream fin(file_name);
    if (fin) {
        string word;
        while (fin >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            words.push_back(word);
        }
    }
    else throw "File not open exception\n";
}


/*
 * The function prints a set of char
 */
void write(const set<char> &w){
    for (auto it = w.begin(); it != w.end(); ++it) cout << *it << ' ';
    cout << '\n';
}


/*
 * The function returns set of chars that occure only in one word.
 */
set<char> task1(const vector<string> &words, const set<char> &vowels, const set<char> &punctuation){
    set<char> result;
    set<char> consonants;
    for (auto word: words) {
        set <char>set_w (begin(word), end(word));
        for (auto s: set_w) {
            if(vowels.find(s) == vowels.end() && punctuation.find(s) == punctuation.end()) {
                if(consonants.find(s) != consonants.end()) result.erase(s);
                else {
                    consonants.insert(s);
                    result.insert(s);
                }
            }
        }
    } return result;
}


/*
 * The function returns set of chars that occure at least at one word more tham two times.
 */
set<char> task2(const vector<string> &words, const set<char> &vowels){
    set<char> result;
    for_each(vowels.begin(), vowels.end(), [&](auto &vowel){for_each(words.begin(), words.end(),
            [&vowel, &result](auto &word){if (count(word.begin(), word.end(), vowel) >= 2) result.insert(vowel);});});
    return result;
}


int main(){
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    set<char> punctuation = {',', '.', '(', ')', '[', ']', '\''};
    vector<string> words;
    read_file("/Users/sophiyca/ClionProjects/set/Text.txt", words);

    //TASK1
    set<char> result = task1(words, vowels, punctuation);
    cout << "Task1:\n";
    write(result);

    //TASK2
    result = task2(words, vowels);
    cout << "\nTask2:\n";
    write(result);

    return 0;
}