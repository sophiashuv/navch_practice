#include <iostream>
#include "Figur.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Trapeze.h"

int main() {
    auto rectangle = Rectangle(3, 4);
    auto circle = Circle(3);
    auto trapeze = Trapeze(1, 2, 3, 4, 5);

    const int n = 3;
    Figur* figurs[n] = {&rectangle, &circle, &trapeze};

    for (int i = 0; i < n; ++i) {
        figurs[i]->print();
        cout << "\n";
    }

    return 0;
}