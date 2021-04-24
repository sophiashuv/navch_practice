#ifndef TASK2_RECTANGLE_H
#define TASK2_RECTANGLE_H

#endif //TASK2_RECTANGLE_H

using namespace std;

class Rectangle: public Figur
{
    double a;
    double b;

public:
    Rectangle(double _a, double _b): a(_a), b(_b){};

    double area() {
        return a * b;
    }

    virtual double perimeter(){
        return 2 * (a + b);
    }

    virtual void print(){
        cout << "Rectangle: " << a << " " << b << "\n" << "area: " << area() << "\nperimeter: " << perimeter() << "\n";
    }
};

