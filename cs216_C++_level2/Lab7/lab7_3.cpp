//course: CS216-002
//Project: Lab Assignment 7
//program: lab7_3.cpp
//Date: 03/24/2015
//Purpose: Use as the lab assignment example
//         get to know standard exceptions: bad_typeid and bad_cast
//Author: Ajin Sunny


#include <iostream>
#include <typeinfo>

using namespace std;

class Vehicle {virtual void member(){}};
class Car : public Vehicle {};
class Truck : public Vehicle {};

int main() {
    Car saturn;
    Truck ford;
    Vehicle vehicle1;
    Car *mycar;
    Truck *histruck;
    Vehicle *yours;
    Car *hers = NULL;
    
    try {
    yours = dynamic_cast<Vehicle *>(&vehicle1);
    cout << typeid(vehicle1).name() << " is: " << typeid(yours).name() <<endl;
    yours = dynamic_cast<Vehicle *>(&ford);
    cout << typeid(ford).name() << " is: " << typeid(yours).name() <<endl;
    yours = dynamic_cast<Vehicle *>(&saturn);
    cout << typeid(saturn).name() << " is: " << typeid(yours).name() <<endl;
    mycar = dynamic_cast<Car *>(&saturn);
    cout << typeid(saturn).name() << " is: " << typeid(mycar).name() <<endl;
    mycar = dynamic_cast<Car *>(&ford);
    cout << typeid(ford).name() << " is: " << typeid(mycar).name() <<endl;
    mycar = dynamic_cast<Car *>(&vehicle1);
    cout << typeid(vehicle1).name() << " is: " << typeid(mycar).name() <<endl;
    cout << typeid(*hers).name() << endl;
    Car& thiscar = dynamic_cast<Car&>(vehicle1);
    }
    catch (bad_typeid &bt)
    {
	cout << "Exception: " << bt.what() << endl;
    }
    catch (bad_cast &bc)
    {	
	cout << "Exception: " << bc.what() << endl;
    }
    return 0;
}
