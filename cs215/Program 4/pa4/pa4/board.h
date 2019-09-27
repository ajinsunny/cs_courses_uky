#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
//#include "game.h"

using namespace std;


class Board
{

	public:
		Board();
		bool search_grid(string word);
	
		
		
	private:
		char board_numbers[4][4];
		int userWord_index;
		bool findword(string word, int x, int y , int wordpos);




};



#endif