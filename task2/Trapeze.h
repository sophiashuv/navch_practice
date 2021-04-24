
#ifndef TASK2_TRAPEZE_H
#define TASK2_TRAPEZE_H

#endif //TASK2_TRAPEZE_H

using namespace std;

class Trapeze: public Figur
{
    double a;
    double b;
    double c;
    double d;
    double h;

public:
    Trapeze(double _a, double _b, double _c, double _d, double _h): a(_a), b(_b), c(_c), d(_d), h(_h) {};

    double area() {
        return h * (a + b) / 2.0;
    }

    virtual double perimeter(){
        return a + b + c + d;
    }

    virtual void print(){
        cout << "Trapeze: " << a << " " << b << " " << c << " " << d << "\n" << "area: " << area() << "\nperimeter: " << perimeter() << "\n";
    }
};
