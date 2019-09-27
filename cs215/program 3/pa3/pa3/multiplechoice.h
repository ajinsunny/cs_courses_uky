#ifndef MULTIPLECHOICE_H_INCLUDED
#define MULTIPLECHOICE_H_INCLUDED

#include <vector>
#include <string>

#include "question.h"

class MultipleChoice : public Question

{

public:

	MultipleChoice(int points, int chapter,int n_choice, string prompt , char c_choice, vector<string> choices);

	int get_nchoice() const;

	string get_goodchoice () const;

	void write_key(ostream &out) const;

//	vector <string> get_chioces () const;
	

private:
	int num_choice;  /*This will accept the number of choices from the question pool file and store it in n_choice*/
	string c_choice;	/*This will be the correct choice for the multiple choice question */
	vector <string> answerchoice; /* This will be vector will have the choices */

	

};



#endif