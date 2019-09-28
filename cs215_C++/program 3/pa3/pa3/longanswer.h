#ifndef LONGANSWER_H_INCLUDED
#define LONGANSWER_H_INCLUDED

#include <string>
#include "question.h"

class LongAnswer : public Question

{

public:

	LongAnswer(int points, int chapter, string prompt, string new_answer_txt);
	

	string get_answer_txt() const;

	// Write the question to a file stream.
	void writeQuestion(ostream &out) const;

	// Write the question's key to a file stream.
	void write_key(ostream &out) const;

	
private:
	string answer_txt;
	
};


#endif 