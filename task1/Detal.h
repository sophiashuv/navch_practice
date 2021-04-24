
#ifndef TASK1_DETAL_H
#define TASK1_DETAL_H

#endif //TASK1_DETAL_H
using namespace std;
#include <ctime>


enum Sort { sort1=1, sort2=2, sort3=3 };


class Date
{
private:
    int month, day, year;
public:
    Date()
    {
        month = 0, day = 0, year = 0;
    }

    Date(const Date &d)
    {
        month = d.month, day = d.day, year = d.year;
    }

    Date(int Month, int Day, int Year)
    {
        setMonth(Month);
        setDay(Day);
        setYear(Year);
    }

    void setDay(int d)
    {
        if (d < 1 || d > 31)
            throw "The day is invalid";
        else
            day = d;
    }

    void setMonth(int m)
    {
        if (m < 1 || m > 12)
            throw "The month is invalid";
        else
            month = m;
    }

    void setYear(int y)
    {
        if (y < 1950 || y > 2021)
            throw "The year is invalid";
        else
            year = y;
    }

    friend bool operator >(Date a, Date b){
        if (a.year == b.year) {
            if (a.month == b.month){
                return a.day > b.day;
            }
            return a.month > b.month;
        }
        return a.year > b.year;
    }

    Date& operator =(const Date &d)
    {
        this->year = d.year;
        this->day = d.day;
        this->month = d.month;
        return *this;
    }

    friend ostream & operator<<(ostream & os, const Date & a) {
        os << a.month << " /" << a.day << " /" << a.year;
        return os;
    }

    friend istream & operator>>(istream & is, Date & a) {
        int y, m, d;
        is >> y >> m >> d;
        a.setDay(d);
        a.setMonth(m);
        a.setYear(y);
        return is;
    }

};


class Detal {
private:
    string name;
    Sort sort;
    Date date;
    int quant;
    double cost;

public:
    Detal() : name(""), sort(sort1), date(Date()), quant(0), cost(0) {}

    Detal(string _name, Sort _sort, Date _date, int _quant, double _cost):sort(_sort),date(_date), quant(_quant), cost(_cost) {}

    friend istream & operator>>(istream & is, Detal & a) {
        cout << "name: ";
        is >> a.name;
        cout << "sort: ";
        int s;
        is >> s;
        a.sort = Sort(s);
        cout << "date (y m d): ";
        is >> a.date;
        cout << "quant: ";
        is >> a.quant;
        cout << "cost: ";
        is >> a.cost;
        cout << "\n";
        return is;
    }

    const string &getName() const {
        return name;
    }

    const Sort &getSort() const {
        return sort;
    }

    const Date &getDate() const {
        return date;
    }

    int getQuant() const {
        return quant;
    }

    double getCost() const {
        return cost;
    }

    void setName(const string &name) {
        Detal::name = name;
    }

    void setSort(const Sort &sort) {
        Detal::sort = sort;
    }

    void setDate(const Date &date) {
        Detal::date = date;
    }

    void setQuant(int quant) {
        Detal::quant = quant;
    }

    void setCost(double cost) {
        Detal::cost = cost;
    }

    friend ostream & operator<<(ostream & os, const Detal & a) {
        os << "name: " << a.name << ",\nsort: " << a.sort
           << ",\ndate: " << a.date << ",\nquant: " << a.quant << ",\ncost: " << a.cost << "\n\n";
        return os;
    }
};


