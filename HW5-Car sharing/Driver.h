#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include <iostream>
#include "Car.h"


using namespace std;

class Driver
{
	public:
		
		Driver::Driver(Car &sC, int m)
		: sharedCar(sC), money(m)
		{ }
	
		void drive(int km);
		void repairCar(string type);
		void display();
		void fullFuel();

	private:
		Car &sharedCar;
		double money;


};


#endif