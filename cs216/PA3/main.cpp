//__________________________________________//
//course: CS216 - 002 Program Assignment 3 
//Date : 04 / 14 / 15
//Purpose: This is main funciton for this programming assignment.  
//Author: Ajin Sunny
//__________________________________________// 


#include<iostream>
#include<string>
#include "stack.h"
#include<sstream>
#include<cstring>

bool check(string exp); //checking if it is an infix exp
bool check_operand(string exp); // checking if the string is an operand 
bool check_operator(string exp); // checking if the string is an operator
int precedence_of_exp(string exp); // This is a function to checkthe precedence of the 
string convert_to_postfix(string exp); //Function to convert infix to postfix 
string evaluation(string exp); // Function to evaluate the exp using post fix notation.

//--------------------- MAIN Function ---------------
//This is the main function which runs the program with case statements and 
//provides the specified operations to the user according to what the use requires 
//


int main()
{
        
    string option;
    string expression;

    do{
        
        restart:
        
          cout<<"***********************************************************"<<endl;
          cout<<"1. Read an expression in infix notation"<<endl;
          cout<<"2. Convert infix to postfix."<<endl;
          cout<<"3. Evaluate the expression using postfix notation."<<endl;
          cout<<"4. Exit"<<endl;
          cout<<"***********************************************************"<<endl;

          cout<<"Please enter your option : ";
        
          cin>>option;

          if (option == "1")
                        {    
                            cout<<"Select: 1"<<endl;
                            cout<<"Enter an infix expression:"<<endl;
                            cin.ignore();
                            //read in the infix expression
                            getline(cin,expression);
                            //check if its infix expression
                            if(check(expression)==false)
                              { 
                                  //if not print error message

                                  cout<<"Not an infix expression"<<endl;
                                  cout<<"Please try again"<<endl;

                                  goto restart;

                              }
                        }
          else if(option == "2")
          {
                cout<<"Select: 2"<<endl;
                cout<<"Infix Expression: "<<expression<<endl; //Displaying Infix
                cout<<"Postfix Expression: "<<convert_to_postfix(expression)<<endl; //Displaying after converting it to Postfix
          }

          else if(option == "3")
          {
                 cout<<"Select: 3"<<endl;
                 cout<<"Infix Expression: "<<expression<<endl; 
                 //Displaying Infix form
                 cout<<"Evaluation of this Expression: "<<evaluation(convert_to_postfix(expression))<<endl;
                 // Displaying after converting to post fix and evaluating the expression

          }

          else
          {
                cout<<"Please enter from a range of 1 to 4 as your option"<<endl; // This is a condition if the user enters anything besides the provided option
          }



    }while(option != "4");
    cout<<"Select: 4"<<endl;
    cout<<"Thank you for using the program"<<endl;



return 0;

}

//------------------ Checking if it is an operand -----------------
//This is a funciton which is used to check if the entered expression has an operand in it 
//and it will return true if there is any operand from 0 -9 
// else it will return false

bool check_operand(string exp)
{
        
    for(int i=0; i<exp.length(); i++)
        {
            if (exp[i]>='0'&&exp[i]<='9')
                {
                    continue;
                }

            else
                {
                    return false;
                }

        }

    return true;


}

//------------------- Checking if it is an operator--------------------
// This bool function is used to check if the given expression by the user has an operator or not 
// if it does then it will return true otherwise it will return false. 
//
bool check_operator(string exp)
{
    
        if(exp == "+" || exp == "-" || exp == "*" || exp == "/")
        {
                return true;
        }    
        else
        {
                return false;
        }


}


//--------------- Precedence checking and reporting function------------------
//This funciton will check the precedence of the operators from the expression 
//and return an integer according to the level of predcedence. Multiplication and 
//division has higher precendence therefore it will return 2 and + and - will return 1 
//anything lower than that will return 0 

int precedence_of_exp(string exp)
{
    // concept goes based on highest returning value 
    // returning 2 means it is either * or / 
    // returning 1 means it is either + or - 
    // returning 0 means any other operator 

    if(exp == "*" || exp == "/")
      return 2;
    if(exp == "+"|| exp == "-")
      return 1;
    else 
      return 0 ;


}

//------------------------ Checking if it is an infix --------------
//This bool function is basically used to check if the given expression by the user is a infix expression 
//or not. If it is then it will return true else it will return false. 
//
//

bool check(string exp)
{
  Stack S;
  stringstream input(exp);
  string infix_result;

  while(input>>infix_result)
  {
    //if the result is not an operator and not an operand and does not equall ( and )
    if(!check_operand(infix_result) && !check_operator(infix_result) && infix_result != "(" && infix_result!=")")
      //return false
      return false;

  }

  return true;

}

//------------------------- Function to convert infix to post fix -----------------------
//This is a function which is used to convert an infix expression to postfix expression. The 
//input is taken in as a string stream format and then uses the other funcitons to perform checking 
//whether they are operator or operand or not, according to this it is then pushed into the stack.
//The required pushing and popping operation is performed acccording to the precedenec function. 
//This is will finally generate a postfix expression and then the contents from the stack is stored into 
//postfix_exp string variable which is later returned as a string to the place where this funciton will
//be called.

string convert_to_postfix(string exp)
{

  Stack S;
  stringstream input(exp);
  string result;
  string postfix_exp;

  while(input>>result)

  {
      // if the input is an operand 
      if (check_operand(result))
      {

          postfix_exp = postfix_exp + result + " ";


      }
      //if the input is an operator 
      else if(check_operator(result))
      {

        while(!S.empty() && S.stackTop()!="(" && precedence_of_exp(result)<=precedence_of_exp(S.stackTop()))
        {

            string over = S.stackTop();
            S.pop();

            postfix_exp += over + " ";

        }

        if(!S.empty() && S.stackTop() == "(")
        {
          //pop the stack
          S.pop();
        }

          S.push(result);


      }


      else if(result=="(")
      {
        //push result into stack
        S.push(result);
      }


      else if(result==")")
      {
          while(!S.empty() && S.stackTop()!="(" )
          { 

            //over equal top of stack and pop the stack
            string over = S.stackTop();
            S.pop();
            //add op to result exp
            postfix_exp += over + " ";
          }
      }
  }

  while(!S.empty())
  {
    postfix_exp += S.stackTop() + " ";
    S.pop();

  }

  return postfix_exp;


}


//---------------------- Function to evaluate the post fix expression ----------------------
//This is a funciton which is used to evaulate the postfix expression. the funciton uses stringstream to take the
//input from the user through the variable "input". This is then used to check for operands and opreators and then it will store the 
//values into stack as strings and perform the opertion by converitng the operands from string format to integer format by using atoi
//after this normal arithmetic is used to find the final answer.After determining the final answer , It is then pointed to the top of the stack to get 
//the final answer which is then displayed by returning as a string variable.


string evaluation(string exp)
{

  Stack S;
  stringstream input(exp);
  stringstream con;
  string result;
  string num1;
  string num2;
  string finalfinal;
  double final1;
  string final2;
  double one;
  double two;

  while(input>>result)
  {
    //clear con stringstream
    con.str(string());
    //if result is an operand 
    if (check_operand(result))
    {
      //push result into stsack
      S.push(result);
    }
    //if result is an operator
    else if (check_operator(result))
    {
      //store the two values in the stack into strings
      num1 = S.stackTop();
      S.pop();
      num2 = S.stackTop();
      S.pop();
      //convert the string to ints
      one = atoi(num1.c_str());
      two = atoi(num2.c_str());
      //if the operator is a +
      if (result == "+")
      {
        //add the two values
        final1 = one+two;
        //convert int back to string
        con<<final1;
        final2 = con.str();
        //add back into stack
        S.push(final2);
      }
      //if operator is -
      else if(result == "-")
      {
        //subtract the two values
        final1 = two-one;
        //convert the result back to string
        con<<final1;
        final2 = con.str();
        //add back into stack
        S.push(final2);
      }
      //if the operator is /
      else if(result == "/")
      {
        //divide the two values
        final1 = two/one;
        //convert back to string
        con<<final1;
        final2 = con.str();
        //push result back into stack
        S.push(final2);
      }
      //if operator is *
      else if(result == "*")
      {
        //mulitply the two values
        final1 = one*two;
        //convert back into string
        con<<final1;
        final2 = con.str();
        //add into stack 
        S.push(final2);
      }
    }
  }
  //set finalfinal equal to the top of stack 
  finalfinal = S.stackTop();
  //emtpyt the stack
  S.pop();
  //reutrn final value
  return finalfinal;
}











