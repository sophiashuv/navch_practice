#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;


/*
 * The function for filling vector with integers.
 */
void fill_vec(vector<int> &vec){
    cout << "Enter elements of vector or 'stop' to continue: ";
    string e;
    cin >> e;
    while (e != "stop"){
        vec.push_back(stoi(e));
        cin >> e;
    }
}


/*
 * The function prints vector.
 */
void show_vec(const vector<int> &vec) {
    for(int el: vec) cout << el << " ";
    cout << "\n";
}


/*
 * The function checks whether vector is a palindrome or not.
 */
bool check_palindrome(const vector<int> &vec){
    size_t size = vec.size();
    for (size_t i = 0; i < size/2; ++i) {
        if (vec[i] != vec[size-1-i]) return false;
    } return true;
}


/*
 * The function prints all elements of vector that occurred
 * more than once.
 */
void many(const vector<int> &vec){
    vector<int> many;
    bool is = false;
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (vec[i] == vec[j]) {
                for (int el: many) if (el == vec[i]) is = true;
                if (!is) {
                    many.push_back(vec[i]);
                    cout << vec[i] << " ";
                }
                is = false;
            }
        }
    } cout << "\n";
}


/*
 * The function deletes all elements of the first vector that
 * occurres also in the second one.
 */
void delete_same(vector<int> &vec1, const vector<int> &vec2){
    for (int i = 0; i < vec2.size(); ++i) {
        for (int j = 0; j < vec1.size(); ++j) {
            if (vec1[j] == vec2[i]) {
                vec1.erase(vec1.begin() + j);
                j--;
            }

        }

    }

}


/*
 * The function inserts all elements of the second vector before
 * the max element of the first one.
 */
void insertion(vector<int> &vec1, const vector<int> &vec2){
    int max = 0; size_t ind_max = 0;
    for (size_t i = 0; i < vec1.size(); ++i) {
        if (max < vec1[i]) {
            max = vec1[i];
            ind_max = i;
        }
    } vec1.insert(vec1.begin() + ind_max, vec2.begin(), vec2.end());
}



int main() {
    vector<int> vec1;
    vector<int> vec2;
    cout << "Fill first vector!\n";
    fill_vec(vec1);
    cout << "Fill second vector!\n";
    fill_vec(vec2);
    if (check_palindrome(vec1)) cout << "First vector is a palindrome\n";
    else cout << "First vector is not a palindrome\n";
    cout << "All elements of second vector that occurres more than one time: ";
    many(vec2);
    cout << "Vectors after deleting same elements from the first vector: \n";
    delete_same(vec1, vec2);
    cout << "First vector: ";
    show_vec(vec1);
    cout << "Second vector: ";
    show_vec(vec2);
    cout << "Vectors after insertion all elements of the second vector before max element of the first one: \n";
    insertion(vec1, vec2);
    cout << "First vector: ";
    show_vec(vec1);
    cout << "Second vector: ";
    show_vec(vec2);
    return 0;
}

// 1 1 2 2 3 4 5 6 6 6 7 8 stop
// 1 1 11 14 2 12 6 8 12 2 stop

//1 1 2 3 4 stop
//1 5 3 stop
