 //Course: CS216 - 002 
//Project: Programming Assignment 3
 //Author: Ajin Sunny 
//Date: 04/14/15
//Purpose: This is the cpp file which has most of the definitions of  member     functions for the linked list and node  
 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//---------- STACK CLASS --------------------

class Stack
{
      public:
        Stack();
        void push(string item);
        string pop();
        string stackTop();
        bool empty();
      private:
        int top;
        vector<string> sstack;
};

// ----------- Stack constructor -------------------------

Stack::Stack() 
{
    top = -1; 
};


// ------------------ Member funcitons to push the contents onto the stack-----------

void Stack::push(string item)
{
    sstack.push_back(item);
    top++; 
};


//------------- Member function which checks if the stack is empty or not------------

bool Stack::empty()
{
        if (top == -1)
            return true;
        else 
            return false;
};

// ------------ Member funciton which is used for popping the stack ----------------

string Stack::pop()
{
    try {
         if (sstack.size()==0) throw 0;}
    catch (int err) {
            cout<<"The stack is empty"<< endl;
            cout<<"Cannot pop an item."<< endl;
            return "Error";
        };
        string tmp=sstack[top];
        sstack.pop_back();
        top--;
        return tmp;
};

// ------------------ Member function which returns the top of the stack -------------------

string Stack::stackTop()
{
        try {
                if (sstack.size()==0) throw 0;
            } catch (int err) {
                                cout<<"The stack is empty"<< endl;
                                return 0;
                              };
            return (sstack[top]);
};


#endif

