/*
 *CS 216 -002 
 *Programming Assignment - No 2
 *Purpose : perform insertion , deletion and print operation of an editor by using linked list 
 *          
 *     
 *      
 * Author: Ajin Sunny
 * Date : 03/07/15
 *       
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Linkedlist.h"



using namespace std;

// This is the main funciton which runs the program 
int main (int argc , char*argv[])
{


    int lineno;  // declearation of the line number which the user inputs for each command 
    string insert_line;  // user text input variable
    string userline;     // user text input variable for the condition when line no > list size
    ifstream f1; // inputstream for file with variable f
    ofstream f2; // outputstream for file with variabl f
    // char command;
    Linkedlist list_sentence; 
    char command_input;

    f1.open("testfile.txt");

    if(!f1.is_open())  // Checking if the file has errors 
    {
        cout<<"The file cannot be opened";

    }

    else {

        list_sentence.makelist(f1); // This is makes the input file which has all the text inputs into linked list 
        list_sentence.printLinkedlist(); // This prints the contents of the linkedlist onto the screen.

        f1.close(); // The input testfile is getting closed 

 do 
     {
         int size_of_linkedlist = list_sentence.getsize()+1; // grabbing the size of the linkedlist for later comparison
         cout<<">";
         cin>>command_input;

         if(command_input == 'I') // This is where the command input from user is checked to see if it is INSERT 
         {
         
             cin>>lineno;
             cin.ignore(200, '\n');


             if(lineno > list_sentence.getsize()) //Checking to see if the line number from user is greater than the list size 
             {
                for(int i=size_of_linkedlist; i<=lineno ; i++)  // if that is true then loop through the list.
                {

                    if(i<lineno) // This is where you add blank lines till the line number 
                    {
                        list_sentence.insertline("" , i);
                    }
                    else // Here you make the INSERT of the line after the blank lines 
                    {
                        cout<<i<<">";
                        getline(cin,userline);
                        list_sentence.insertline(userline, i);       
                    }

                }

             } 

             else
             {
              
              cout<<lineno<<">"; // printing the line number of the inserting line function
              getline(cin, insert_line); //getting the line from the user
              list_sentence.insertline(insert_line,lineno); // This is where you call the insert function to insert the inputted line from the user

             }
                 
         
         }

        
         else if(command_input == 'D') //This is the command input from the user used to check if the input is DELETE
         {
                
                cin >> lineno;

                if(lineno <= list_sentence.getsize())
                {
                 list_sentence.deleteline(lineno);

                }
                else 
                {
                        cout<<"Sorry. Unable to delete a nonexistent line"<<endl;
                }




         }
         
         else if(command_input == 'L') // This is to check if command input is to list everything in linked list 
         {
                list_sentence.printLinkedlist(); // LISTING EVERYTHING IN THE LIST ONTO THE SCREEN 

         }

         
         else if(command_input == 'Q') // This is to check is the command input is to QUIT and SAVE the file 
         {
            Node const* top = list_sentence.gethead(); // Getting the top of the list and storing in pointer "top"
            f2.open("testfile.txt",ios::out); // opening the testfile in output mode to write the contents
            
            while(top!=NULL) // In this while loop you write the list onto the testfile 
            {
                    f2<<top->getinfo();
                    f2<<endl;
                    top = top->getnext();
            }
 
         }


        }while(command_input!= 'Q' && command_input !='q'); // This program will be run until the user hits Q to Quit and save 


    }


    return 0;

}



