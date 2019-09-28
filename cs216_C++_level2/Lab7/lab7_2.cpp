//course: CS216-002
//Project: Lab Assignment 7
//program: lab7_2.cpp
//Date: 03/24/2015
//Purpose: Use as the lab assignment example
//
//Author: Ajin Sunny

#include <iostream>
#include <string>
using namespace std;
 
//define our own exception class
class Matherr { public: string errname; };
class DivideByZero : public Matherr
{
    public:
        DivideByZero() {this->errname = "Division by zero";}
        string getName() {return this->errname;}
};
 
double divide(int a, int b) {
    if(b == 0)
        throw DivideByZero();
    return (double) a / b;
}
 
int main() {
    try {
        double d = divide(4, 0);
        cout << d << endl;
    }
    catch (DivideByZero& err) {
        cout << "Exception: " << err.getName() << endl;
    }
    cout << "After try-catch block!" << endl;
    return 0;
}
