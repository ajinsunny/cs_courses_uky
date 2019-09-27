/* Name
 * CS 215, Fall 2013
 * Programming Assignment 3 - http://www.cs.uky.edu/~neil/215/pa/3/
 * _ October, 2013
 *
 * Driver program for Exam and Question classes.
 */ 



#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
// Prototypes for non-member functions.
#include "pa3.h"
//#include "exam.cpp"
#include "exam.h"

// Non-member functions.
void pause_215(bool have_newline);

void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(200, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}



int main()
{
	
	string q_poolname;
	cout<<"Welcome to Examinator 2013 by Ajin Sunny"<<endl<<endl<<endl;
	
	cout<<"Please enter the name of the question pool file (.txt format) : ";
	getline(cin,q_poolname);

	cout<<endl<<"Checking.............. "<<endl;

	ifstream fin;
	fin.open(q_poolname);
	int count = 0; 
	while (fin.fail()) 
	{
		count += 1;
		cout<<endl<<"Error opening file"<<endl;
		fin.clear();
		cout<<endl<<"Please enter the name of the question pool again (.txt format)  : ";
		cin>>q_poolname;
		fin.open(q_poolname);

		if (count ==2)
		{
			cout<<"Hint : have you forgotten the "" - "" in the name of your question pool file";
		}
		
	}

	cout<<"Succeeded"<<endl;
	int no_questions;
	cout<<endl<<"How many questions should the exam have ? : ";
	cin>>no_questions;   

	while(cin.fail())  //check if it works
	{
		cout<<endl<<"The number you entered is invalid or not a number"<<endl;
		cin.clear();
		cout<<"Enter the number of questions you want in th exam again : "<<endl;
		cin>>no_questions;

	}

	cout<<"Number of question check suceeded  !"<<endl;




	int maximum_chap = 0;
	int minimum_chap = 0;
	cout<<"Please enter the minimum chapters you want in the exam : ";
	cin>>minimum_chap;  //decleration in the header file pa3.h
	cout<<endl;    
	cout<<"Please enter the maximum chapters you want in the exam : ";
	cin>>maximum_chap;   //decleration in the header file pa3.h
	cout<<endl;


	while(maximum_chap<minimum_chap)
	{
		cout<<"Error the maximumchapter cannot be less than minimum chapter ! ";
		cin.clear();
		cout<<"Enter the maximum chapters again"<<endl;
		cout<<"Maximum chapters : "; cin>>maximum_chap;
					
	}
	
	//Problem *** check if number of question in the pool for the specific max and min is greater than the number of questions the user entered
	

	//Exam e(min_chap, max_chap, q_poolname);

	//int n_quest= e.num_questions();
	//if( n_quest<no_question )

	//{
	//	cout<<"Error ! There are not enough questions between those chapters"<<endl;

	//}


	string exam;
	string exam_key;

	cout<<endl<<"Please enter a file name where you want to write questions for the exam ? (.txt format) : ";
	cin>>exam;
	cout<<endl<<"Please enter a file name where you want to write the key for the exam ? (.txt format) :";
	cin>>exam_key;

	ofstream fout;
	ofstream fout2;
	fout.open(exam);
	while(fout.fail())
	{
		cout<<endl<<"Error opening the file ! "<<endl<<"File Does not exist";
		fout.clear();
		cout<<endl<<"Enter the name of the file you want to write the questions to , again :";
		cin>>exam;
		fout.open(exam);
		
	}

	cout<<"Success there is an exam file";
	
	fout2.open(exam_key);
	while(fout2.fail())
	{
		cout<<endl<<"Error opening the file Does not exist";
		fout2.clear();
		cout<<endl<<"Enter the name of the file you want to write the answers to , again :";
		cin>>exam_key;
		fout2.open(exam_key);
		
	}
		

	Exam e(minimum_chap, maximum_chap,no_questions);
	e.read_questions(q_poolname);
	e.shuffle();
	e.writeExam(exam);
	e.write_key(exam_key);



		
	pause_215(false);
	return 0;



}










// Some helper functions (not member functions) for converting
// between choice letters 'a' 'b' etc and indices into the
// array of choices.  You should put these in multiplechoice.cpp.

// Convert a letter to an index.  Returns 0 for 'a' or 'A', 1 for
// 'b' or 'B', and so on, up to 25 for 'z' or 'Z'.  Should be called
// only with ordinary ASCII letters.




int letter_to_index(char c)
{
	c = tolower(c);
	if (c < 'a' || c > 'z')
		return -1; // Invalid
	else
		return c - 'a';  // subtract the ASCII codes
}

// Convert an index to a lowercase letter.  Returns 'a' for 0, 'b' for 1,
// and so on.  Should be called only with values between 0 and 25 inclusive.


char index_to_letter(int i)
{
	return 'a' + i;
}


// Split a string on the @ character.  Returns a vector of the parts, in order.
vector<string> split_string(string input)
{
	vector<string> pieces;

	// Start of the current field
	int field_start = 0;

	// Location of the next at sign.
	int next_at;
	do {
		// Find the @.  Returns the index, or string::npos if it wasn't
		// found.
		next_at = input.find('@', field_start);

		// If it wasn't found, add the last piece.
		if (next_at == string::npos)
			pieces.push_back(input.substr(field_start));
		// Or it was found, so add this piece
		else
			pieces.push_back(input.substr(field_start, next_at - field_start));

		// The next field starts just after the @
		field_start = next_at + 1;

		// If there was no @, we're done.
	} while(next_at != string::npos);

	return pieces;
}
