//course: CS216-002
//Project: Lab Assignment 7
//Program: lab7.cpp
//Date: 03/25/2015
//Purpose: Use as the lab assignment example
//
//Author: Ajin Sunny

#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;

//Deifining the classes 

class Matherr { public: string errname; };
class DivideByZero : public Matherr
{
            public:
                        DivideByZero() {this->errname = "Division by zero";}
                                string getName() {return this->errname;}
};

class OutofRange : public Matherr
{
        public: 
            OutofRange(){this->errname = "Out of Range !";}
            string getName() {return this->errname;}
};

//Defining the function for calculating the average

double calculateAverage(vector<double> scores);



int main()
{

// Initializing the required varibales 
vector<double> scores;
double input_score;
cout<<"Welcome to Average score calculation"<<endl;
string input_string;

// do while loop which prompts the user for scores
do
{
    
    cout<<" Enter the score : "<<endl;
    cin>>input_score;
    
    // checks if the input was of the right type or else it fails 
    if(cin.fail())
    {
        cin.clear();
        getline(cin,input_string);

    }    

    // if it doesnt fail and is a correct input type then push it to the vector
    else
    {
            scores.push_back(input_score);

    }
}while(input_string != "Q" && input_string!="q");

// average variable 
double avg;

// Try and catch block for Division by zero and Out of Range error 
try 
{

    avg = calculateAverage(scores);
    cout<<"The average is : "<<avg<<endl;
        
}

catch(DivideByZero & err)
{
    cout<<"Exception: "<<err.getName()<<endl; 
}

catch(OutofRange &err)
{
    cout<<"Exception: "<<err.getName()<<endl;
}

return 0;
}


// Function to calculate the average of the scores given by the user 
//
double calculateAverage(vector<double> scores)
{
    if(scores.size()==0)
    {
        throw DivideByZero();       
    }
        
    for (int i=0; i < scores.size(); i++)
    {
            
            if(scores[i] < 0 || scores[i] > 100)
            {
                throw OutofRange();       
            }           

    }

    double sum=0;
    double average;

    for(int i=0 ; i<scores.size() ; i++)
    {
            sum += scores[i];
    }

    average = sum/scores.size();

    return average;
}





















