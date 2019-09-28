/*

Name: Ajin Sunny
Date: 2/20/17
Course: CS315-001
Assignment: HW6 - Divide function

HOW TO COMPILE 

g++ -std=c++11 divide.cpp -o divide

HOW TO RUN

./divide<test.txt

*/


#include<iostream>
using namespace std;


struct pairs{

        int x;
        int y;

};

struct pairs whatisit(struct pairs pair)

{

	if(pair.x==0)
		{
		pair.y=0;
		return pair;
		}

	struct pairs qr; 
	
	pair.x = pair.x/2;
		
	qr = whatisit(pair);

	qr.x=qr.x*2;
	qr.y=qr.y*2;

	if(pair.x%2==1)
		{
			qr.x=qr.y+1;
		}
	if(qr.x>=qr.y)
	{
		qr.y=qr.y-pair.y;
		qr.x=qr.x+1;
	}
	
	return qr;

}




int main()

	{
		int n;
		struct pairs nums;
		nums.x = 0;
		nums.y = 0;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>nums.x;
			cin>>nums.y;
			nums = whatisit(nums);
			cout<<nums.x<<nums.y<<endl;

		}
		
		return 0;
		
	}

