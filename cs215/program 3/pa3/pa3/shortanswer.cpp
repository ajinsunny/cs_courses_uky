#include "shortanswer.h"



ShortAnswer::ShortAnswer(int pt, int chap, string pr,const vector<string> &ans)
	:Question(pt, chap, pr)
{

	answer = ans;

}



vector<string> ShortAnswer::get_answer() const 
{
	return answer;
}



void ShortAnswer::writeQuestion(ostream &out) const 
{
	Question::writeQuestion(out);
	out << "______________________________________" << endl;
}


void ShortAnswer::write_key(ostream &out) const 
{
	Question::write_key(out);

	int points = 0;
	points = get_points();
	vector<string> the_answer_short;

	the_answer_short = get_answer();

	out<<"("<<points<<" points)"<<endl;

	for (int i=0; i<the_answer_short.size()-1;i++)
	
	{
		out << the_answer_short[i] << endl;
	
	}
	
	//out <<  << endl;
}