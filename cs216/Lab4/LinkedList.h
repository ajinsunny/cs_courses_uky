// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;

// Node class 
class Node {
    int data; 
    Node* next;
   public:
    Node() {}; 
    void SetData(int aData) { data = aData; }; 
    void SetNext(Node* aNext) { next = aNext; }; 
    int Data() { return data; }; 
    Node* Next() { return next; };
};
// List class 
class List { 
    Node *head; 
  public: 
    List() { head = NULL; }; 
    void Print(); 
    void Append(int data); 
    void Delete(int data); 
};
#endif
