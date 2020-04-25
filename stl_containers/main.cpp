#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>
#include "Header.h"
#include <map>

//    Завдання 3.Розробити тип для задання опису комп’ютерiв за такими
//    атрибутами:назва фiрми, категорiя, тип процесора, iнвентарний номер,список додаткових комплектуючих.
//    Данi про комп’ютери заданi у файлi.Отримати уфайлi out.dat:
//      1. впорядкований за категорiями, типом процесора, назвою фiрми повний перелiк комп’ютерiв;
//      2. для кожної наявної категорiї перелiк комп’ютерiв кожної фiрми;
//      3. для кожної фiрми рейтинг додаткових комплектуючих.


/*
 * The function reads .txt file using istream_iterator.
 * Returns list of Computers.
 */
list<Computer> read_file(const string &file_name){
    ifstream fin(file_name);
    if (fin) {
        istream_iterator<Computer> isiter(fin), pend;
        list<Computer> computers(isiter, pend);
        fin.close();
        return computers;
    }
    else throw "File not open exception\n";
}


/*
 * The function writes a list of Computers using
 * ostream_iterator.
 */
void write_list(const list<Computer> &students, ostream &os, const char* ros){
    ostream_iterator<Computer> ositer(os, ros);
    copy(students.begin(), students.end(), ositer);
}


/*
 * The function writes a map ((map<string, list<Computer>>) using
 * ostream_iterator.
 */
void write_map_list(map<string, list<Computer>> m, ostream &os){
    for (auto it = m.begin(); it != m.end(); ++it) {
        os << it->first << " => ";
        write_list(it->second, os, "\n\t\t\t ");
        os << "\n";
    }
}


/*
 * The function writes a writes a map map<string, multimap<int, string>>  using
 * ostream_iterator.
 */
template <class T>
void write_map_multimap(map<string, multimap<int, string, T>> m, ostream &os){
    for (auto it = m.begin(); it != m.end(); ++it) {
        os << it->first << " => ";
        for (auto it2=it->second.begin(); it2!=it->second.end(); ++it2) {
            os << it2->first <<  " : " << it2->second << "\n\t\t ";
        }
        os << "\n";
    }
}


/*
 * The function returns a multimap of swaps keys and
 * values of the given map.
 */
template <class T1, class T2, class T3>
multimap<T2, T1, T3> swapPairs(map<T1, T2> m) {
    multimap<T2, T1, T3> m1;
    for (auto&& item : m) m1.emplace(item.second, item.first);
    return m1;
}


int main() {
    try {

        list<Computer> com_list = read_file("/Users/sophiyca/ClionProjects/stl_containers/data.txt");
        ofstream myfile;
        myfile.open ("/Users/sophiyca/ClionProjects/stl_containers/out.dat");

        // TASK
        myfile << "Table of all computers: \n";
        write_list(com_list, myfile, "\n");

        // TASK1
        myfile << "\nSorted by all criterias:\n";
        com_list.sort();
        write_list(com_list, myfile, "\n");

        myfile << "\nSorted by category:\n";
        com_list.sort([](const Computer& f, const Computer& s) {return (f.getCategory() < s.getCategory());});
        write_list(com_list, myfile, "\n");

        com_list.sort([](const Computer& f, const Computer& s) {return (f.getP_type() < s.getP_type());});
        myfile << "\nSorted by p_type:\n";
        write_list(com_list, myfile, "\n");

        com_list.sort([](const Computer& f, const Computer& s){ return (f.getFirm_name() < s.getFirm_name());});
        myfile << "\nSorted by firm_name:\n";
        write_list(com_list, myfile, "\n");

        com_list.sort([](const Computer& f, const Computer& s){ return (f.getNum() < s.getNum());});
        myfile << "\nSorted by num:\n";
        write_list(com_list, myfile, "\n");


        // TASK2
        map<string, list<Computer>> mymap;
        for (auto & el : com_list) mymap[el.getCategory()].push_back(el);

        myfile << "\nCategories for computer: \n";
        write_map_list(mymap, myfile);


        // TASK3
        map<string, map<string, int>> firm_map;
        map<string, multimap<int, string, greater <int>>> firm_map2;
        for (auto &el : com_list) {
            for (const auto & value : el.getDod_com()) firm_map[el.getFirm_name()][value] += 1;
            firm_map2[el.getFirm_name()] = swapPairs<string, int, greater <int>>(firm_map[el.getFirm_name()]);
        }

        myfile << "Task3: \n";
        write_map_multimap<greater <int>>(firm_map2, myfile);

    } catch (const char* ex) {
        cout << ex;
    }

    return 0;
}

