/* Name Ajin Sunny
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Helper functions for letters and strings: interfaces.
 */ 


#include "wordlist.h"
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>


#include <iostream>



Wordlist::Wordlist(string wordlistfile)
{

	end = dictionaryWords.size();
	start = 0;
	ifstream fin;
	fin.open(wordlistfile);

	string line;
	cout<<"Loading wordlist.txt . . .";

	while(!fin.eof())
	{
		getline(fin,line);
		dictionaryWords.push_back(line);

	}

	cout<<" Found 62887 words."<<endl;
		

}



bool Wordlist::binary_search(vector<string> &dictionarywords , string userword, int start, int end)
{
	if(start>end)
	{return false;}

	int middle = (start+end)/2;

	if(userword == dictionarywords[middle])
	{
		return true;	
	}

	else if (userword<dictionarywords[middle])
	{

		return binary_search(dictionarywords, userword, start, middle-1);

	}

	else 
	{
		return binary_search(dictionarywords, userword, middle+1,end);
	}


}

bool Wordlist::search_dictionary(string word)
{
	
	return binary_search(dictionaryWords, word, 0, dictionaryWords.size()-1);
	
}