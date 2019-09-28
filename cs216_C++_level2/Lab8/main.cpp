#include<iostream>
#include<string>
#include"LinkedList.h"
using namespace std;

int readInt(string);
int main()
{

   char choice;
   int item;
   LinkedList a;
   
   cout << "This program demonstrates the linked list. " << endl;
   cout << "Initially, you will be asked to create the list." << endl;
   cout << "You will be later prompted to manipulate the list." <<endl << endl;
   
   a.makeList();
   
   choice='b';
   
   while(choice != 'q')
   {
      cout << "*******************************************************" << endl;
      cout<<"i: Insert (Insert an element)\n";
      cout<<"d: Delete (Delete a node with the given value)\n";
      cout<<"p: Print  (Print the content of the current list)\n";
      cout<<"q: Quit   (Quit the program)\n";
      cout << "*******************************************************" << endl;
      cout<<"\t Please enter your choice here: ";
      cin>>choice;
      
      switch(choice)
      {
	 case 'i':
	    item=readInt("to insert: ");
	    a.insertItem(item);
	    break;
	    
	 case 'd':
	    item=readInt("to delete: ");
	    a.deleteItem(item);		
	    break;

	 case 'p':
	    cout << "The content of the current ordered list is: "<<endl;
	    a.printList();
	    break;
	    
	 case 'q':
	    break;
	    
	 default:
	    cout<<" Invalid choice. Please try again.\n";
	    break;
      }
   }
   cout<<" Bye" << endl;
   return 0;
}	
int readInt(string descr)
{
   int item;
   cout << "\t Please enter an integer value " << descr; 
   cin >> item;
   
   while (item < 0)
   {
      cout << " Please try again: ";
      cin >> item;
   }
   return item;
}
