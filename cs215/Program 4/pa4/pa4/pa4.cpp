/* Name
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Driver program for WordGrid game.
 */ 

#include <iostream>
#include "board.h"
#include "game.h"
#include <ctime>

using namespace std;

void pause_215(bool have_newline);

int main()
{
	
	cout<<"WordGrid by Ajin Sunny - CS 215 PA4"<<endl;
	cout<<"Bonus features implemented: none"<<endl;


	
	// TODO: seed the RNG
	srand(time(NULL));

    /* Depending on how you design your Game class, your main
     * function could be as simple as the following:*/
	

	Game game("wordlist.txt");

    while (!game.is_ended())
    {

        game.take_turn();
    }
    game.game_over();
     
     

    pause_215(false);
    return 0;
}

void pause_215(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(200, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}

