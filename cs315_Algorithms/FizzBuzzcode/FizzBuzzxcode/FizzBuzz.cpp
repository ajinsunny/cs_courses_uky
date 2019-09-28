//
//  main.cpp
//  FizzBuzzcode
//
//  Created by Ajin on 1/17/17.
//  CS 315-001
//  Spring 2017
//

#include <iostream>
using namespace std;

int main()
{
    int i=0;
    
    for(int n = 1; n<100; n++)  // The for loop, loops through numbers from 1 through 100
    {
        
        if ( n % 3 == 0 || n % 5 == 0 )  // else if the loop identifies the number divisible by 3 it outputs "Fizz"
            cout<<"Fizz";
        
        if(  )  //else if the loop identifies a number divisible by 5 it outputs "Buzz"
            cout<<"Buzz";
    
        else
            cout<<n;
        
        cout<<"\n";
        
    }
    cout<<"The total no. of numbers div by 3 and 5 are "<<i<<"\n";
    
    
    
}

/*
 
 Task: write a solution in your favorite programming language.
 
 How long has it taken you to have a correct solution?
 
 How many numbers between 1 and 100 are divisible by both 3 and 5?
 
 
 Answers to task:
 
 Programming Language: C++
 
 It took 15 - 20 min to write this program from scratch.
 
 
 There are 6 numbers between 1 and 100 that are divisible by both 3 and 5.
 
 */

