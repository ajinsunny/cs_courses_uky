//LinkedList.cpp

#include "LinkedList.h"
using namespace std;

/** 
* Print the contents of the list
*/ 
void List::Print() {
    // Temp pointer 
    Node *tmp = head; 

    // No nodes 
    if ( tmp == NULL ) {
         cout << "EMPTY" << endl;
         return;
     }
    // One node in the list 
    else if( tmp->Next() == NULL ) {
         cout << tmp->Data();
         cout << " --> "; 
         cout << "NULL" << endl;
     }
     else {
    // Parse and print the list
          while ( tmp != NULL) {
                cout << tmp->Data(); 
                cout << " --> "; 
                tmp = tmp->Next();
          }
          cout << "NULL" << endl;
      }
}

/**
 * Append a node to the linked list
 */
void List::Append(int data) {
    // Create a new nide
    Node* newNode = new Node();
    newNode->SetData(data); 
    newNode->SetNext(NULL);
    // Create a temp pointer
    Node *tmp = head; 
    if ( tmp != NULL ) {
        // Nodes already present in the list 
        // Parse to end of list 
	    while ( tmp->Next() != NULL ) {
		    tmp = tmp->Next();
		}
       
        // Point the last node to the new node
    		tmp->SetNext(newNode);

	
}

     else {
         // First node in the list
	 head = newNode;
     }
}
/**
 * Delete a node from the list
 */ 
void List::Delete(int data) {
    // Create a temp pointer
    Node *tmp = head;
    // No nodes
    if ( tmp == NULL )
        return;
    // Last node of the list
    if ( tmp->Next() == NULL ) {
         head = NULL;
     } else {
         // Parse thru the nodes
         Node *prev;
         do {
              if ( tmp->Data() == data ) break;
              prev = tmp;
              tmp = tmp->Next();
          } while ( tmp != NULL );
          // Adjust the pointers
          prev->SetNext(tmp->Next());
          // Delete the current node
          delete tmp;
      }
} 
