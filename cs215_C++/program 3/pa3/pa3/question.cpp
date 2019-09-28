#include "question.h"



Question::Question(int pt, int chap, string pr)
{
	points = pt;
	chapter = chap;
	prompt = pr;

}



int Question::get_points()const
{
	return points;
}

void Question::set_points(int pts)
{
	points = pts;
}


int Question::get_chapter()const
{

	return chapter;
	
}

void Question::set_chapter(int chap)
{
	chapter = chap;
}

string Question::get_prompt()const
{

	return prompt;
}



void Question::writeQuestion(ostream &out) const
{
	out << "(" << points << " points) " << prompt << endl;
}


void Question::write_key(ostream &out) const
{
	out<<"(" << points << " points) "<<endl;
	out<<endl;

}