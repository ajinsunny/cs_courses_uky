#ifndef SHORTANSWER_H_INCLUDED
#define SHORTANSWER_H_INCLUDED

#include <vector>
#include <string>
using namespace std;
#include "question.h"

class ShortAnswer : public Question 
{
public:

	ShortAnswer(int pt, int chap, string pr,const vector<string> &ans);

	vector<string> get_answer() const;

	// Write the question to a file stream.
	void writeQuestion(ostream &out) const;
	// Write the question's key to a file stream.
	void write_key(ostream &out) const;
private:

	vector<string> answer;
};






#endif