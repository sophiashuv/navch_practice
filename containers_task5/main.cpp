#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include "Header.h"

//    Розробити клас Книга (назва, автор, кількість сторінок, рік видання, ціна)
//    Використовуючи алгоритми, виконати наступні дії:
//       1) зчитати дані про книжки з текстового файлу у контейнер;
//       2) впорядкувати за автором, а для одного автора за назвою;
//       3) обчислити кількість книжок, у яких рік видання попадає в задані межі;
//       4) перенести у інший контейнер книги заданого автора;
//       5) вивести всі книжки з максимальною кількістю сторінок;
//       6) знайти сумарну вартість усіх книжок;
//       7) збільшити ціну усіх книжок на вказаний відсоток.

using namespace std;

/*
 * The function reads books from file
 * pushing them in vector.
 */
void read_file(const string &file_name, vector<Book> &r){
    ifstream fin(file_name);
    if (fin)copy(istream_iterator<Book>(fin), istream_iterator<Book>(), back_inserter(r));
    else throw "File not open exception\n";
}

/*
 * The function writes vector of books.
 */
void write(const vector<Book> &r, ostream &os){
    ostream_iterator<Book> ositer(os, "\n");
    copy(r.begin(), r.end(), ositer);
}


/*
 * The function sorts the book by Author
 * (if same, by book name), and prints changed vector.
 */
void task2(vector<Book> &books){
    sort(books.begin(), books.end());
    write(books, cout);
}


/*
 * The function counts amount of books
 * issued between input years.
 */
void task3(vector<Book> &books){
    int y1 = 2015, y2 = 2020;
//    cout << "Enter years range: ";
//    cin >> y1 >> y2;
    cout << "\nAmount of all books from " << y1 << " to " << y2 << " = " << count_if(books.begin(), books.end(),
                 [y1, y2](const auto &e){return e.getYear() >= y1 && e.getYear() <= y2;}) << "\n";
}


/*
 * The function copies all books of the
 * input author in a new container.
 */
void task4(vector<Book> &books){
    vector<Book> author_books;
    string author = "Author01";
//    cout << "Enter author: ";
//    cin >> author;
    copy_if(books.begin(), books.end(), back_inserter(author_books), [author](const auto &e){return e.getAuthor() == author;});
    write(author_books, cout);
}


/*
 * The function prints all books with max
 * amount of pages.
 */
void task5(vector<Book> &books){
    cout << "\nMax:\n";
    auto max_e = max_element(books.begin(), books.end(), [](const auto &a, const auto &b){return a.getPages() < b.getPages();});
    while(max_e != books.end()) {
        cout << *max_e << "\n";
        max_e = find(++max_e, books.end(), *(--max_e));
    }
}


/*
 * The function prints sum of all books.
 */
void task6(vector<Book> &books){
    cout << "\nSum prices of all books = " << accumulate(books.begin(), books.end(), 0);
}


/*
 * The function increases prices of all
 * books by the input percentage and prints them.
 */
void task7(vector<Book> &books){
    double p = 70;
//    cout << "Enter percentage: ";
//    cin >> p;
    for_each(books.begin(), books.end(), [p](auto &e){e.setPrice(e.getPrice()*(1 + p/100));});
    write(books, cout);
}


int main() {
    try {

        vector<Book> books;
        read_file("/Users/sophiyca/ClionProjects/containers_task5/books.txt", books);
        cout << "All books: \n";
        write(books, cout);
        auto func_vector = {task2, task3, task4, task5, task6, task7};
        int i = 2;
        for_each(func_vector.begin(), func_vector.end(), [&books, &i](auto f){
            cout <<  "\n-----------------------------------\nTASK " << i << ":\n"; i++; f(books);});

//        task2(books);
//        task3(books);
//        task4(books);
//        task5(books);
//        task6(books);
//        task7(books);

    } catch (const char* ex) {
        cout << ex;
    }

    system("pause");
    return 0;
}