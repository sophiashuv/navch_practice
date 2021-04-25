
#ifndef TASK5_SPENDING_H
#define TASK5_SPENDING_H

#endif //TASK5_SPENDING_H

#include <iostream>
#include <deque>

#include "SpentMaterial.h"

using namespace std;

class Spending{
protected:
    uint number;
    string data;
    deque<SpentMaterial> materials;

public:
    Spending(){
        number = 0;
        data = "";
        materials =  deque<SpentMaterial>();
    }

    Spending(uint _number, string _data, deque<SpentMaterial> _materials) {
        number = _number;
        data = _data;
        materials =  _materials;
    }

    Spending(const Spending& a) {
        number = a.number;
        data = a.data;
        materials =  a.materials;
    }

    friend istream& operator >>(istream & in,  Spending & b) {
        int am;
        in >> b.number >> b.data >> am;
        b.materials = deque<SpentMaterial>(am);
        for (int i = 0; i < am; ++i) {
            in >> b.materials[i];
        }
        return in;
    }

    friend ostream & operator<<(ostream & os, const Spending & a) {
        os << "number: " << a.number << "\ndata: " << a.data << "\nmaterials: \n";
        for (auto p: a.materials)
            os << p;
        os << "\n\n";
        return os;
    }

    void add_material(SpentMaterial mat){
        materials.push_back(mat);
    }

    friend bool operator ==(Spending a, Spending b){
        return a.number == b.number;
    }

    friend bool operator <(Spending a, Spending b){
        return a.number < b.number;
    }

    uint getNumber() const {
        return number;
    }

    void setNumber(uint number) {
        Spending::number = number;
    }

    const string &getData() const {
        return data;
    }

    void setData(const string &data) {
        Spending::data = data;
    }

    const deque<SpentMaterial> &getMaterials() const {
        return materials;
    }

    void setMaterials(const deque<SpentMaterial> &materials) {
        Spending::materials = materials;
    }
};
