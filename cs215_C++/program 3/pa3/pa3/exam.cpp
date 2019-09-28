#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include <stdlib.h>
#include <sstream>
#include "exam.h"
#include "multiplechoice.h"
#include "shortanswer.h"
#include "longanswer.h"
#include "pa3.h"
using namespace std;



Exam::Exam()
{

}


Exam::Exam(int min_ch, int max_ch, int num_question)
{

	minchap = min_ch;
	maxchap = max_ch;
	n_question = num_question;


	//string str;
	//ifstream fin;
	//fin.open(qp_filename);
	//getline(fin,str);
	//parse_question(str);
		
}

void Exam::shuffle()

{
	random_shuffle(qlist.begin(),qlist.end());
}



int str2int(const string & input)
{
	istringstream in (input);
	int result;
	in>>result;
	if (in.fail())
		return 0;

	return result;

}




//parsing the question 
Question *parse_question(string line)
{
	vector<string> parts = split_string(line);
	string type = parts[0];
	int points = str2int(parts[1]);
	int chapter = str2int(parts[2]);
	string prompt = parts[3];

	if(type=="multiple")
	{


		int num_choices = str2int(parts[4]);
		char correct = parts[5][0];
		vector<string> choices;
		//unsigned int j=6;
		for (int i =0; i <num_choices; i++)
		{
			choices.push_back(parts[6+i]);
		}


		return new MultipleChoice(points, chapter , num_choices,prompt,correct,choices);
	}

	else if(type =="short")
	{
		vector<string> answers;
		for(unsigned int i=4; i<=parts.size()-1;i++)
		{
			answers.push_back(parts[i]);

		}
		return new ShortAnswer(points, chapter, prompt,answers);
		

	}

	else if(type =="long")
	{
		string ans;
		for(unsigned int i=4; i<=parts.size()-1; i++)
		{
			ans+=parts[i]+"\n";
		}

		return new LongAnswer(points, chapter, prompt,ans);

	}

}

void Exam::set_qlist(vector<Question *> &pushed_qlist)
{
	
	int range = pushed_qlist.size()-1;
	for (int i=0; i<=range; i++)
		{
						
			//qlist[i] = pushed_qlist[i];
			qlist.push_back(pushed_qlist[i]);

		}


}


bool Exam::read_questions(string qp_filename)
{
	ifstream fin;

	fin.open(qp_filename);

	bool complete = false;

	vector<Question *> temp_question;

	string ln;

	

	while(!fin.eof())
	{
		
		getline(fin,ln);
		/*vector<string> split_vector;
		split_vector = split_string(ln);
		int minimum = get_minchap();
		int maximum = get_maxchap();
		int read_chapter_num = str2int(split_vector[2]);
		if (read_chapter_num>=minimum && read_chapter_num<=maximum)
		{*/
			temp_question.push_back(parse_question(ln));
		//}

				
	}

	
	set_qlist(temp_question);

	complete = true;
	return complete;
	

}

bool Exam::writeExam(string filename) const
{
	ofstream fout;

	fout.open(filename);

	for(unsigned int i=0; i<=qlist.size()-1; i++)
	{
		qlist[i]->writeQuestion(fout);
		
		fout<<endl;

	}
	fout.close();

	return true;
}


bool Exam::write_key(string filename) const
{
	ofstream fout;

	fout.open(filename);

	for(unsigned int i=0; i<=qlist.size()-1; i++)
	{
		qlist[i]->write_key(fout);

		fout<<endl;

	}
	fout.close();

	return false;


}















