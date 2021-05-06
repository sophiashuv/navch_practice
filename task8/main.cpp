#include <iostream>
#include "Polynomial.h"

using namespace std;

int main() {
    Polynomial a, b;
    cin >> a >> b;

    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    cout << "sum(a, b): " << a + b << "\n";

    int aa, bb, h;
    cout << "Enter interval: \na = ";
    cin >> aa;
    cout << "b = ";
    cin >> bb ;
    cout << "Enter h: \nh = ";
    cin >> h;
    for (int i = aa; i < bb; i += h) {
        cout << "x = " << i << ": f1(x) = " << a.evaluate(i) << "\n";
        cout << "x = " << i << ": f2(x) = " << b.evaluate(i) << "\n";
    }

    int x;
    cout << "Enter x: ";
    cin >> x;
    if (a == b) {
        cout << "x = " << x << " : f(x) = " << a.evaluate(x) << "\n";
    }
    else {
        cout << "a * x: " << a * x << "\n";
        cout << "b': " << b.differentiate() << "\n";
    }
}