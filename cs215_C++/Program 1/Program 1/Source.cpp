#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
}


string sequence;

string read_sequence()

	{
		cout<<"Please enter an RNA uppercase sequence : ";
		cin>>sequence;
}

int num_codons()
{
	int len = sequence.length();

	int no_codons = len/3;

	return no_codons;

}

