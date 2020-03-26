//
// Created by Sophia Shuvar on 24.03.20.
//

#ifndef FINAL_TEMPLETE_LIST_H
#define FINAL_TEMPLETE_LIST_H

#endif //FINAL_TEMPLETE_LIST_H
#pragma once
#include <iostream>
using  namespace std;

template<typename T>
class List {
private:
    template<typename K>
    class Node
    {
    public:
        Node * pNext;
        K data;

        Node(K data = K(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };

    size_t Size;
    Node<T> *head;

public:
    List() {
        Size = 0;
        head = nullptr;
    }

   ~List(){
       Node<T>* current = head;
       Node<T>* pNext;

       while (current != nullptr) {
           pNext = current->pNext;
           delete current;
           current = pNext;
       }
   }

    void push_back(T data){
        if (head == nullptr) head = new Node<T>(data);
        else {
            Node<T>* current = this->head;
            while (current->pNext != nullptr) {
                current = current->pNext;
            }
            current->pNext = new Node<T>(data);
        }
        ++Size;
    }

    void Show(){
        int counter = 0;
        Node<T> *current = this->head;
        while (current != nullptr) {
            cout << current->data;
            current = current->pNext;
            counter++;
        }
        cout << "\n";
    }

    size_t GetSize() {
        return Size;
    }

    T& operator[](const size_t index){
        if (head == nullptr) throw "List is empty";
        if (index >= Size) throw "Invalid index";
        else {
            size_t iterator = 0;
            Node<T>* current = this->head;
            while (iterator != index) {
                current = current->pNext;
                ++iterator;
            }
            return current->data;
        }
    }

};
