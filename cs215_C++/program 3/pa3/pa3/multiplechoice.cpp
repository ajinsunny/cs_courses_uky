
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "multiplechoice.h"



MultipleChoice::MultipleChoice(int points, int chapter,int n_choice, string prompt , char correct_choice, vector<string> choices)
	:Question(points,chapter,prompt) 
{
	num_choice=n_choice;
	answerchoice = choices;
	c_choice = correct_choice;

}



int MultipleChoice::get_nchoice() const
{
	return num_choice;
}

string MultipleChoice::get_goodchoice () const
{

	return c_choice;

}



void MultipleChoice::write_key(ostream &out) const
{
	int points = 0;
	points = get_points();
	string the_answer = "";
	the_answer = get_goodchoice();
	//out<<"(" << points << " points) "<<endl;
	out<<"("<<the_answer<<")"<<" is the correct answer"<<endl;
	out<<endl;

}

