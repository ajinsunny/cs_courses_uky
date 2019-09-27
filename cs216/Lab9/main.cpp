/*
 *CS 216 - 002 Lab assignment 9 
  Date - April 10th 2015
  Purpose - create two functions which finds the second greatest and reads data into an array 

Author : Ajin Sunny 
 
 * */


#include <iostream>
#include <string>

using namespace std;

int secondGreatest(int* data, int size);
int* read_data(int &size);

int main()
{
            
    int size;
    int second_great; 
    cout<<"Please input integers :"<<endl;
    int* array=read_data(size); 
    second_great=secondGreatest(array, size); 
    cout<<"The second greatest value is: "<<second_great<<endl;
    delete[] array;
    return 0;
}












































