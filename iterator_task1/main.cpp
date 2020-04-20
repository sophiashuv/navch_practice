#include <iostream>
#include <fstream>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include "Student.h"

//        Визначити клас для представлення студента за такими параметрами: прізвище, ім’я,
//        факультет, група, середній бал. Перелік студентів знаходиться у текстовому файлі.
//        Зчитати дані в один із послідовних контейнерів та вивести на консоль.
//        Всіх студентів заданого факультету та групи перемістити на початок контейнера,
//        порядок інших студентів зберегти. Вилучити студентів, середній бал яких <2.
//        Отримати в алфавітному порядку студентів заданого факультету. Результати всіх операцій
//        записати у файл. Використовувати для читання та запису потокові ітератори.


/*
 * The function reads .txt file using istream_iterator.
 * Returns list of students.
 */
list<Student> read_file(const string &file_name){
    ifstream fin(file_name);
    if (fin) {
        istream_iterator<Student> isiter(fin), pend;
        list<Student> students(isiter, pend);
        return students;
    }
    else throw "File not open exception\n";
}


/*
 * The function writes a Container of Students using
 * ostream_iterator.
 */
template <typename C>
void write(const C &students, ostream &os){
    ostream_iterator<Student> ositer(os, "\n");
    copy(students.begin(), students.end(), ositer);
}


/*
 * The function moves all students of input faculty and group to
 * the beginning of the list and writes new student list into a file.
 */
void move_front(list<Student> &students, ostream &os){
    string faculty; int group;
    cout << "Enter name of faculty (CS, BA, EPE) and group (22, 11, 12, 31, 32) to move front: ";
    cin >> faculty >> group;
    os << "Student list where " << faculty  << " " << group << " students are first: \n";
    auto it = students.end();
    for (size_t i = students.size(); i > 0; i--){
        it--;
        if (it->getFaculty() == faculty && it->getGroup() == group) {
            students.splice(students.begin(), students, it);
            advance(it, i);
        }
    }
    write(students, os);
}


/*
 * The function removes students with grade lover than 2
 * and writes new student list into a file.
 */
void remove_lower(list<Student> &students, ostream &os){
    os << "------------------------------------------------------------------------------\n\n";
    os << "Student list after removing students whose points are lower than 2: \n";
    students.remove_if([](const Student &s){return s.getGrade() < 2;});
    write(students, os);
}


/*
 * The function receives a set of alphabetically sorted
 * students of an input faculty and writes them into a file.
 */
void sort_faculty(list<Student> &students, ostream &os){
    string faculty;
    os << "------------------------------------------------------------------------------\n\n";
    cout << "Enter name of faculty to sort: ";
    cin >> faculty;
    os << "Alphabetically sorted students of " << faculty <<" faculty: \n";
    set<Student> f_students;
    copy_if(students.begin(), students.end(), inserter(f_students, f_students.end()),
            [faculty](const Student &s){return s.getFaculty() == faculty;});
    write(f_students, os);
}


int main() {
    try {
        list<Student> students = read_file("/Users/sophiyca/ClionProjects/iterator_task1/students.txt");
        write(students, cout);
        ofstream myfile;
        myfile.open ("/Users/sophiyca/ClionProjects/iterator_task1/result.txt");

        //          TASK1
        move_front(students, myfile);

        //          TASK2
        remove_lower(students, myfile);

        //          TASK3
        sort_faculty(students, myfile);

        return 0;
    } catch (const char* ex) {
        cout << ex;
        return 1;
    }
}
