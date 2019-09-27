#ifndef WORDLIST_H_INCLUDED
#define WORDLIST_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
//#include "game.h"

using namespace std;


class Wordlist
{

public:
	Wordlist(string wordlistfile);
	bool search_dictionary(string word);


private:

	bool binary_search(vector<string> &dictionarywords , string userword, int start, int end);
	vector<string> dictionaryWords;
	string userWord;
	int start;
	int end;


};



#endif


