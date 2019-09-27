

Student Name: Ajin Sunny 
Course: CS 315-001 
Assignment: HW6
Date : 2/20/17


———README————

This assignment is focused on the function divide as explained in the textbook. 

The function takes in two n-bit integers and produces an output of quotient and remainder when x is divided by y 

This concept of modular arithmetic is used because when you are repeatedly dividing numbers that very large the time taken for calculation will be exponentially higher. By using the concept of modular arithmetic division you can divide the function faster to produce the output. 

METHOD:
In this assignment I have used the concept of structure to return two values from the whatisit function in the pseudocode. 

I have used structure called pairs with instance of pair that uses x and y and another structure called pair with instance name qr for the quotient and remainder. 

HOW TO COMPILE

Please enter the following in the terminal or putty after you are in the project directory to compile 

g++ -std=c++11 divide.cpp -o divide

HOW TO RUN 

Please enter the following in the terminal or putty after you are in the project directory to compile

./divide<test.txt

where test.txt is the text file to input the necessary numbers. 

