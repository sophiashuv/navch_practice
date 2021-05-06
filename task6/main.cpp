#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const vector<char> vowels = { 'a', 'o', 'u', 'e', 'i', 'y' };

vector<string> input_text() {
    cout << "Enter text: ";
    vector<string> text = vector<string>();
    string word = " ";
    while (word[word.length() - 1] != '.') {
        cin >> word;
        text.push_back(word);
    }

    auto last_word = text[text.size() - 1];
    last_word.pop_back();
    text[text.size() - 1] = last_word;
    return text;
}

void count_vovels_percentage(string word) {
    int num_vowels = count_if(word.begin(), word.end(),
        [&](char i) {return find(vowels.begin(), vowels.end(), i) != vowels.end(); });

    double percentage = (double)num_vowels * 100 / word.length();
    cout << word << " : " << percentage << "%\n";
}

int main() {
    vector<string> text = input_text();
    for_each(text.begin(), text.end(), [&](string word) {count_vovels_percentage(word); });
    return 0;
}
