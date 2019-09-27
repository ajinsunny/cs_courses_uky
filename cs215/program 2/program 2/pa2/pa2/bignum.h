#ifndef BIGNUM_H_INCLUDED
#define BIGNUM_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

class bignum
{
public:
	// Constructors.
	bignum();
	bignum(int num_digits);
	bignum(const string &digits);
	bignum(const bignum &other);

	// Destructors.
	~bignum();

	// Assignment operator.
	bignum &operator=(const bignum &other);

	// Accessors
	int digits() const;
	int as_int() const;
	string as_string() const;
	void print(ostream &out) const;
	bignum add(const bignum &other) const;
	bignum multiply(const bignum &other) const;
	bool equals(const bignum &other) const;

private:
	// Pointer to a dynamically-allocated array of integers.  The last
	// digit (ones place) is stored in digit[0], the next-to last (tens
	// place) in digit[1], and so on.
	int *digit;
	// Number of digits in the array, not counting leading zeros.
	// Should be less than or equal to the allocated size of digit.
	int ndigits;
};


#endif