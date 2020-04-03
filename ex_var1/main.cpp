#include <iostream>
#include <string>
#include <fstream>
#include "VipCard.h"
#include <vector>

using namespace std;


template <typename T>
vector<T> max_sum(const vector<T> vec){
    vector<T> maximals;
    T max;
    for(T el: vec) if (el.is_bigger(max)) max = el;
    for(T el: vec) if (el == max) maximals.push_back(el);
    return maximals;
}


template <typename T>
void read_file(const string &file_name, vector<T> &c){
    ifstream myfile(file_name);
    if (myfile.is_open()) {
        T el;
        while (myfile >> el) c.push_back(el);
    }
    else cout << "Unable to open file";
}


double VipCard::percentage = 0.7;

int main() {
    cout << "\n-------------------------task1------------------------------------------\n";
    int n;
    cout << "Enter amount: ";
    cin >> n;
    Card el;
    vector<Card> first_vec;
    for ( int i = 0; i < n; i++) {
        cin >> el;
        first_vec.push_back(el);
    }
    cout << "Cards are: \n";
    for (Card el: first_vec) {
        el.print();
        cout << "\n";
    }
    vector <Card> max =  max_sum<Card>(first_vec);
    cout << "\nMax sum is: \n";
    for (Card el: max) {
        el.print();
        cout << "\n";
    }

    //-------------------------------------------------------------------------
    cout << "\n-------------------------task2------------------------------------------\n";

    vector<GoldCard> second_vec;
    read_file<GoldCard>("/Users/sophiyca/ClionProjects/ex_var1/goldcard", second_vec);
    cout << "\nGold cards: \n";
    for (GoldCard el: second_vec) {
        el.print();
        cout << " --- " << el.sum_of_two() << "\n";
    }

    vector <GoldCard> max2 =  max_sum<GoldCard>(second_vec);
    cout << "\nMax sum is: \n";
    for (GoldCard el: max2) {
        el.print();
        cout << " --- " << el.sum_of_two() << "\n";
    }

    //-------------------------------------------------------------------------
    cout << "\n-------------------------task3------------------------------------------\n";

    vector <VipCard> third_vec;
    read_file<VipCard>("/Users/sophiyca/ClionProjects/ex_var1/vipcard", third_vec);

    size_t size1 = first_vec.size(), size2 = second_vec.size(), size3 = third_vec.size();
    vector <Card*> all_cards;
    for (int i = 0; i < size1; i++) all_cards.push_back(&first_vec[i]);
    for (int i = 0; i < size2; i++) all_cards.push_back(&second_vec[i]);
    for (int i = 0; i < size3; i++) all_cards.push_back(&third_vec[i]);

    Card * new_max = new Card;
    for(Card * el: all_cards){
        if(el->sum_of_two()>new_max->sum_of_two()) new_max = el;
        el->print();
        cout <<  " --- " << el->sum_of_two() << "\n";
    }

    for(Card *el: all_cards) if(el->sum_of_two() == new_max->sum_of_two())
        cout << new_max->GetNumber() << "---" << new_max->sum_of_two() << "\n";

    return 0;
}