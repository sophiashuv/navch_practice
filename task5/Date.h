
#ifndef TASK5_DATE_H
#define TASK5_DATE_H

#endif //TASK5_DATE_H
using namespace std;
#include <ctime>


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

    friend bool operator <(Date a, Date b){
        return !(a > b);
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
        char dash;
        int y, m, d;
        is >> y >> dash >> m >> dash >> d;
        a.setDay(d);
        a.setMonth(m);
        a.setYear(y);
        return is;
    }

};
