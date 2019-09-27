#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class Question {
public:
	Question(int pt, int chap, string pr);
	virtual int get_points() const;
	void set_points(int pts);
	int get_chapter() const;
	void set_chapter(int chap);
	string get_prompt() const;
	

	// Write the question to a file stream.
	virtual void writeQuestion(ostream &out) const;
	// Write the question's key to a file stream.
	virtual void write_key(ostream &out) const;
private:
	int points;
	int chapter;
	string prompt;
};



#endif