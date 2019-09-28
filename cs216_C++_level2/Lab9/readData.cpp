/*
 *CS 216 - 002 Lab assignment 9 
  Date - April 10th 2015
  Purpose - create two functions which finds the second greatest and reads data into an array
  Author : Ajin Sunny  
 * */





#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int* read_data(int &size)
{
    string input;
    int arsize = 10;
    int *arrayptr = new int[arsize];
    int counter = 0;


    cin>>input;

    while(input != "Q" && input !="q")
    {
        try{
            arrayptr[counter] = stoi(input);
            counter++;


            if((counter+1)==arsize)
                {   
                    arsize=arsize*2;
                    int *temparray = new int[arsize];
                    copy(arrayptr, arrayptr+min(arsize/2,arsize),temparray);
                    delete[] arrayptr;
                    arrayptr = temparray;
                }

    
    
            }
        catch(...){
                cin.clear();

        }
getline(cin, input);

    }
    
size = counter;
return arrayptr;

}




















