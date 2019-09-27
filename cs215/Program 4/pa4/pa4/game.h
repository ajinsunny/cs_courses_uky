/* Name Ajin Sunny
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Helper functions for letters and strings: interfaces.
 */ 



#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "wordlist.h"
#include "board.h"

using namespace std;


class Game
{
	public:

		Game(string wordlistfile);

		void take_turn();
		bool is_ended();
		void game_over();

		bool whether_legal(string word);

	private:
		Wordlist w;
		Board b;
		int score;
		int misses;
		string user_input;
		vector<string> usedWords;

};

#endif