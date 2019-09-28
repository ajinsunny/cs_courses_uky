/* Name Ajin Sunny
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Helper functions for letters and strings: interfaces.
 */ 



#include <iostream>
#include "game.h"
#include "wordlist.h"
#include "board.h"
#include "letters.h"



Game::Game(string wordlistfile)
	 :w(wordlistfile),b()
 {
	score = 0;
	user_input="";
	misses = 0;
	
 }

	 
  void Game::game_over()
 {
	 cout<<"GAME OVER !!!" <<endl;
	 cout<<"Your score was : "<<score;
	 cout<<"Your Words were : ";
	 for (unsigned int i=0; i < usedWords.size(); i++)
	 {
		 cout<<usedWords[i]<<",";
		 
	 }

	 
 }

 bool Game::is_ended()
 {
	 if(misses>4||user_input == "q")
	 {
		 return false;
	 }

 }


 bool Game::whether_legal(string word)
 {
	 bool flag = false;

	 if(w.search_dictionary(word))
	 {
		 flag=true;

	 }

	 if(b.search_grid(word))
	 {
		flag=true;
	 }

	 else
	 {
		 cout<<"I cannot find that word on the board"<<endl;

	 }


	 for(int i=0; i <usedWords.size(); i++)
	 {

		 if(usedWords[i]==word)
		 {
			 continue;
		 }

		 else
		 {
			 flag=false;
		 }

	return flag;
		
	 }

 }
 
 
void Game::take_turn()
 {
	

	cout<<"Score : " <<score;
	cout<<"		Misses : "<<misses<<"/5"<<endl<<endl;
	
	 
	for(unsigned int i=0; i<usedWords.size(); i++)
	 {
		 cout<<"Your Words : " << usedWords[i];
	 }


	
	cout<<"Please enter the word you think you found on the grid  : ";
	getline(cin,user_input);
	while(cin.fail())
	{
		cout<<"Its not a legal word"<<endl;

		cin.clear();
		cin.ignore(200,'\n');


	}

	string new_user_input=uppercase(user_input);
	usedWords.push_back(new_user_input);

	int n=new_user_input.length();


	if(new_user_input != "Q")
	{

		if(whether_legal(new_user_input))
		{
			score+=(n*n);
		}

		else
		{
			misses+=1;
		}

	}

	cout<<"  "<<endl;


	//if(w.search_dictionary(user_input))
	//{
	//	cout<<"It is a good word";
	//	
	//}
	//else
	//	{
	//		cout<<"Word not found in the dictionary";
	//		misses+=1;
	//	}
	//	
	//


	//if(b.search_grid(user_input))
	//{
	//	cout<<"Found the word";
	//	score += (n*n);
	//}
	//
	//else
	//{

	//cout<<"Word not found ! ";
	//misses+=1;

	//}

}





 






