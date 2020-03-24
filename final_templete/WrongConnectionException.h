//
// Created by Sophia Shuvar on 24.03.20.
//

#ifndef FINAL_TEMPLETE_WRONGCONNECTIONEXCEPTION_H
#define FINAL_TEMPLETE_WRONGCONNECTIONEXCEPTION_H

#endif //FINAL_TEMPLETE_WRONGCONNECTIONEXCEPTION_H

#include <iostream>
#pragma once
using namespace std;
class WrongConnectionException{
private :
    string message;
public:
    WrongConnectionException(){
        message = "";
    }

    WrongConnectionException(string _message){
        message = _message;
    }

    void show() const{
        cout << message;
    }
};