/* Name
 * CS 215, Fall 2013
 * Programming Assignment 4 - http://www.cs.uky.edu/~neil/215/pa/4/
 * _ November, 2013
 *
 * Helper functions for letters and strings: implementation.
 */ 

#include <cstdlib>
#include <string>
#include <cctype>

using namespace std;

const int NUM_LETTERS = 26;
const char FIRST_LETTER = 'A';

// Percentage frequencies of letters in English.
const double Frequencies[NUM_LETTERS] = {
    8.167, 1.492, 2.782, 4.253, 12.702, // A-E
    2.228, 2.015, 6.094, 6.966, 0.153,  // F-J
    0.772, 4.025, 2.406, 6.749, 7.507,  // K-O
    1.929, 0.095, 5.987, 6.327, 9.056,  // P-T
    2.758, 0.978, 2.360, 0.150, 1.974,  // U-Y
    0.074                               // Z
};

char random_letter()
{
    // Find the sum of all the frequencies.  Might not be 100%
    // because of rounding.
    double sum = 0.0;
    for (int i = 0; i < NUM_LETTERS; i++)
        sum += Frequencies[i];
    
    // The frequencies divide up the range [0, sum) into segments of
    // different lengths:   |----A---|B-|-C-|--D-|------E-----|...

    // We'll generate a random number in that range and see which
    // segment it fell into.

    // Get a double between 0 and sum.
    double rdbl = rand() * sum / (RAND_MAX + 1);
    double cumulative = 0.0;

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        // Cumulative frequency of all the letters so far.
        cumulative += Frequencies[i];

        // If the random number is less than the cumulative frequency
        // (and was greater than or equal to the last cumulative frequency),
        // it fell into the current letter's segment.
        if (rdbl < cumulative)
            return FIRST_LETTER + i;
    }

    // Because of rounding we might not have reached the exact sum, so
    // treat an "overflow" as the last letter.
    return FIRST_LETTER + NUM_LETTERS - 1;
}

string uppercase(string input)
{
    // input is a copy (call-by-value), so we're free to modify it
    for (size_t i = 0; i < input.length(); i++)
    {
        // Convert lowercase letters to upper; leave others unchanged.
        if (islower(input[i]))
            input[i] = toupper(input[i]);
    }
    // Return (a copy of) the now-uppercase parameter.
    return input;
}
