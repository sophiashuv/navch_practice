//
// Created by Sophia Shuvar on 23.05.20.
//

#ifndef CONTAINERS_TASK7_BOOK_H
#define CONTAINERS_TASK7_BOOK_H

#endif //CONTAINERS_TASK7_BOOK_H
using namespace std;

//Книга характеризується облiковим номером, автором книги, назвою книги i жанром.
class Book {
private:
    int b_num;
    string author;
    string name;
    string genre;

public:
    Book() : b_num(0), author(""), name(""),  genre("") {}

    Book(int _b_num, string _author, string _name, string _genre): b_num(_b_num), author(_author),
    name(_name),  genre(_genre) {}

    friend istream & operator>>(istream & is, Book & a) {
        is >> a.b_num;
        is >> a.author;
        is >> a.name;
        is >> a.genre;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Book & a) {
        os << "b_num: " << a.b_num << ", author: " << a.author
           << ", name: " << a.name << ", genre: " << a.genre ;
        return os;
    }

    int getB_num() const {
        return b_num;
    }

    const string &getAuthor() const {
        return author;
    }

    const string &getName() const {
        return name;
    }

    const string &getGenre() const {
        return genre;
    }
};