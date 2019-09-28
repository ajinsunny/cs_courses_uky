/*
 *CS 216 -002 
 Programming Assignment - No 1
 Purpose : The purpose of this program is to call the student information 
            by using the student ID number

          The user still has the option to quit when ever the prompt is running 
 *
 * Author: Ajin Sunny
 * Date : 02/15/15
 *
 * */


#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(int argc, char *argv[])

{
    const	string student_ID = argv[1];  // variables assigned for reading in the command line arguments
	const   string sec1 = argv[2];
    const	string sec2 = argv[3];
    const	string student_courses = argv[4];

	ifstream f1;                  // files being opened in ifstream
    f1.open(sec1.c_str());
	ifstream f2;
    f2.open(sec2.c_str());
	ifstream f3;
    f3.open(student_courses.c_str());
	if (f1.is_open())
	{
		string ID_fromfile; // declaring variables for reading words from the file 
		string first_name;
		string last_name;
        while (!f1.eof())   // Looping through the enitre first section 
        {
	        
        f1>>ID_fromfile;   // reading word by word from the file 
        f1>>last_name;
        f1>>first_name;
        f1.ignore(256,'\n'); // after reading the first name ignoring the rest of the line including students major which is not required 

		if(ID_fromfile == student_ID) // At this point the users input matches the ID read from the file 
				{
			  		cout<<endl;
                    cout<<"Student number: "<<ID_fromfile<<endl;          // Display the students details 
					cout<<"Name: "<<last_name<<","<<first_name<<endl;
					cout<<"Section: day-time"<<endl;
					if(f3.is_open())
					{
						string ID;
						string course;
						while(!f3.eof())  // Looping over the studentscourses.txt file to find the matching courses for the students 
						{
							f3>>ID;  
							if(ID==student_ID) // When the student ID matches with the ID in the third file the courses are read out from the file
							{
								f3>>course;
								cout<<course<<endl;

							}
						}	
                    if(course == "")
                    {
				    cout<<"This student is not taking any course"<<endl<<endl;  // When nothing matches from the third file the student 
                    }    
					}


					
				}



		}
    }

	
	else{
	    cout<<"sec1students.txt cannot be opened"<<endl; // if file is not found then this will be displayed

		}	
	
	if (f2.is_open()) // Checking if the file is opening or not 
		{
	        	string ID2_fromfile;
                string first_name2;
                string last_name2;

            while (!f2.eof()) // Looping over the entire section 2 of the students roster
            {
               
	    	    f2>>ID2_fromfile;
                f2>>last_name2;
                f2>>first_name2;
                f2.ignore(256,'\n');

		        if (ID2_fromfile == student_ID)
			    {
                   
				    cout<<endl;
                    cout<<"Student number: "<<ID2_fromfile<<endl;
                    cout<<"Name: "<<last_name2<<","<<first_name2<<endl;
                    cout<<"Section: evening"<<endl;

					if(f3.is_open()) // opening the courses file to match the input ID with the ID in the course file 
                                        {
                                                string ID2;
                                                string course2;

                                                while(!f3.eof()) //Looping over the course file to find the match 
                                                {
                                                        f3>>ID2;
                                                        if(ID2==student_ID) // When the student ID match is found...
                                                        {
                                                                f3>>course2;
                                                                cout<<course2<<endl;  // Courses for that corresponding student is printed out

                                                        }
                                                      
                                                }      
                                                       
                                             if(course2 == "")
                                             {    
                                               cout<<"This student is not taking any course"<<endl; // When the student is not taking any coures
                                                    
                                             }
                                               
                                               
                                        }


			    }		

		    }
        } 

f1.close(); //Closing all the files after its use

f2.close();

f3.close();

return 0;

}
