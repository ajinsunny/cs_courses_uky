/* Name Ajin Sunny
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Helper functions for letters and strings: interfaces.
 */ 




#include "board.h"
#include "letters.h"
#include <iostream>


Board::Board()
{

	 for(int i=0; i<=3; i++)
	 {
		 for(int j=0; j<=3; j++)
		 {

			 char board_letter=random_letter();

			 board_numbers[i][j]=board_letter;

		 }
		
	 }

	 for(int i=0; i<4; i++)
	 {
		 cout<<"+---+---+---+---+";
		 cout<<endl;
		 for(int j=0; j<4; j++)
		 {
			 cout<<"| "<<board_numbers[i][j]<<" ";
			
		 }
		 cout<<"|";
		 cout<<endl;
	}
	 cout<<"+---+---+---+---+";

	
	  //do word search 
	 //if the word is found 
	// Check whether a word occurs on the board.
	//(Private) Recursive helper function for word search.

	 // increment score by n^2  where n is the length of the word.


	
}


bool Board :: findword(string word, int x, int y , int wordpos)
{
	if(wordpos>=word.size())
		return true;

	if(word[wordpos]!=board_numbers[x][y])
		return false;

	for(int i=x-1; i<=x+1;i++)
	{
		if(i<0 || i>3)
			continue;
		for(int j=y-1; j<=y+1; j++)
		{
			if(j<0 || j>3)
				continue;

			//skip the middle
			if(i==x && j==y)
				continue;
			
			if(findword(word, i,j, wordpos+1))
			return true;

		}

	}

	return false;
	
}

//bool Board:: search_grid(string userWord)
//{
//	userWord_index=0;
//	for(int i = 0; i < userWord.length(); i++)
//		userWordLetters[i] = userWord[i];
//
//
//	for(int i=0; i<4; i++)
//	{
//		for(int j=0; j<4; j++)
//		{
//			if(userWordLetters[userWord_index]==board_numbers[i][j])
//			{
//				findword(userWordLetters[userWord_index+1], i , j,userWord_index)
//			}
//		
//		}
//	}
//
//
//
//}

bool Board:: search_grid(string userWord)
{
	
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(findword(userWord,i,j,0))
				return true;
		
		}	
	}
	return false;

}


