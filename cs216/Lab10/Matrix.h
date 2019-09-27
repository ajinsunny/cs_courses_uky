//File: Matrix.h
//Purpose: to declare the class Matrix
//Author: (your name)

#ifndef MATRIX_H
#define	MATRIX_H

#include <iostream>
using namespace std;


class Matrix
{
  public:
	Matrix(int sizeX, int sizeY);
    Matrix(const Matrix &m);
	~Matrix();
	int GetSizeX() const { return dx; }
	int GetSizeY() const { return dy; }
	long &Element(int x, int y);        // return reference to an element
	void Print() const;
    long &operator()(int x,int y);
    Matrix &operator=(const Matrix &m);
    friend ostream &operator<<(ostream &out, const Matrix &m);
    friend Matrix operator+(Matrix m1, Matrix m2);
    friend Matrix operator*(Matrix m1, Matrix m2);
    friend Matrix operator*(int fac, Matrix m1);
    friend Matrix operator*(Matrix m1, int fac);
  private:
	long **p;       // pointer to a pointer to a long integer
	int dx;
    int dy;
};



#endif	/* MATRIX_H */

