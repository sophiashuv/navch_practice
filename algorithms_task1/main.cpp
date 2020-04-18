#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <numeric>
#include "Car.h"
//        22.	Задано текстовий файл з інформацією про автомобілі (марка, рік випуску автомобіля,
//        колір та ціна). З використанням алгоритмів: зчитати дані в один з послідовних
//        контейнерів; впорядкувати автомобілі за роком випуску; видалити автомобілі, рік
//        випуску яких попадає в задані межі;  скопіювати в новий контейнер автомобілі
//        заданої марки, ціна яких не перевищує задану; обчислити сумарну вартість автомобілів
//        в контейнері.


/*
 * The function reads .txt file using istream_iterator.
 * Returns list of students.
 */
list<Car> read_file(const string &file_name){
    ifstream fin(file_name);
    if (fin) {
        istream_iterator<Car> isiter(fin), pend;
        list<Car> cars(isiter, pend);
        return cars;
    }
    else throw "File not open exception\n";
}


/*
 * The function writes a Container of Students using ostream_iterator
 */
void write(const list<Car> &cars, ostream &os){
    ostream_iterator<Car> ositer(os, "\n");
    copy(cars.begin(), cars.end(), ositer);
}


int main() {
    try {
        list<Car> cars = read_file("/Users/sophiyca/ClionProjects/algorithms_task1/cars.txt");
        write(cars, cout);
        cout << "------------------------Sorted cars------------------------\n";
        cars.sort();
        write(cars, cout);

        cout << "------------------------Cars with removed cars------------------------\n";
        int y1 = 1990, y2 = 2000;
        cars.remove_if([y1, y2](const Car &c){return c.getYear() > y1 && c.getYear() < y2;});
        write(cars, cout);

        cout << "------------------------Copied in new container------------------------\n";
        list<Car> new_cars;
        string b = "Mustang"; double max_prise = 40.0;
        copy_if(cars.begin(), cars.end(), back_inserter(new_cars), [b, max_prise]
        (const Car &c){return ((c.getBrand() == b) && (c.getPrice() < max_prise));});
        write(new_cars, cout);

        cout << "------------------------Sum in a new container------------------------\n";
        double product = accumulate(new_cars.begin(), new_cars.end(), 0.0);
        cout << product;
        return 0;
    } catch (const char* ex) {
        cout << ex;
        return 1;
    }

}