
#ifndef TASK8_POLYNOMIAL_H
#define TASK8_POLYNOMIAL_H

#endif //TASK8_POLYNOMIAL_H
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Polynomial
{
    private:
        vector<int> coefficients = vector<int>();
        size_t deg;

public:
    Polynomial() {
        coefficients = vector<int>();
    }


    Polynomial(const vector<int> &coefs) {
        coefficients = vector<int>(coefs.size());
        deg = coefs.size();
        for (int i = 0; i < coefs.size(); ++i) {
            coefficients[i] = coefs[i];
        }
        delete_zeros();
        deg = degree();
    }


    Polynomial(const int v, size_t _deg) {
        coefficients = vector<int>(_deg);
        deg = _deg;
        for (int i = 0; i < deg; ++i) {
            coefficients[i] = 0;
        }
    }


    friend istream & operator>>(istream & is, Polynomial & a) {
        cout << "Enter coefficients of the polynom: ";
        int e;
        is >> e;
        while (!is.fail()) {
            a.coefficients.push_back(e);
            is >> e;
        }
        is.clear();
        is.ignore(numeric_limits<streamsize>::max(), '\n');    // This line ignores the rest of the current line, up to '\n'.

        a.delete_zeros();
        a.deg = a.degree();
        return is;
    }


    friend ostream & operator<<(ostream & os, const Polynomial & a) {
        for (int i = a.deg - 1; i >= 0; i-- ) {
            if ( a.coefficients[i] != 0 ) {
                os << a.coefficients[i] << "x^" << i << " ";
            }
        }
        return os;
    }


    friend bool operator ==(const Polynomial &a, const Polynomial &b){
        if (a.deg != b.deg) return false;
        for (int i = 0; i < a.deg; ++i) {
            if (a.coefficients[i] != b.coefficients[i]) return false;
        }
        return true;
    }


    void delete_zeros(){
        while (!coefficients.empty() && coefficients[coefficients.size() - 1] == 0) {
            coefficients.pop_back();
        }
    }


    void set ( int a , int b ) {
        deg = degree();
        if (deg <= b){
            for (int i = 0; i < b - deg + 1; ++i) {
                coefficients.push_back(0);
            }
        }
        coefficients[b] = a;
        delete_zeros();
        deg = degree();
    }


    size_t degree() {
        return coefficients.size();
    }


    int evaluate (int x) {
        auto res = 0;
        for (int i = deg - 1; i >= 0; i-- ) {
            res += coefficients[i] * pow(x, i);
        }
        return res;
    }


    Polynomial differentiate() {
        if ( deg == 0 ) return Polynomial(vector<int>{0});
        Polynomial deriv = Polynomial( 0, deg - 1 );
        deriv.deg = deg - 1;
        for ( int i = 0; i < deg; i++ )
            deriv.coefficients[i] = ( i + 1 ) * coefficients[i + 1];
        return deriv;
    }


    friend Polynomial operator+(Polynomial lhs,  const Polynomial& rhs) {
        Polynomial c = Polynomial(0, max(lhs.deg, rhs.deg));
        for ( int i = 0; i < lhs.deg; i++ ) c.coefficients[i] += lhs.coefficients[i];
        for ( int i = 0; i < rhs.deg; i++ ) c.coefficients[i] += rhs.coefficients[i];
        c.deg = c.degree();
        return c;
    }


    friend Polynomial operator-(Polynomial lhs,  const Polynomial& rhs) {
        Polynomial c = Polynomial(0, max(lhs.deg, rhs.deg));
        for ( int i = 0; i < lhs.deg; i++ ) c.coefficients[i] += lhs.coefficients[i];
        for ( int i = 0; i < rhs.deg; i++ ) c.coefficients[i] -= rhs.coefficients[i];
        c.deg = c.degree();
        return c;
    }


    friend Polynomial operator*(Polynomial lhs,  const int coef) {
        Polynomial c= Polynomial(0, lhs.deg);
        for ( int i = 0; i <= lhs.deg; i++ ) c.coefficients[i] = lhs.coefficients[i] * coef;
        c.deg = c.degree();
        return c;
    }


//    Polynomial times ( Polynomial b )
//    {
//        Polynomial a = *this; //a is the poly on the L.H.S
//        Polynomial c;
//
//        for ( int i = 0; i <= a.deg; i++ )
//            for ( int j = 0; j <= b.deg; j++ )
//                c.coefficients[i+j] += ( a.coefficients[i] * b.coefficients[j] );
//        c.deg = c.degree();
//        return c;
//    }
};
