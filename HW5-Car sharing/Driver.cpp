#include "Car.h"
#include "Driver.h"
#include <iostream>
#include <string>

using namespace std;

void Driver::drive(int km)
{
	
	sharedCar.alterkmandfuel(km);

}


void Driver::repairCar(string type)
{
	if (type == "SMALL")
	{
		money -= 50;
		cout << "50$ is reduced from the driver's budget because of SMALL accident" << endl;
		sharedCar.alterins(type);
	}

	else if (type == "MEDIUM")
	{
		money -= 150;
		cout << "150$ is reduced from the driver's budget because of MEDIUM accident" << endl;
		sharedCar.alterins(type);
	}
	else if (type == "LARGE")
	{
		money -= 300;
		cout << "300$ is reduced from the driver's budget because of LARGE accident" << endl;
		sharedCar.alterins(type);
	
	}
	else
	{
		cout << "Wrong Input!!!" << endl;
	}

}

void Driver::display()
{
	cout << "Driver Budget: " << money << "$" << endl;

}

void Driver::fullFuel()
{
	double initialfuel = sharedCar.fuellevel();
	money -= (300-initialfuel);
	sharedCar.alterfuel();

}