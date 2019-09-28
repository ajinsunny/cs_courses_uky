/* Name
 * CS 215, Fall 2013
 * Programming Assignment 3 - http://www.cs.uky.edu/~neil/215/pa/3/
 * _ October, 2013
 *
 * Prototypes for helper functions.
 */ 
#ifndef PA3_H_INCLUDED
#define PA3_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

void pause_215(bool have_newline);
int letter_to_index(char c);
char index_to_letter(int i);



vector<string> split_string(string input);

#endif
