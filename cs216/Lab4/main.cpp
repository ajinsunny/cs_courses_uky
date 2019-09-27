//main.cpp

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    // New list
    List list;
    // Append nodes to the list
    list.Append(100);
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(500);
    list.Print();
    // Delete nodes from the list
    list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
    list.Delete(200);
    list.Print();
    list.Delete(500);
    list.Print();
    list.Delete(100);
    list.Print();
} 

