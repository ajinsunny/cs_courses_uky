#include<iostream>
#include<string>
#include "longanswer.h"


using namespace std;



LongAnswer::LongAnswer(int points, int chapter, string prompt, string new_answer_txt)
	:Question(points , chapter , prompt )
{

	answer_txt = new_answer_txt;

}

string LongAnswer::get_answer_txt() const
{

	return answer_txt;

}


void LongAnswer::writeQuestion(ostream &out) const 
{
	Question::writeQuestion(out);
	out << "________________________________________________________________________" << endl;
	out << "________________________________________________________________________" << endl;
	out << "________________________________________________________________________" << endl;
	out << "________________________________________________________________________" << endl;
	out << "________________________________________________________________________" << endl;
	out << "________________________________________________________________________" << endl;
}


void LongAnswer::write_key(ostream& outfile) const
{
	Question::write_key(outfile);
	outfile << answer_txt << endl;

}


