/*
 CS 216 - 002 Lab assignment 9 
 Date - April 10th 2015
 Purpose - create two functions which finds the second greatest and reads data into an array 

 Author : Ajin Sunny 

 * */


#include <iostream>
#include <string>
#include <vector>


int secondGreatest(int* data, int size)
{
    int greatest=data[0]; //initialize greatest to the first data value
    int second_great=0; //assumes that 0 is the minimum value
    if(size>1)
        {
            for (int i=1;i<size;i++)
                { //Looping through each value inside the array
                     if (data[i]>second_great && data[i]!=greatest)
                        { 
                                
                            second_great=data[i]; 
                            if(second_great>greatest)
                                { 
                                    int tmp=greatest; 
                                    greatest=second_great;
                                    second_great=tmp;
                                }

                        }

                }
        }
            if (second_great==0)
                return greatest;

            return second_great; 
}
    

























































