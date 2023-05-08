#include <iostream>
#include "header.h"
#include <string>
#include <fstream>

using namespace std;





void Print(DynamicStringStack& myStack)
{
	string value;
	string funcName;
	DynamicStringStack reverseStack;
	cout << "PRINTING THE STACK TRACE:" << endl;
	if(myStack.isEmpty())
	{
		
		cout << "The Stack is empty!" << endl;
	}
	else
	{
		while(!myStack.isEmpty())
		{
			myStack.pop(value,funcName);
			reverseStack.push(value,funcName);
		}

	}

	while (!reverseStack.isEmpty())
	{
		reverseStack.pop(value,funcName);
		cout << funcName << " " << value << endl;
		myStack.push(value,funcName);
	
	}


}







void addStudentRequest(linkedlist &list, DynamicStringQueue &queue)
{
	string func;
	string studentName;
	int studentID;
	cout << "Add a service <function> that the student wants to use:" << endl;
	cin >> func;
	func = func + ":";
	if (list.findFunc(func))
	{
		cout << "Give student's name: ";
		cin >> studentName;
		cout << "Give student's ID <an int>: ";
		cin >> studentID;
		queue.enqueue(studentID, studentName, func);
		cout << studentName << "'s service request of " << func << " has been put in the student's queue." << endl;
		cout << "Waiting to be served..." << endl;
		list.puttheposback();
	}
	else 
	{
		cout << "The requested service <function> does not exist." << endl;
		cout << "GOING BACK TO MAIN MENU" << endl;
	}
	

}

void addInstructorRequest(linkedlist &list, CircularQueue &queuel)
{
	string func;
	string InstructorName;
	int InstructorID;
	cout << "Add a service <function> that the Instructor wants to use:" << endl;
	cin >> func;
	func = func + ":";
	if (list.findFunc(func))
	{
		cout << "Give Instructor's name: ";
		cin >> InstructorName;
		cout << "Give Instructor's ID <an int>: ";
		cin >> InstructorID;
		queuel.addToEnd(InstructorID, InstructorName, func);
		cout << "prof." <<InstructorName << "'s service request of " << func << " has been put in the Instructor's queue." << endl;
		cout << "Waiting to be served..." << endl;
		list.puttheposback();
		
	}
	else 
	{
		cout << "The requested service <function> does not exist." << endl;
		cout << "GOING BACK TO MAIN MENU" << endl;
	}
	

}

void processARequest(string functionName, linkedlist &mainList, DynamicStringStack &commonStack)
{
	DynamicStringStack temp;
	string dummy1;
	string dummy2;
	mainList.putposfunc(functionName);
	while (true)
	{
		
		string prop = mainList.getfuncProperties();
		
		if ( prop.substr(0,6) == "define")
		{
			
			commonStack.push(prop,functionName);
		}
		else if ( prop.substr(0,4) == "call")
		{
			
			
			cout << "Calling " <<prop.substr(5,10) << " from " << functionName.substr(0,10) << endl;
			processARequest(prop.substr(5,10)+":", mainList, commonStack);
			mainList.changetheorder();
			
		}
		else if (prop.substr(0,5) == "print")
		{
			
			Print(commonStack);
			
		}
		else if (prop == "final")
		{
			break;
		}

		
	}	
	
	while (commonStack.topfunc(commonStack) == functionName)
	{
		commonStack.pop(dummy1,dummy2);
		if (commonStack.isEmpty())
		{
			break;
		}
	
	}

	cout << functionName.substr(0,10) << "is finished. Clearing the stack from it's data..." << endl;
	cout << endl;
	system("pause");
	if (commonStack.isEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	
	

	
}

void processARequest(CircularQueue &queueInstructors, DynamicStringQueue &queueStudent, linkedlist &mainList, DynamicStringStack &commonStack )
{

	if (!queueInstructors.isEmpty())
	{
		
		cout << "Processing prof." << queueInstructors.name() << "'s request <with ID " << queueInstructors.number() << "> of service <function>:" << endl;
		cout << queueInstructors.funcN() << endl;
		processARequest(queueInstructors.funcN(), mainList, commonStack );
		queueInstructors.clearList();
		

	
	}
	if (!queueStudent.isEmpty())
	{
		
		string value1;   // Dummy variable for dequeue
		string value2;	 // Dummy variable for dequeue
		int ivalue2;
		cout << "Processing " << queueStudent.name() << "'s request <with ID " << queueStudent.number() << "> of service <function>:" << endl;
		cout << queueStudent.funcD() << endl;
		processARequest(queueStudent.funcD(), mainList, commonStack);
		queueStudent.dequeue(ivalue2, value1, value2);
		if (!queueStudent.isEmpty())
		{
			string value1;   // Dummy variable for dequeue
			string value2;	 // Dummy variable for dequeue
			int ivalue2;
			cout << "Processing " << queueStudent.name() << "'s request <with ID " << queueStudent.number() << "> of service <function>:" << endl;
			cout << queueStudent.funcD() << endl;
			processARequest(queueStudent.funcD(), mainList, commonStack);
			queueStudent.dequeue(ivalue2, value1, value2);
		}
		
	
	}

	else
	{

		cout << "Both instructor's and student's queue is empty.\nNo request is processed." << endl <<"GOING BACK TO MAIN MENU" <<endl;
	}
}

int main()
{
	DynamicStringStack commonStack = DynamicStringStack();
	DynamicStringQueue queueStudent = DynamicStringQueue();
	CircularQueue queueInstructors = CircularQueue();
	
	linkedlist mainList;
	char input;
	string filename;
	string fileContent;
	cout << "If you want to open a service <function> defining file, then press <Y/y> for 'yes', otherwise press any single key" << endl;
	cin >> input;


	
	while (input == 'Y' || input == 'y')
	{
		
		cout << "Enter the input file name: ";
		cin >> filename;
		ifstream file;
		file.open(filename.c_str());
		if (!file)
		{
			cout << "File failed to open." << endl;
			exit(3);
			return 3;
	
		}
		else 
		{
			int count = 0;
			while (getline(file, fileContent))
			{
				
				if (count == 0)
				{
					mainList.addToRight(fileContent);
					count += 1;
					
				}
				else 
				{
					mainList.addToDown(fileContent);
				
				}

	
			}
			
		}
		file.close();
		cout << "If you want to open a service <function> defining file, then press <Y/y> for 'yes', otherwise press any single key" << endl;
		cin >> input;
		
	}
	mainList.puttheposback();
	mainList.printList();

	while (true)
	{
		cout << endl;
		cout<<"**********************************************************************"<<endl
			<<"**************** 0 - EXIT PROGRAM *************"<<endl
			<<"**************** 1 - ADD AN INSTRUCTOR SERVICE REQUEST *************"<<endl
			<<"**************** 2 - ADD A STUDENT SERVICE REQUEST *************"<<endl
			<<"**************** 3 - SERVE (PROCESS) A REQUEST *************"<<endl
			<<"**********************************************************************"<<endl;
		cout << endl;
		int option;
		cout << "Pick an option from above (int number from 0 to 3): ";
		cin>>option;
		switch (option)
		{
			case 0:
				cout<<"PROGRAM EXITING ... "<<endl;
				commonStack.cleartheStack();
				queueStudent.clear();
				queueInstructors.clearList();
				system("pause");
				exit(0);
			case 1:
				addInstructorRequest(mainList, queueInstructors);
				
				break;
			case 2:
				addStudentRequest(mainList, queueStudent);
				
				break;
			case 3:
				processARequest(queueInstructors, queueStudent, mainList, commonStack);
				

				break;
			default:
			cout<<"INVALID OPTION!!! Try again"<<endl;
		}
	}

	return 0;

}