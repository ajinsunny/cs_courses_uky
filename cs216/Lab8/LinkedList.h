// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include <iostream>
using namespace std;



class LinkedList;  // needed for friend line below

class ListElement
{
  private:    
   int datum;
   ListElement* next;
    
  public:
   ListElement (int, ListElement*);
   
   int getDatum () const;
   ListElement const* getNext () const;

   friend class LinkedList;  // gives LinkedList access to datum and next
};


class LinkedList
{
  private:
   ListElement* head;

  public:
   LinkedList ();
   
   void insertItem (int);
   void makeList ();
   void deleteItem (int);
   void printList ();
};

#endif
