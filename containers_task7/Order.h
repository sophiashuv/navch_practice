//
// Created by Sophia Shuvar on 23.05.20.
//

#ifndef CONTAINERS_TASK7_ORDER_H
#define CONTAINERS_TASK7_ORDER_H

#endif //CONTAINERS_TASK7_ORDER_H

using namespace std;
// Замовлення характеризується датою, облiковим номером книги,реєстрацiйним номером читача та ознакою виконання(так-нi).

class Order {
private:
    string date;
    int book_id;
    int reader_id;
    bool done;


public:
    Order() = default;

    Order(string _date, int bookId, int readerId, bool _done) : date(_date), book_id(bookId), reader_id(readerId), done(_done) {}

    friend istream & operator>>(istream & is, Order & a) {
        is >> a.date;
        is >> a.book_id;
        is >> a.reader_id;
        is >> a.done;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Order & a) {
        os << "date: " << a.date << ", book_id: " << a.book_id
           << ", reader_id: " << a.reader_id << ", done: " << a.done ;
        return os;
    }

    const string &getDate() const {
        return date;
    }

    int getBook_id() const {
        return book_id;
    }

    int getReader_id() const {
        return reader_id;
    }

    bool isDone() const {
        return done;
    }

};