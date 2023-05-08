#include "Car.h"

#include <iostream>
#include <string>

using namespace std;

Car::Car(double fC, int iF, double tKm)
{
	fuelcost = fC;
	insfee = iF;
	totalkm = tKm;
}

void Car::display()
{
	cout << "Fuel Level: "<< fuelcost << endl;
	cout << "Insurance Fee: " << insfee << endl;
	cout << "Total distance that the car has travelled: " << totalkm << endl << endl;

}

void Car::alterins(string type)
{


	if (type == "SMALL")
	{
		
		insfee += (insfee)*5/100;	
	}

	else if (type == "MEDIUM")
	{
			
		insfee += (insfee)*10/100;
	}
	else if (type == "LARGE")
	{
			
		insfee += (insfee)*20/100;
	
	}
	cout << "Yearly insurance fee is increased to "<< insfee <<" because of the " << type << " accident" << endl;
	

}

void Car::alterkmandfuel(double km)
{
	totalkm += km;
	double cost = (km*(0.25));
	fuelcost -= cost;
	
}


void Car::alterfuel()
{
	fuelcost = 300;
	cout << "Fuel is full" << endl << endl;
}

double Car::fuellevel()
{
	return fuelcost;
}