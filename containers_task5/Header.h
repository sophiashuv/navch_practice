//
// Created by Sophia Shuvar on 08.05.20.
//

#ifndef CONTAINERS_TASK5_HEADER_H
#define CONTAINERS_TASK5_HEADER_H

#endif //CONTAINERS_TASK5_HEADER_H
#include <iostream>
#include <string>

using namespace std;


class Book {
private:
    string name;
    string author;
    int pages;
    int year;
    double price;
public:
    Book() : name(""), author(""), pages(0), year(0), price(0) {}

    Book(string _name, string _author, int _pages, int _year, double _price): name(_name),
                                                                author(_author), pages(_pages),
                                                                year(_year), price(_price) {}

    friend istream & operator>>(istream & is, Book & a) {
        is >> a.name;
        is >> a.author;
        is >> a.pages;
        is >> a.year;
        is >> a.price;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Book & a) {
        os << "name: " << a.name << ", author: " << a.author
           << ", pages: " << a.pages << ", year: " << a.year << ", price: " << a.price;
        return os;
    }

    friend bool operator <(const Book & a, const Book & b){
        if (a.author == b.author) return a.name < b.name;
        return a.author < b.author;
    }

    friend bool operator ==(const Book &a, const Book &b){
        return a.pages == b.pages;
    }

    friend double operator +(double d, const Book &a) {
        return  d + a.price;
    }

    int getYear() const {
        return year;
    }

    const string &getAuthor() const {
        return author;
    }

    int getPages() const {
        return pages;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Book::price = price;
    }
};