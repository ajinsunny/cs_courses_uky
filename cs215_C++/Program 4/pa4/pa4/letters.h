/* Name Ajin Sunny
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Helper functions for letters and strings: interfaces.
 */ 

#ifndef LETTERS_H_INCLUDED
#define LETTERS_H_INCLUDED

#include <string>
using namespace std;

// Get a random letter weighted by English letter frequency.
char random_letter();

// Convert a string to uppercase.  Returns a new string.
string uppercase(string input);

#endif

