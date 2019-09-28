//course: CS216-002
//Project: Lab Assignment 10
//Date: 04/14/2015
//File: Matrix.cpp
//Purpose: to define the class Matrix
//Author: Ajin Sunny

#include <iostream>
#include <cassert>
#include "Matrix.h"

using namespace std;





Matrix::Matrix(int sizeX, int sizeY) : dx(sizeX), dy(sizeY)
{
    assert(sizeX > 0 && sizeY > 0);
    p = new long*[dx];		
    // create array of pointers to long integers
    assert(p != 0);
    for (int i = 0; i < dx; i++)
    {	  // for each pointer, create array of long integers
        p[i] = new long[dy];  
        assert(p[i] != 0);
        for (int j = 0; j < dy; j++)
            p[i][j] = 0;
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < dx; i++)
        delete [] p[i];	// delete arrays of long integers
    delete [] p;	// delete array of pointers to long
}

long &Matrix::Element(int x, int y)
{
    assert(x >= 0 && x < dx && y >= 0 && y < dy);
    return p[x][y];
}

Matrix::Matrix(const Matrix &m) : dx(m.dx), dy(m.dy)
{
    p=new long*[dx];
    assert(p !=NULL);
    for (int i=0;i<dx;i++)
    {
        p[i]=new long[dy];
        assert(p[i]!=NULL);
        for(int j=0;j<dy;j++)
            p[i][j]=m.p[i][j];
    }


};

void Matrix::Print() const
{
    cout << endl;
    for (int x = 0; x < dx; x++)
    {
        for (int y = 0; y < dy; y++)
            cout << p[x][y] << "\t";
        cout << endl;
    }
}


long &Matrix::operator()(int x,int y)
{
    long value=0;
    if(x>dx-1||y>dy-1)
        return value;
    value = p[x][y];
    return p[x][y];

}; 


Matrix &Matrix::operator=(const Matrix &m)
{
    for(int i=0; i<dx; i++)
        for(int j=0; j<dy; j++)
            p[i][j]=m.p[i][j];
    return *this;

};


Matrix operator*(Matrix m1, Matrix m2)
{
    int bigx=m2.dx;
    int bigy=m2.dy;
    if(m1.dx>m2.dx)
        bigx=m1.dx;
    if(m1.dy>m2.dy)
        bigy=m1.dy;
    Matrix tmp(bigx,bigy);
    for(int i=0;i<m1.dx;i++){
        for(int j=0;j<m2.dy;j++)
        {
            tmp.p[i][j]=0;
            for(int k=0;k<m1.dy;k++)
                tmp.p[i][j]=tmp.p[i][j]+(m1.p[i][k]*m2.p[k][j]);
        }
    };
    return tmp;
};


ostream &operator<<(ostream &out, const Matrix &m)
{

    out<<endl;
    for(int x=0 ; x<m.dx; x++)
    {
        for(int y=0; y<m.dy; y++)
            out << m.p[x][y] << "\t";
        out<<endl;

    }
    return out;

};


Matrix operator+(Matrix m1, Matrix m2)
{
    Matrix M(m1.dx, m1.dy);
    if (m1.dx!=m2.dx||m1.dy!=m2.dy)
    {
        cout<<"Matrices dimensions does not match"<<endl;
        return M;
    };

    for(int i=0;i<m1.dx;i++)
        for(int j=0;j<m1.dy;j++)
            M.p[i][j]=m1.p[i][j]+m2.p[i][j];
    return M;

};



Matrix operator*(int fac, Matrix m1)
{
    for(int i=0; i<m1.dx; i++)
        for(int j=0; j<m1.dy; j++)
            m1.p[i][j]=m1.p[i][j]*fac;
    return m1;

};



Matrix operator*(Matrix m1, int fac)
{
    for(int i=0; i< m1.dx ;i++)
        for(int j=0; j<m1.dy; j++)
            m1.p[i][j]=m1.p[i][j]*fac;
    return m1;

};


