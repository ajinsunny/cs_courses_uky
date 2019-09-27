//course: CS216-00x
//Project: Lab Assignment 10
//Date: 04/14/2015
//Purpose: to implement operator overloading to simplify basic operations on Matrices
//         such as <<, (), +, * operators
//Author: (your name)

#include <cstdlib>
#include <iostream>
#include <cassert>
#include <ctime>
#include "Matrix.h"

using namespace std;

int main(int argc, char** argv) {
    int size1, size2, size3;
    const int RANGE = 5; //using to generate random number in the range[1,6]
        
    cout << "Please input three positive integers: (size)";
    cin >> size1 >> size2 >> size3;
    assert(size1 > 0 && size2 > 0 && size3 > 0);
    
    Matrix myMatrix1(size1, size2), myMatrix2(size2,size3);
    Matrix yourMatrix1(size1, size2), yourMatrix2(size2, size3);
    Matrix theirMatrix1(size1, size2), theirMatrix2(size1, size3);

    srand(time(0));
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size2; j++)
            myMatrix1(i,j) = rand() % RANGE + 1;
    yourMatrix1 = 2 * myMatrix1;
    theirMatrix1 = myMatrix1 + yourMatrix1;
    cout << "myMatrix1: " << endl;
    cout << myMatrix1 << endl << endl;
    
    cout << "yourMatrix1 = 2 * myMatrix " << endl;
    cout << yourMatrix1 << endl << endl;
    
    cout << "myMatrix1 + yourMatrix1: " << endl;
    cout << theirMatrix1 << endl << endl;
    
    for (int i = 0; i < size2; i++)
        for (int j = 0; j < size3; j++)
            myMatrix2(i,j) = rand() % RANGE + 1;
    yourMatrix2 = myMatrix2 * 3;
    theirMatrix2 = myMatrix1 * yourMatrix2;
    cout << "myMatrix1: " << endl;
    cout << myMatrix1 << endl << endl;
    
    cout << "myMatrix2: " << endl;
    cout << myMatrix2 << endl << endl;
    
    cout << "yourMatrix2 = myMatrix2 * 3 " << endl;
    cout << yourMatrix2 << endl << endl;
    
    cout << "myMatrix1 * yourMatrix2: " << endl;
    cout << theirMatrix2 << endl << endl;
    
    return 0;
}
