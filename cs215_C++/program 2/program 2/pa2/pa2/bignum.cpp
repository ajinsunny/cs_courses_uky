
/*
Name: Ajin Sunny
CS 215 Section 2

*/







#include <iostream>
#include <string>
#include<cmath>


using namespace std;
#include "bignum.h"
void pause_215(bool have_newline);
bool test_bignum();


// Method implementations here.
//

/*
bignum()
Description: This is a default constructor used to make a bignum and assign it zero

Input: No input the constructor is just called without any arguments

Output: The constructor gives a bignum of 1 digit and this will be zero

*/
bignum::bignum()
{

	ndigits=1;
	digit = new int[1];
	digit[0] = 0;
	
}

/*
bignum(int ndigits)

Description: This constructor is used to make a bignum of ndigits and it will set all these digits to the number 9

Input: The input parameter for the function is ndigits. This is the number of digits of the bignum.

Output: As usual constrctors does not return anything. But it will create a bignum with ndigits of number 9.

*/

bignum::bignum(int num_digits)
{
	digit = new int[num_digits];
	ndigits = num_digits;
	for (int i = num_digits; i >= 0 ; i--)
	{
		digit[i] = 9;
	}

}

/*
bignum::bignum(const string &digits)

Description: This constructor is used to create a string of bignum. The important part is that this constructor will
			ignore the alphabets present in the numbers with the digits following after the alphabets.

Input: This takes in a string and filters out to give the proper bignum.

Output: Does not return anything. It creates a bignum with alphabets taken off. It will output zero if everything
		given into the constructor is alphabets followed by numbers.

*/

bignum::bignum(const string &digits)
{
	ndigits = 0;

	for (int i = 0; i <= digits.length(); i++)
	{
		if (isdigit(digits[i]))
			ndigits++;
		
	}

	digit = new int[ndigits];
	for(int i=ndigits-1; i>=0; i--)
			digit[i] = (digits[i] - '0');

	//this part is to reverse order.
	/*for(int i =0; i<ndigits/2;i++)
	{

		int first =digit[i];
		int last = digit[ndigits-i-1];
		digit[i] =last;
		digit[ndigits-i-1] = first;
	}*/

	if (ndigits ==0)
	 {
		 ndigits = 1;
		 digit = new int;
		 digit[0] = 0;
	 }

}

/*
~bignum()

Description: Destructs the bignum object.
Input : No input
Output: No output


*/

bignum::~bignum()
{
	delete[] digit;
}




bignum::bignum(const bignum &other)

	{

		ndigits = other.ndigits;


		digit = new int[ndigits];

		for (int i =0 ; i < ndigits; i++)
			digit[i] = other.digit[i];


	}


/*

bignum & bignum::operator=(const bignum &other)

Description: This constructor will create a deep copy of the "other" object without changing aanything on the original 
			array

Inputs : The input will be the object other of type bignum

Output: It will not return or give an output. It will make a deep copy of the digit array

*/
bignum & bignum::operator=(const bignum &other)
{
	if (this == &other)
		return *this;


	delete[] digit;

	ndigits = other.ndigits;
	digit = new int[ndigits];
	for (int i = 0; i < ndigits; i++)
		digit[i] = other.digit[i];

	return *this;
}


/*
int bignum::digits() const

Description: This will just return ndigits to whereand with which bignum object it is being called

Input: No Input

Output: return ndigits of the bignum


*/

// Ordinary (nonmember) functions here.


int bignum::digits() const
{
	
	return ndigits;

}

/*
int bignum::as_int() const

Description : This member function will return the value of the big num as an integer. If the number is too large it is also
				allowed to overflow.

Input: Doesnt take any input 

Output: returns the bignum as an integer to the bignum which is calling this function.

*/

int bignum::as_int() const
{
	int actual_int =0;
	
	for(int i =0; i<ndigits/2;i++){


		int first =digit[i];
		int last = digit[ndigits-i-1];
		digit[i] =last;
		digit[ndigits-i-1] = first;
	}

	for (int i=ndigits-1; i>=0 ; i--)
	{
		actual_int += digit[i] * pow(10,i);
	}

	


	return actual_int;
}

/*
string bignum::as_string() const

Description:  This member funciton returns the sequence of digits as a string to which the bignum object calls it.
				its goes through the bignum and concatinate it to and empty string and return a string.

Input: It doesnt take any input.

Output: Returns a string according to which bignum object calls the method.
				
*/

string bignum::as_string() const
{
	string str = "";

	for( int i=0; i<=ndigits-1 ; i++)
	{
		str= str + char(digit[i] + '0');

	}
	
	return str;

}

/*
void bignum::print(ostream &out) const

Description: This memberfunction is used to print the bignum as a string into the out stream.

Input: Takes in the object to perform outstream.

Output: The function doesn't return anything but it will print the bignum as a string in the out stream.


*/

void bignum::print(ostream &out) const
{

	string outstr = as_string();

	out<<outstr;
		
}

/*
bignum bignum::add(const bignum &other) const

Description: This constructor is used to add two bignums. The process takes place step by step. The numbers are gone
				through by loop and added digit by digit and stored into a final result and returns this result.

Input: It takes in the "other" bignum and adds to the original bignum to which the constructor is being being called.

Output: It returns the sum of two bignums.


*/

bignum bignum::add(const bignum &other) const
{
	int asz = ndigits; //size of the first additive
	int bsz = other.digits(); // size of the second additive

	int longest = 0; // variable to determine longer size for the additive

	if(asz>bsz)
	{
		longest=asz;
	}
	else 
	{
		longest = bsz;
	}

	int carry =0;
	int sum=0;

	int *result = new int[longest+1];

	

	for (int i=0; i<longest+1 ;i++)
	{
		int aa=0;
		int bb=0;

		if(i<asz)
		{
			aa=digit[i];
		}

		if (i<bsz)
		{
			bb=other.digit[i];
		}

		sum = aa+bb+carry;

		int currentdigit=sum%10;

		result[i] = currentdigit;

		carry =sum/10;
	}

	string result_str = "";
	int i=0;
	int j=0;

	while (result[i] == 0)
		{
			i = i +1;
			j=i;
		}

	while(j < longest)
		{
			
			result_str += result[j] +'0';
			j++;

	}

		
	bignum final_result=bignum(result_str);
	delete[] result;
	return final_result;

}

/* 
Description: This contrcutor is used to multiply two bignums. It uses the same algorithims as adding of bignums but in this 
				we use another final bignum and initialize it to zero. Then add each multiplied value into the final bignum. 
				this also includes considering the carry of the added numbers.

Input : It takes in one of multiplcant values and uses it multiply to the bigum to which it was being called at the first point.

Output: The final result returns a bignum which the multiplied value of the two initial bignums.



*/


bignum bignum::multiply(const bignum &other) const
{

	bignum answer;
	bignum ans(ndigits+other.ndigits-1);

	for(int i=other.ndigits-1 ; i>=0 ; i--)
	{
		int carry = 0;

		for(int k=0 ; k<=ndigits+other.ndigits-1 ; k++)
			{
				ans.digit[k] = 0;
			}	
		
						
		for(int j =ndigits-1; j>=0 ;j--)
		{
			int temp = 0;
			temp = digit[j] * other.digit[i] + carry;
			ans.digit[i+j] = temp % 10;
			carry = temp / 10;

						
		}

		answer = answer.add(ans);			
			
	}

	return answer;
}
/*
Description: This member function is used to compare two bignums and check its equality. It checks every digit by digit.
				There is a flag initially set to change the bool values. After everything is compared to equal it returns
				a true bool value.

Input: It takes in the "other" bignum which is to be compared with the bignum with which it was called.

Output:  It returns a bool value which determines the equality of the two bignums.
*/
bool bignum::equals(const bignum &other) const
{
	if (ndigits == other.digits())
	{

		for(int i = 0; i < ndigits; i++) {
			if(digit[i] == other.digit[i])
			{
				return true;	
			}
		}

		return true;
	}

	else {
		return false;
	}
}


int main()
{
	bool success = test_bignum();
	if (success) {
		cout << "All tests succeeded, good job!" << endl;
	} else {
		cout << "Some tests failed, keep trying!" << endl;
	}

	pause_215(false);
	return 0;
}


bool test_bignum()
{
	// Current test number.  Be sure to increment this before each test!
	int curr_test = 0;
	// Number of failed tests.
	int failed = 0;

	// Test 1: do the default constructor and as_string work?
	curr_test++;
	bignum simple;
	if (simple.as_string() != "0") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 2: does the integer constructor work?
	curr_test++;
	bignum nines(9);
	if (nines.as_string() != "999999999") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 3: does the string constructor work (correct input)?
	curr_test++;
	bignum hundred("100");
	if (hundred.as_string() != "100") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 4: does the string constructor work (bad input)?
	curr_test++;
	bignum sixtyfive("65abcd");
	if (sixtyfive.as_string() != "65") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 5: does the string constructor work (all bad input)?
	curr_test++;
	bignum zero("not a number");
	if (zero.as_string() != "0") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 6: does the string constructor work (long input)?
	curr_test++;
	bignum huge("123456789123456789");
	if (huge.as_string() != "123456789123456789") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 7: does the copy constructor work?
	curr_test++;
	bignum copy(sixtyfive);
	if (copy.as_string() != "65") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 8: does the assignment operator work?
	curr_test++;
	simple = hundred;
	if (simple.as_string() != "100") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 9: does the destructor work, and do the copy constructor
	// and assignment operator make deep copies?  A failure is likely
	// to crash the program.
	curr_test++;
	{
		bignum secondcopy(copy);
		bignum thirdcopy(secondcopy);
		bignum newcopy("175");
		thirdcopy = hundred;
		copy = newcopy;
		newcopy = bignum("42");
	}
	if (copy.as_string() != "175" || hundred.as_string() != "100") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 10: does digits() work?
	curr_test++;
	if (hundred.digits() != 3) {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 11: does digits() work (zero)?
	curr_test++;
	if (zero.digits() != 1) {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}


	// Test 12: does multiply() work (no carry)?
	curr_test++;
	bignum multiplicand("123");
	bignum multiplier("12");
	bignum product = multiplicand.multiply(multiplier);

	if (product.as_string() != "1476") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 13: does multiply() work (with carry)?
	curr_test++;
	bignum mc1("963");
	bignum mc2("82");
	bignum mcp = mc1.multiply(mc2);

	if (mcp.as_string() != "78966") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 14: does multiply() work (large numbers)?
	curr_test++;
	bignum mh1("12345678900");
	bignum mh2("98765432100");
	bignum mhp = mh1.multiply(mh2);

	if (mhp.as_string() != "1219326311126352690000") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 15: does multiply() work (numbers starting with zeros)?
	curr_test++;
	bignum mz1("00005");
	bignum mz2("0002");
	bignum mzp = mz1.multiply(mz2);

	if (mzp.as_string() != "10") {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}


	// Test 16: does multiply() work (numbers wuth zeros in between)?
	curr_test++;
	bignum mb1("100001");
	bignum mb2("101");
	bignum mbp = mb1.multiply(mb2);

	if (mbp.as_string() != "10100101") 
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}
	// TODO: add two more tests for multiply() <------------THIS IS DONE Test 15 and 16

	

	// TODO: add four tests each for add(), as_int(), and equals()
	//EQUAL TEST 
	// Test 15: does equal() work (not equal numbers)?
	curr_test++;
	bignum eq1("123");
	bignum eq2("987");
	if (eq1.equals(eq2)==true)
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 16: does equal() work (equal numbers)?
	curr_test++;
	bignum eq3("123");
	bignum eq4("123");
	if (eq3.equals(eq4)==false)
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

		// Test 17: does equal() work (equality in numbers and letters)?
	curr_test++;
	bignum eq5("123");
	bignum eq6("abc");
	if (eq5.equals(eq6)==true)
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 18: does equal() work (are reversed equal numbers equal)?
	curr_test++;
	bignum eq7("123");
	bignum eq8("321");
	if (eq7.equals(eq8)==true)
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	//ADD TEST

	// Test 19: does add() work (numbers without carry)?
	curr_test++;
	bignum add1("123");
	bignum add2("111");
	bignum tot_add12 = add1.add(add2);

	if (tot_add12.as_string() != "234") 
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}


	// Test 20: does add() work (numbers with carry)?
	curr_test++;
	bignum add3("987");
	bignum add4("654");
	bignum tot_add34 = add3.add(add4);

	if (tot_add34.as_string() != "234") 
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 21: does add() work (numbers with alphabets)?
	curr_test++;
	bignum add5("987");
	bignum add6("abc");
	bignum tot_add56 = add5.add(add6);

	if (tot_add56.as_string() != "987") 
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 22: does add() work (numbers with numbers and alphabets)?
	curr_test++;
	bignum add7("987");
	bignum add8("a1b2c34564");
	bignum tot_add78 = add7.add(add8);

	if (tot_add78.as_string() != "987") 
	{
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	//AS_INT TEST

	// Test 23: does the as_int() work (correct input)?
	curr_test++;
	bignum hundred1("100");
	if (hundred1.as_int() != 100) {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 24: does the as_int() work (huge number)?
	curr_test++;
	bignum huge1("99999999999");
	if (huge1.as_int() != 99999999999) {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 25: does the as_int() work (alphabet input)?
	curr_test++;
	bignum alpha("abc");
	if (alpha.as_int() != 0) {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}

	// Test 26: does the as_int() work (leading zeros with alphabets input)?
	curr_test++;
	bignum num_alpha("0001abc");
	if (num_alpha.as_int() != 1) {
		cerr << "Test " << curr_test << " failed." << endl;
		failed++;
	}



	return (failed == 0);
}

/* pause_215() - Wait for the user to press ENTER.
*
* Description: 
*   Optionally read and discard the remainder of the user's last
*   line of input.  Then, prompt the user to press ENTER, then
*   read and discard another line of input.
*
* Inputs:
*   bool have_newline:
*     True if the user has already entered a newline that the
*     program has not yet read.  If true, this function first
*     discards remaining input up to and including that newline.
*
*   Reads two lines from standard input if have_newline is true,
*   one line if it is false.  Lines are assumed to be less than
*   two hundred characters long.
*
* Outputs:
*   No return value.
*
*   Prints a prompt to standard output.
*
* Notes:
*   This function is intended to be used at the end of a program,
*   just before returning from main().  Reading another line of
*   input prevents the console window from closing immediately.
*
*   In general, have_newline should be true if the last user input
*   from cin used the extraction operator (>>), and false if there
*   has been no user input or if the last input used getline().
*/
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