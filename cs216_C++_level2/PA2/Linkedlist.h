
//
//Course: CS216 - 002 
//Project: Programming Assignment 2
//Author: Ajin Sunny 
//Date: 03/10/15
//Purpose: This is the cpp file which has most of the definitions of  member functions for the linked list and node 
//
//


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Node  // This is the Node class which is used to insert and delete the information input from the user 
{

    private:
        string info; 
      //  Node* next;

    public:
        Node *next;
        Node(string info, Node*);
        Node const* getnext() const;
        string getinfo() const;
        friend class LinkedList;

};


class Linkedlist  // This is the Linkedlist class which is used to set the text input from user as a Linked list format 
{
    private:
        Node* head;
        int size;
        int num;

    public:
        Linkedlist();
        int getsize();
        Node* gethead();
        void makelist (ifstream& f);
        void insertline (string item, int position_of_insert);
        void deleteline (int position_of_deletion);
        void printLinkedlist ();
};



#endif 


