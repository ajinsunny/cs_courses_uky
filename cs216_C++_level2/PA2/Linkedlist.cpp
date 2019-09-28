#include <iostream>
#include <string>
#include "Linkedlist.h"

//
// Course: CS216 - 002 
// Project: Programming Assignment 2
// Author: Ajin Sunny 
// Date: 03/10/15
// Purpose: This is the cpp file which has most of the definitions of  member functions for the linked list and node 
//


Linkedlist::Linkedlist() //constructor for linkedlist 
{
    head = NULL;
    size = 0;    
}


Node::Node(string info, Node * _next) : info(info) , next(_next) // This is a constructor for the Node Class
{}


int Linkedlist::getsize()  // This is just a member function to return the size of the list if size needs to be
    // incremented when there is any change in the linked list
{

return size;

}

Node const* Node::getnext() const // Member function to get the next pointer of the node
{
        return next;
}

Node* Linkedlist::gethead() // Member function to get the top of the Node 
{
        return head;
}

string Node::getinfo() const //  Member function to get the data of the Node and return it 
{
        return info;

}

void Linkedlist::makelist(ifstream& f) // This is the member function that is used to make all the components in a file in the form of a list 
{


    Node *currptr = NULL;
    Node *newNodeptr = NULL;
    string line;


    while(!f.eof())
    {
        //read the line from the file 
        getline(f,line);

        //dynamically allocate a new Node of Node class type by using a constructor for class Node 

        newNodeptr = new Node(line,NULL);
        

        if(head == NULL)
        {
            
            head = newNodeptr;
            currptr = head;    

        }

        else
        {
                currptr->next = newNodeptr;
                currptr = newNodeptr;
        }
        size++;

    }
    


}



void Linkedlist::insertline (string line, int position_of_insert) // This is the INSERT function which inserts user input into the linked list 
{

//First we set the current pointer to head 
Node *currptr = head;
Node *prevptr = NULL;
Node *newptr;
newptr = new Node(line, currptr);

// inserting from the top of the linked list 

if(position_of_insert == 1) // This is the case when there is only one NODE.
{

    head = newptr;

}

else 
{
    for (int i = 0 ; i < position_of_insert-1 ; i++ ) // Looping through and setting the pointer 
    {
    
        prevptr = currptr;
        currptr = currptr->next;

    
    }

    prevptr->next = newptr; // Making the insertion 
    newptr->next = currptr; // making the insertion 
}

size++;

}


void Linkedlist::deleteline (int position_of_deletion) // Member function that is used to DELETE a line which the user wants to be deleted 

{
    Node *currptr = head;
    Node *prevptr = NULL;

    if(position_of_deletion == 1)  // case when there is only one node 
    {
            prevptr = head;
            head = head->next;
    }

    else
    {
        for(int i = 1 ; i < position_of_deletion ; i++) // Looping throught to set the pointers 
        {
            prevptr = currptr;
            currptr = currptr->next;

    
        }
    }
    prevptr->next = currptr->next; //deleting the Node by setting the pointers

    delete currptr;

    size=size-1; // decrease the size of linked list 

}




void Linkedlist::printLinkedlist () // Member function that is used to PRINT the list onto the screen 
{

Node *currptr;
currptr = head;
int no_of_the_line = 1;

while (currptr != NULL)
{

  cout<<no_of_the_line<<">"<<currptr->getinfo()<<endl;
  currptr = currptr->next;
  //Now increment the line no before the loop starts again.

  no_of_the_line=no_of_the_line+1;


}

}


