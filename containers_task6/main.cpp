#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <algorithm>
#include "Movie.h"

//        Розробити тип для задання опису фільмів за такими атрибутами:
//        назва фільму, жанр, режисер, кіностудія, список акторів.
//        Дані про фільми задано у файлі. Вивести:
//            1)впорядкований за жанром, кіностудією, назвою повний перелік усіх фільмів;
//            2)для кожної наявної категорії перелік назв фільмів кожного режисера;
//            3)рейтинг акторів, які задіяні у фільмах заданого жанру.

/*
 * The function reads .txt file using istream_iterator.
 * Returns list of Movies.
 */
void read_file(const string &file_name, list<Movie> &r){
    ifstream fin(file_name);
    if (fin) copy(istream_iterator<Movie>(fin), istream_iterator<Movie>(), back_inserter(r));
    else throw "File not open exception\n";
}


/*
 * The function writes a list using ostream_iterator.
 */
template<typename T, typename K>
void write_list(const T &r, ostream &os, const char* pend = "\n"){
    ostream_iterator<K> ositer(os, pend);
    copy(r.begin(), r.end(), ositer);
}


/*
 * The function writes a map <string,map<string, list<string>>>
 * ostream_iterator.
 */
void write_map_map_list(const map<string,map<string, list<string>>> &m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){os << el.first << " => ";
        for_each(el.second.begin(), el.second.end(), [&](const auto &e){os << e.first <<  " : " ;
        write_list<list<string>, string>(e.second, os, " ");cout << "\n\t\t   ";}); os << "\n";});
}

/*
 * The function writes a writes a map map<string, multimap<int, string>>  using
 * ostream_iterator.
 */
template <class T>
void write_map_multimap(map<string, multimap<int, string, T>> m, ostream &os){
    for_each(m.begin(), m.end(), [&](const auto &el){ os << el.first << " => "; for_each(el.second.begin(), el.second.end(),
            [&](const auto &e){os << e.second <<  " : " << e.first << "\n\t\t   ";});  os << "\n";});
}

/*
 * The function returns a multimap of swaped keys and
 * values of the given map.
 */
template <class T1, class T2, class T3>
multimap<T2, T1, T3> swapPairs(const map<T1, T2> &m) {
    multimap<T2, T1, T3> m1;
    for (auto&& item : m) m1.emplace(item.second, item.first);
    return m1;
}

/*
 * The function sorts list and prints sorted list
 */
void task1(list<Movie> &movies){
    movies.sort();
    write_list<list<Movie>, Movie>(movies, cout);
}

/*
 * The function fills a map and print for all genres
 * list of all films of all directors
 */
void task2(list<Movie> &movies){
    map<string,map<string, list<string>>> map1;
    for (auto &el : movies) map1[el.getGenre()][el.getDirector()].push_back(el.getMovie_name());
    write_map_map_list(map1, cout);
}

/*
 * The function fills a map and print rating of all
 * actors for all genres.
 */
void task3(list<Movie> &movies){
    map<string, map<string, int>> map3;
    map<string, multimap<int, string, greater <int>>> map2;
    for (auto &el : movies) {
        for (const auto & value : el.getActors()) map3[el.getGenre()][value] += 1;
        map2[el.getGenre()] = swapPairs<string, int, greater <int>>(map3[el.getGenre()]);
    }
    write_map_multimap<greater <int>>(map2, cout);
}

int main() {
    try {
        list<Movie> movies;
        read_file("/Users/sophiyca/ClionProjects/containers_task6/movies.txt", movies);
        write_list<list<Movie>, Movie>(movies, cout);
        auto func = {task1, task2, task3};
        int i = 1;
        for_each(func.begin(), func.end(), [&movies, &i](const auto &el) { cout << "\nTASK " << i++ << "\n";el(movies);});
    } catch (const char* ex) {
        cout << ex;
    }
    system("pause");
    return 0;
}