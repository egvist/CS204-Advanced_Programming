#ifndef CAR_H
#define CAR_H
#include <string>
#include <iostream>



using namespace std;

class Car
{
	public:
	
		Car(double fC, int iF, double tKm);
	

		void display();

		void alterins(string type);
		void alterkmandfuel(double km);
		void alterfuel();
		double fuellevel();
		


	private:
		double fuelcost;
		int insfee;
		double totalkm;


};


#endif