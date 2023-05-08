#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct courseNode
{
	string courseCode, courseName;
	vector<string> studentsAttendingIDs;
	courseNode *next;


};



void DisplayList (courseNode * head)
{
	cout << endl;
	courseNode * ptr = head;
    while (ptr != NULL) 
	{
		int IDsize = ptr->studentsAttendingIDs.size();
		cout << ptr ->courseCode << " " << ptr ->courseName << ": ";
		for (int i = 0; i < IDsize; i++)
		{
			cout << ptr->studentsAttendingIDs[i] << " ";
		}
		cout << endl;
		
		
		ptr = ptr->next;
	}
	cout << endl;
}

void DisplayListFinal (courseNode * head)
{
	
	courseNode * ptr = head;
    while (ptr != NULL) 
	{
		int IDsize = ptr->studentsAttendingIDs.size();
		cout << ptr ->courseCode << " " << ptr ->courseName << ": ";
		for (int i = 0; i < IDsize; i++)
		{
			cout << ptr->studentsAttendingIDs[i] << " ";

		}
		if (IDsize < 3)
		{
			cout << "-> This course will be closed " << endl; 
		
		}
		else
		{
		cout << endl;
		}
		
		ptr = ptr->next;
	}
	cout << endl;
}


courseNode * Add(courseNode * head, string courseCode_m, string courseName_m, string StudentsID)
{
	courseNode * ptr = head;



	if (head == NULL || courseName_m[0] < head->courseName[0])
	{
		courseNode * temp = new courseNode;
		temp->courseCode = courseCode_m;
		temp->courseName = courseName_m;
		temp->studentsAttendingIDs.push_back(StudentsID);
		temp->next = head;
	
		return temp;

	}

	while ((ptr->courseCode != courseCode_m))
	{
		ptr = ptr->next;
	}

	if (ptr->courseCode == courseCode_m)
	{
		bool InOrOut = find(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end(), StudentsID) != ptr->studentsAttendingIDs.end();
		if (InOrOut == false)
		{
			ptr->studentsAttendingIDs.push_back(StudentsID);
		}
		sort(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end());

		return head;
	}

	while ((ptr->next != NULL) && (ptr->next->courseName[0] <= courseName_m[0]))
	{
		ptr = ptr->next;
	}

	if ((ptr->next == NULL) || (ptr->courseName[0] > courseName_m[0]))
	{
		courseNode * temp = new courseNode;
		temp->courseCode = courseCode_m;
		temp->courseName = courseName_m;
		temp->studentsAttendingIDs.push_back(StudentsID);
		temp->next = ptr->next;
		ptr->next = temp;
		sort(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end());
		return head;
	}

	return 0;

}

courseNode * Drop(courseNode * head, string courseCode_m, string courseName_m, vector<string> StudentsID)
{
	courseNode * ptr = head;

	while ((ptr->next != NULL) && (ptr->courseCode != courseCode_m))
	{
		ptr = ptr->next;
	
	}

	if (ptr->courseCode == courseCode_m)
	{
	
		int IDSsize = StudentsID.size(); 
		for (int i= 0; i< IDSsize; i++)
		{
			
			bool isV = (find(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end(), StudentsID[i]) != ptr->studentsAttendingIDs.end());
			if (isV)
			{
				ptr->studentsAttendingIDs.erase(remove(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end(), StudentsID[i]),ptr->studentsAttendingIDs.end());
				cout << "Student with id " << StudentsID[i] << " has dropped " << ptr->courseCode << "." << endl;
				
		
			}
			else if (!isV)
			{

				cout << "Student with id " << StudentsID[i] << " is not enrolled to " << ptr->courseCode << ", thus he can't drop that course." << endl;
			}
		}
		return head;
	}
	
	else if (ptr->next == NULL)
	{
		int IDSsize = StudentsID.size();
		for (int i= 0; i< IDSsize; i++)
		{
			cout << "The " << courseCode_m << " course is not in the list, thus student with id " << StudentsID[i] << " can't be dropped." << endl;
		}

		return head;
	}
	return 0;

}

courseNode * Add2(courseNode * head, string courseCode_m, string courseName_m, vector<string> StudentsID)
{
	courseNode * ptr = head;


	while ((ptr->next != NULL) && (ptr->courseCode != courseCode_m))
	{
		ptr = ptr->next;
	}

	if (ptr->courseCode == courseCode_m)
	{
		

		int IDSsize = StudentsID.size();
		for (int i = 0; i< IDSsize; i++)
		{
			
			if (find(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end(), StudentsID[i]) != ptr->studentsAttendingIDs.end())
			{
				cout << "Student with id " << StudentsID[i] << " is already enrolled to " << ptr->courseCode << ". No action taken." << endl;

			}
			else
			{
				ptr->studentsAttendingIDs.push_back(StudentsID[i]);
				cout << "Student with id " << StudentsID[i] << " is enrolled to " << ptr->courseCode <<"." << endl;
			}
		
		}

		sort(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end());

		return head;
	}

	courseNode *ptr2 = head;
	
	while ((ptr2->next != NULL) && (ptr2->next->courseName[0] <= courseName_m[0]))
	{
		ptr2 = ptr2->next;
	}
	if ((ptr2->next == NULL) || (ptr2->courseName[0] >= courseName_m[0]))
	{
		courseNode * temp = new courseNode;
		temp->courseCode = courseCode_m;
		temp->courseName = courseName_m;
		temp->studentsAttendingIDs = StudentsID;
		temp->next = ptr2->next;
		ptr2->next = temp;
		cout << courseCode_m << " does not exist in the list of Courses. It is added up." << endl;
		int IDSsize = StudentsID.size();
		for (int i = 0; i< IDSsize; i++)
		{
			
			cout << "Student with id " << StudentsID[i] << " is enrolled to " << temp->courseCode <<"." << endl;
			
		}
		
		sort(temp->studentsAttendingIDs.begin(), temp->studentsAttendingIDs.end());
		return head;
	}
	sort(ptr->studentsAttendingIDs.begin(), ptr->studentsAttendingIDs.end());
	return 0;


}



int main()
{


	int choice;

	string filename, StudentID_main, fileDataLine;
	ifstream file;
	string courseCode_main, courseName_main;
	courseNode * temp = NULL;
	courseNode * head = NULL;
	
	cout << "Please enter the filename: ";
	cin >> filename;
	
	

	
	file.open(filename);
	
	cout << "Successfully opened file " << filename << endl;
	
	while (file)
	{
		getline(file, fileDataLine);


		int index_firstSpace = fileDataLine.find(' ');
		int index_secondSpace = fileDataLine.find(' ', index_firstSpace+1);
		string courseCode_main = fileDataLine.substr(0,index_firstSpace);
		int len_of_courseName =  index_secondSpace - index_firstSpace-1;
		string courseName_main = fileDataLine.substr(index_firstSpace+1, len_of_courseName);
		string StudentID_main = fileDataLine.substr(index_secondSpace+1, 5);

		
		head = Add(head, courseCode_main, courseName_main, StudentID_main);
		
		
		

	}
	cout << "The linked list is created." << endl;
	cout << "The initial list is: " << endl;
	DisplayList(head);
	


	string addingelements, droppingelements;
	cout << "Please select one of the choices: " << endl;
	cout << "1. Add to List\n2. Drop from List\n3. Display List\n4. Finish Add/Drop and Exit" << endl;
	cin >> choice;

	while (choice != 4)
	{

		if (choice == 1)
		{
			cout << "Give the student ID and the course names and course codes that he/she wants to add:" << endl;
			cin.ignore();
			getline(cin, addingelements);
			cout << endl;
			string courseCode;
			string courseName;
			vector<string> stuId;
			int count = 0;
			int prevind = 0; 
			int element_Size = addingelements.size();
			for (int i = 0; i < element_Size; i++)
			{

				if (addingelements[i] == ' ')
				{
					count += 1;


					if (count == 1)
					{   
						
						courseCode = addingelements.substr(prevind,i-prevind);

 
						prevind = i+1;

			
					}
					else if (count == 2)
					{

						courseName = addingelements.substr(prevind,i-prevind);

						prevind = i+1;

						if ((addingelements.size()-(i+1)) < 6)
						{
							stuId.push_back(addingelements.substr(i+1,5));

							head = Add2(head, courseCode, courseName, stuId);
							stuId.clear();
							courseCode.clear();
							courseName.clear();
							
						
						}
				
				
				
					}
					else if (count > 2)
					{
	

						bool is = (int(addingelements[i+1]) >= 65) && (int(addingelements[i+1]) <= 90);
						if (is)
						{

							stuId.push_back(addingelements.substr(prevind,i-prevind));

							count = 0;
							prevind = i+1;

							head = Add2(head, courseCode, courseName, stuId);
							stuId.clear();
							courseCode.clear();
							courseName.clear();
						}
						else
						{


							stuId.push_back(addingelements.substr(prevind,i-prevind));
							

							prevind = i+1;

							if ((addingelements.size()-(i+1)) < 6)
							{
								stuId.push_back(addingelements.substr(i+1,5));

								head = Add2(head, courseCode, courseName, stuId);
								stuId.clear();
								courseCode.clear();
								courseName.clear();
							
						
							}
						}
			
					}
					
				}
	
			}
			
			
		}
		else if (choice == 2)
		{
			cout << "Give the student ID and the course names and course codes that he/she wants to add:" << endl;
			cin.ignore();
			getline(cin, droppingelements);
			cout << endl;
			string courseCode;
			string courseName;
			vector<string> stuId;
			int count = 0;
			int prevind = 0; 
			int element_Size = droppingelements.size();
			for (int i = 0; i < element_Size; i++)
			{

				if (droppingelements[i] == ' ')
				{
					count += 1;


					if (count == 1)
					{   
						
						courseCode = droppingelements.substr(prevind,i-prevind);


						prevind = i+1;

			
					}
					else if (count == 2)
					{

						courseName = droppingelements.substr(prevind,i-prevind);

						prevind = i+1;

						if ((droppingelements.size()-(i+1)) < 6)
						{
							stuId.push_back(droppingelements.substr(i+1,5));
							head = Drop(head, courseCode, courseName, stuId);
							stuId.clear();
							courseCode.clear();
							courseName.clear();
							
							
						}
				
				
				
					}
					else if (count > 2)
					{
	

						bool is = (int(droppingelements[i+1]) >= 65) && (int(droppingelements[i+1]) <= 90);
						if (is)
						{

							stuId.push_back(droppingelements.substr(prevind,i-prevind));
							count = 0;
							prevind = i+1;
							head = Drop(head, courseCode, courseName, stuId);
							stuId.clear();
							courseCode.clear();
							courseName.clear();
						}
						else
						{


							stuId.push_back(droppingelements.substr(prevind,i-prevind));
							

							prevind = i+1;
							if ((droppingelements.size()-(i+1)) < 6)
							{
								stuId.push_back(droppingelements.substr(i+1,5));
								head = Drop(head, courseCode, courseName, stuId);
								stuId.clear();
								courseCode.clear();
								courseName.clear();
							
							
							}
						}
			
					}
					
				}
	
			}
			
		
		}

		else if (choice == 3)
		{

			cout << "The current list of course and the students attending them: " << endl;
			DisplayList(head);
		}

		cout << "Please select one of the choices: " << endl;
		cout << "1. Add to List\n2. Drop from List\n3. Display List\n4. Finish Add/Drop and Exit" << endl;
		cin >> choice;

	}
	if (choice == 4)
	{
		cout << "The add/drop period is finished. Printing the final list of courses and students attending them." << endl;
		cout << "NOTE: Courses with less than 3 students will be closed this semester." << endl;
		DisplayListFinal(head);
		delete head;
	}
	
	

	
	
	file.close();

	
	return 0;
}