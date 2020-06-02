#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <map>
#include <algorithm>
using namespace std;

//    Завдання 1.
//    Розробити типи для вiдбору на навчання за результатами тестування.
//    Претенденти характеризуються прiзвищем, iменем та iдентифiкацiйним номером.
//    Тести є двох категорiй: базовi та спецiалiзованi. Базовi характеризу-ються
//    номером, назвою предмету та максимальною кiлькiстю балiв. Спецi-алiзованi тести крiм даних базових
//    мають ще максимальну кiлькiсть балiв за спецiальний роздiл. Данi учасникiв тестування i обох категорiй
//    тестiв задано у трьох окремих файлах вiдповiдно до категорiї.
//    Данi про тестування також задано в окремих файлах вiдповiдно до категорiї тестiв.Результатом базових тестiв в
//    важають вiдсоток набраних
//    балiв вiд максимального значення, а результатом спецiалiзованих тестiв – середнє арифметичне вiдсоткiв
//    обох частин (обчислюють окремо для кожної частини).
//     1. Отримати (у файлi) для кожного учасника перелiк предметiв з набраними балами.
//     2. Отримати (у файлi) у кожнiй з категорiй тестування для кожногопредмета рейтинг учасникiв.
//     3. Отримати (у файлi) для заданого перелiку номерiв тестiв сумарний рейтинг учасникiв.

class Pretendent {
protected:
    string name;
    string surname;
    int id_num;

public:
    Pretendent(){}

    friend istream & operator>>(istream & is, Pretendent & a) {
        is >> a.name >> a.surname >> a.id_num;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Pretendent & a) {
        os << "name: " << a.name << ", surname: " << a.surname << ", id_num: " << a.id_num  ;
        return os;
    }

    const string &getName() const {
        return name;
    }

    const string &getSurname() const {
        return surname;
    }

    int getId_num() const {
        return id_num;
    }
};

class Test_b {
protected:
    int t_num;
    string name;
    int max;


public:
    Test_b(){}

    friend istream & operator>>(istream & is, Test_b & a) {
        is >> a.t_num >> a.name >> a.max;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Test_b & a) {
        os << "t_num: " << a.t_num << ", name: " << a.name << ", max: " << a.max  ;
        return os;
    }

    int getT_num() const {
        return t_num;
    }

    const string &getName() const {
        return name;
    }

    virtual int getMax() const {
        return max;
    }

    virtual void print(){
        cout << "t_num: " << t_num << ", name: " << name << ", max: " << max;
    }

};



class Test_s: public Test_b {
protected:
    int max_s;

public:
    Test_s(){}

    friend istream & operator>>(istream & is, Test_s & a) {
        is >> (Test_b&)a;
        is >> a.max_s;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Test_s & a) {
        os << (Test_b&)a;
        os << ", transport: " << a.max_s;
        return os;
    };

    virtual void print() override{
        Test_b:: print();
        cout << ", transport: " << max_s;
    }

    int getMax_s() const {
        return max_s;
    }

    int getMax() const {
        return (max + max_s);
        //return (max + max_s)/2;
    }
};

//struct Points_b {
//
//    size_t pts;
//
//    friend istream& operator >> (istream& in, Points_b& o) {
//        return in >> o.pts;
//    }
//};
//struct Points_s {
//
//    size_t pts;
//    size_t sPts;
//
//    friend istream& operator >> (istream& in, Points_s& o) {
//        return in >> o.pts >> o.sPts;
//    }
//};
//
//template<typename test> struct ExamTraits;
//
//template<> struct ExamTraits<Test_b> {
//
//    using ptsType = Points_b;
//};
//
//template<> struct ExamTraits<Test_s> {
//
//    using ptsType = Points_s;
//};


//template<typename test, typename traits = ExamTraits<test>>
class Result {
protected:
   // using ptsType = typename traits::ptsType;

    int t_num;
    string p_name;
    int points;

public:
    Result(){}

    friend istream & operator>>(istream & is, Result & a) {
        is >> a.t_num >> a.p_name >> a.points;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Result & a) {
        os << "t_name: " << a.t_num << ", p_name: " << a.p_name << ", points: " << a.points  ;
        return os;
    }

    int getT_num() const {
        return t_num;
    }

    const string &getP_name() const {
        return p_name;
    }

    int getPoints() const {
        return points;
    }
};


template <typename T, typename K>
void read_file(const string &file_name, T &r){
    ifstream fin(file_name);
    if (fin) copy(istream_iterator<K>(fin), istream_iterator<K>(), back_inserter(r));
    else throw "File not open exception\n";
}

template<typename T, typename K>
void write_list(const T &r, ostream &os, const char* pend = "\n"){
    ostream_iterator<K> ositer(os, pend);
    copy(r.begin(), r.end(), ositer);
}

template<typename T, typename K>
void write_map_map(const map<T, K> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.first << " => ";
        for_each(el.second.begin(), el.second.end(), [&](const auto &e){os << e.first <<  " : "  << e.second << "\n\t   ";}); os << "\n";});
}

void task1(const vector<Pretendent> &pretendents, const vector<Test_b*> &all_tests, const vector<Result> &result){
    map<string, map <string, double>> m;
    for (auto &p: pretendents) {
        for (auto &t: all_tests) {
            for (auto &r: result) {
                if (r.getT_num() == t->getT_num() && r.getP_name() == p.getName()) m[p.getSurname()][t->getName()] += r.getPoints();
            }
        }
    }
    write_map_map<string, map <string, double>>(m, cout);
}


template <class T1, class T2, class T3>
multimap<T2, T1, T3> swapPairs(map<T1, T2> &m) {
    multimap<T2, T1, T3> m1;
    for (auto&& item : m) m1.emplace(item.second, item.first);
    m.clear();
    return m1;
}

//2. Отримати (у файлi) у кожнiй з категорiй тестування для кожного предмета рейтинг учасникiв.
void task2(const vector<Pretendent> &pretendents, const vector<Test_b> &tests1, const vector<Test_s> &tests2, const vector<Result> &result){
    map<string, multimap <double, string, greater<double>>> m1;
    map<string, multimap <double, string, greater<double>>> m2;

    map<string, map <string, double>> mmm1;
    map<string, map <string, double>> mmm2;

    for (auto &r: result) {
        for (auto &p: pretendents) {
            for (auto &t: tests1){
                if (r.getT_num() == t.getT_num() && r.getP_name() == p.getName()) {
                    mmm1[t.getName()][p.getSurname()] += (r.getPoints() * 100) / t.getMax();
                }
            }
            for (auto &t: tests2){
                if (r.getT_num() == t.getT_num() && r.getP_name() == p.getName()) {
                    mmm2[t.getName()][p.getSurname()] += (r.getPoints() * 100) / t.getMax();
                }
            }
        }
    }
    for (auto el: mmm1){
        m1[el.first] = swapPairs<string, double, greater<double>>(el.second);
    }
    for (auto el: mmm2){
        m2[el.first] = swapPairs<string, double, greater<double>>(el.second);
    }

    cout << "Normal:\n";
    write_map_map<string,  multimap<double, string, greater<double>>>(m1, cout);
    cout << "\n---------------------------\n";
    cout << "Special:\n";
    write_map_map<string,  multimap<double, string, greater<double>>>(m2, cout);
}

//3. Отримати (у файлi) для заданого перелiку номерiв тестiв сумарнийрейтинг учасникiв.
void task3(const vector<Pretendent> &pretendents, const vector<Test_b*> &all_tests, const vector<Result> &result){
//    map<int, map <double, string, greater<double>>> m;
//    vector<int> perelic; int e;
//    cin >> e;
//    while (!cin.fail()) {
//        perelic.push_back(e);
//        cin >> e;
//    }
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // This line ignores the rest of the current line, up to '\n'
//    for (auto &tt: perelic){
//        for (auto &t: all_tests){
//            for (auto &p: pretendents) {
//                for (auto &r: result) {
//                    if (r.getT_num() == tt && r.getP_name() == p.getName() && tt == t->getT_num())
//                        m[tt][(r.getPoints() * 100) / t->getMax()] = p.getSurname();
//                }
//            }
//        }
//    }
//    write_map_map<int, map <double, string, greater<double>>>(m, cout);

    map<string, double> m1;
    for (auto &t: all_tests) {
        for (auto &p: pretendents) {
            for (auto &r: result) {
                if(r.getP_name() == p.getName() && t->getT_num() == r.getT_num())
                m1[p.getName()] += (r.getPoints() * 100) / t->getMax();
            }
        }
    }
    multimap<double, string, greater<double>> m2 = swapPairs<string, double, greater<double>>(m1);
    for_each(m2.begin(), m2.end(), [&](const auto &el){cout << el.second << " => " << el.first << "\n";});


}

int main() {
//    for (int i = 0; i < 11; ++i) {
//        cout << "Test_b" << i << " Name" << rand() % 9 << " " << rand() % 100 <<" " <<  rand() % 100 << "\n";
//    }

    vector<Pretendent> pretendents;
    vector<Test_b> tests1;
    vector<Test_s> tests2;
    vector<Test_b*> all_tests;
    vector<Result> result;
    read_file<vector<Pretendent>, Pretendent>("/Users/sophiyca/ClionProjects/ex_pr3/pretendents.txt", pretendents);
    read_file<vector<Test_b>, Test_b>("/Users/sophiyca/ClionProjects/ex_pr3/tasts.txt", tests1);
    read_file<vector<Test_s>, Test_s>("/Users/sophiyca/ClionProjects/ex_pr3/tests2.txt", tests2);
    read_file<vector<Result>, Result>("/Users/sophiyca/ClionProjects/ex_pr3/tests1_res.txt", result);
    read_file<vector<Result>, Result>("/Users/sophiyca/ClionProjects/ex_pr3/test2_res.txt", result);
    for (int i = 0; i < tests1.size(); i++) all_tests.push_back(&tests1[i]);
    for (int i = 0; i < tests2.size(); i++) all_tests.push_back(&tests2[i]);

    //write_list<vector<Result>, Result>(result, cout);

    task1(pretendents, all_tests, result);
    cout << "\n---------------------------\n";
    task2(pretendents, tests1, tests2, result);
    cout << "\n---------------------------\n";
    task3(pretendents, all_tests, result);

    return 0;
}