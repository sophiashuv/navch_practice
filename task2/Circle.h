
#ifndef TASK2_CIRCLE_H
#define TASK2_CIRCLE_H

#endif //TASK2_CIRCLE_H

#include <math.h>

using namespace std;

class Circle: public Figur
{
    double r;

public:
    Circle(double _r): r(_r) {};

    double area() {
        return M_PI * pow(r, 2);
    }

    virtual double perimeter(){
        return 2 * M_PI * r;
    }

    virtual void print(){
        cout << "Circle: " << r << "\n" << "area: " << area() << "\nperimeter: " << perimeter() << "\n";
    }
};
