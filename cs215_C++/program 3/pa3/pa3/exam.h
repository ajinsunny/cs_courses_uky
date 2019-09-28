#ifndef EXAM_H_INCLUDED
#define EXAM_H_INCLUDED

#include <string>
#include <vector>
#include "question.h"
#include "multiplechoice.h"
#include "shortanswer.h"
#include "longanswer.h"
using namespace std;

/*
Handled by the constructor:
	Set the minimum and maximum chapter.
	Read a list of questions from a question pool file (keeping only questions from the correct chapters).
Get the number of questions.
Randomly shuffle the order of questions.
Trim the exam to a given number of questions (by removing everything after the first n).
Write the exam to an file.
Write the key to a file.
*/
class Exam 
{
public:
	// This constructor should read the question pool.
	Exam();
	Exam(int min_ch, int max_ch, int num_question);
	

	// Alternatively, we could have the constructor take only
	// the chapter numbers, and use a method to read from the
	// input file.  This depends in part on where in main you
	// define the exam object, and what information you have
	// at that point in the program.
	//Exam(int minchap, int maxchap);
	//bool read_questions(string qp_filename);

	int get_no_questions();
	int get_maxchap();
	int get_minchap();
	
	// Or we could use mutator methods for everything.
	//Exam();
	//void set_min_chapter(int min);
	//void set_max_chapter(int max);
	bool read_questions(string qp_filename);

	void set_qlist(vector<Question *> & pushed_qlist);

	void shuffle();

	// Could return bool (were there enough questions?)
	void trim(int num_qs);

	// These could take ostreams instead; then main would be
	// responsible for opening the output files.  These methods
	// return true for success, false for failure.
	bool writeExam(string filename) const;
	bool write_key(string filename) const;
private:
	// PRIVATE helper method (internal use only; to be called from
	// the constructor)
	
	// List of (pointers to) questions.
	vector<Question *> qlist;
	// Minimum and maximum chapters.
	int minchap;
	int maxchap;
	int n_question;

};



#endif 