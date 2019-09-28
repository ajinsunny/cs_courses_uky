/*
course: CS216 - 001
Project: Lab Assignment 2
Date: 01/28/15
Purpose: To display a greeting message to the computer screen 
Author: Ajin Sunny

*/

#include <iostream>
#include <fstream>
#include <string>



using namespace std;

int main()

        {
				
                ifstream f("users.txt");
               	if(f.is_open())
                {
		
			string name;
			string t;
			int number_users = 0;
			while(f >> name)
                        {
                                cout <<"Hello, "<< name << '\n';
                        	getline(f,t);
				number_users = number_users + 1 ;

			}
			
			cout<<'\n'<<"The number of users logged on is: "<<number_users<<'\n';


                        f.close();



                }

                else cout <<"Unable to open file";

return 0;

                }


