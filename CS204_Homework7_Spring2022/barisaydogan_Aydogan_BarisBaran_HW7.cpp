#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "barisaydogan_Aydogan_BarisBaran_HW7_myfuncs.h"
#include <random>
#include <time.h>
using namespace std;

mutex mutex1, mutex2,mutex3, mutex4;
HW7PrintQueue printer; // Shared printer declared as global variable
int id = 1;
int max_print = 0; //I had to declare max_print as global because functions must use it like friend function
int count_gen = 0; //Same as above

int random_range(const int & min, const int & max) {
 static mt19937 generator(time(0));
 uniform_int_distribution<int> distribution(min, max);
 return distribution(generator);
}


void generate_printjobs(int min, int max, int min_sec, int max_sec, int user)
{
	//Declaring count variable for 3 users. It helps me to understand the time that they create their first print job.
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	
	
	while (count_gen < max_print)
	{
		
		count_gen++;
		// If first print job, then it has to wait/sleep for a random time range
		if ((user == 0 && count1 == 0) || (user == 1 && count1 == 0) || (user == 2 && count1 == 0))
		{
			int sec = random_range(min_sec,max_sec);
			this_thread::sleep_for(chrono::seconds(sec));
		}
		//Mutex is locked because, I will increase a variable
		mutex1.lock();
		if (user == 0)
		{
			count1++;
		}
		
		else if (user == 1)
		{
			count2++;
		}
		else 
		{
			count3++;
		}
		// Mutex2 is kind a general mutex that holds cout and enqueuing
		mutex2.lock();
		mutex1.unlock();

		// Special mutex for just enqueuing 
		mutex3.lock();
		int sec = random_range(min_sec,max_sec);
		int num = random_range(min,max);
		
		printer.enqueue(id,num);
		mutex3.unlock();
		
		
		time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
		struct tm *ptm = new struct tm;
		localtime_s(ptm, &tt);
		cout << "User " << user << " sent new print job with ID " << id << " sent to the printer queue, number of pages: " << num << " (printer queue size: " << printer.getCurrentSize() << " ) " << put_time(ptm,"%X") << endl ;
		id++;
		mutex2.unlock();
		
		//After creating print job, it has to sleep for a random time
		this_thread::sleep_for(chrono::seconds(sec));
	}
	
}

void printer_dequeue()
{
	//Printer waits thread for 1 sec
	this_thread::sleep_for(chrono::seconds(1));
	int id_num;
	int pages;
	while(!printer.isEmpty())
	{
		// Special dequeuing mutex here. This mutex prevent possible error
		mutex1.lock();
		time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
		struct tm *ptm = new struct tm;
		localtime_s(ptm, &tt);
		
		printer.dequeue(id_num,pages);
		// cout mutex here.
		mutex2.lock();
		cout << "The printer started to print the job with ID: " << id_num << ", number of pages: " << pages << "(queue size is: " << printer.getCurrentSize() << ") " << put_time(ptm,"%X") << endl;
		mutex1.unlock();
		

		
		

		mutex2.unlock();
		// Printer is printing pages and it has to wait 1 sec for each pages so it has wait pages sec time. And also extra 1 sec for after printing whole pages.
		this_thread::sleep_for(chrono::seconds(pages));
		this_thread::sleep_for(chrono::seconds(1));
		
		// cout mutex here.
		mutex4.lock();
		cout <<	"The printer finished printing the job with ID: " << id_num << ", number of pages: " << pages << " " << put_time(ptm,"%X") << endl;
		mutex4.unlock();
	}


}

int main()
{
	int max_pages;
	int min_pages;
	int max_val_waiting;
	int min_val_waiting;
	int max_num_print;
	cout << "Please enter the max number of print jobs: ";
	cin >> max_num_print;
	cout << "Please enter the min and max values for the waiting time period (in seconds) after creating a print job:" << endl;
	cout << "Min: ";
	cin >> min_val_waiting;
	cout << "Max: ";
	cin >> max_val_waiting;
	cout << "Please enter the min and max values for the number of pages in a print job:" << endl;
	cout << "Min number of pages: ";
	cin >> min_pages;
	cout << "Max number of pages: ";
	cin >> max_pages;
	
	
	time_t tt = chrono::system_clock::to_time_t (chrono::system_clock::now());
	struct tm *ptm = new struct tm;
	localtime_s(ptm, &tt);
	cout << "Simulation starts " << put_time(ptm,"%X") << endl;


	

	max_print = max_num_print;
	thread printer_thread(&printer_dequeue);
	thread user1(&generate_printjobs,min_pages,max_pages,min_val_waiting,max_val_waiting,1);
	thread user2(&generate_printjobs,min_pages,max_pages,min_val_waiting,max_val_waiting,2);
	thread user3(&generate_printjobs,min_pages,max_pages,min_val_waiting,max_val_waiting,3);
	


	user1.join();
	user2.join();
	user3.join();
	printer_thread.join();
	

	
	
	

	if (printer.isEmpty())
	{
		time_t tt2 = chrono::system_clock::to_time_t (chrono::system_clock::now());
		struct tm *tmm = new struct tm;
		localtime_s(tmm, &tt2);
		cout << "End of the simulation ends " << put_time(tmm,"%X") << endl;
	}



}