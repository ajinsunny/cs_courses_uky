//course: CS216-002
//Project: Lab Assignment 5
//Date: 02/18/2015
//Purpose: To test the scope of variables, allocation from the heap, 
//         and recursive function         
//Author: Ajin Sunny

#include <iostream>
#include <sstream>

using namespace std;

void func1(void);
void func2(void);
void func3(void);
int div_rec(int n);
int Fibonacci(int n);
// global scope program storage
int num = 1;  
// static scope program storage
static int nums = 5;

int main ( void )
{
   // Function scope to stack storage
   int num = 2; 
   func1();
   func1();
   func2();
   func3();
   int answer = div_rec(12);
   // Implement a function to display the sequence of Fibonacci numbers here:
   int i;
   int c = 0;
   cout<<"The Fibonacci numbers (1st--36th) are:"<<endl<<endl;

   for (i = 1; i<=36; i++)
   {
    
   c++;

   int fib_ans = Fibonacci(i);

   cout<<fib_ans<<" ";
   
   if(c == 9 || c == 18 || c==27 || c == 36)

       {    
   
             cout<<endl;

       }
   

   }

   return 0;
 
}

void func1() {
    // function scope to stack storage
    int num = 3;
    int nums = 6;

    cout << "Calling func1: " << endl;
    // Function scope but program storage
    static int func1StaticNum = 8;
    // func1StaticNum retains its value
    // between calls
    func1StaticNum++; // keeps value for
                      // next call
    return;
}

void func2() {
    cout << "Calling func2: " << endl;
    // Block scope storage
    for (int num = 215; num < 217; num++) {
        cout << "num in for loop: " << num << endl;
    } 
    // No function or block declare,
    // num is global
    cout << "num after for loop: " << num << endl;
    return;
}   

void func3() {
    cout << "Calling func3: " << endl;
    // function scope ptr in stack storage
    int *num;
    // The pointer in the stack now points
    // to storage in the heap
    num = new int;
    *num = 7;
    // More typical use of heap storage:
    // Allocate heap buffer for file data
    char *filedata;
    filedata = new char[256];
    // Read data from file into heap buffer
    // filehandle.getline(filedata,256);
    istringstream iss("CS215 is fun!");
    iss.getline(filedata, 256);  //change file data
    filedata[4]++; // change file data
    // Heap storage must be freed
    // when done with it
    delete num;
    delete [] filedata;
    return;
} 

int div_rec(int n) {
    cout << "Calling recursive function: " << endl;
    if (n < 1) return 0;
    int answer = div_rec(n/2);
    return 1 + answer;
}


int Fibonacci(int n)
{

        if (n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else
            return (Fibonacci(n-1)+Fibonacci(n-2));
        
}
