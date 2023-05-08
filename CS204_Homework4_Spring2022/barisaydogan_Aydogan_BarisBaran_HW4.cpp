#include <iostream>
# include <string>
#include <fstream>
#include "barisaydogan_Aydogan_BarisBaran_HW4_myfuncs.h"
using namespace std;


int main()
{
	DynStack container;
	string filename;
	ifstream myfile;
	do
    {
        cout << "Please enter the file name: ";
        cin >> filename;
        myfile.open(filename);
		if (myfile.fail())
		{
			cout << "File not found." << endl;
		
		}
    } while (myfile.fail());
	
	string line;
	int linenum = 1;
	bool notabreak = true;
	char popsym;
	int popline;
	while (getline(myfile,line))
	{
		char nn;

		int i = 0;
		
		while((notabreak != false)&& i < line.size())
		{
			if(container.isEmpty() && ( line[i] == '(' || line[i] == '{' || line[i] == '[' ))
			{
				container.push(line[i],linenum);
				cout << "Found the opening symbol " << line[i] << " at line " << linenum << endl;
			}
			else if(!container.isEmpty() && ( line[i] == '(' || line[i] == '{' || line[i] == '[' ))
			{
				container.push(line[i],linenum);
				cout << "Found the opening symbol " << line[i] << " at line " << linenum << endl;
			}
			else if(container.isEmpty() && ( line[i] == ')' || line[i] == '}' || line[i] == ']' ))
			{
				container.push(line[i],linenum);
				cout << "ERROR!!! Found the closing symbol " << line[i] << " but there are no unclosed opening symbols!" << endl;
				notabreak = false;
				
			}
			else if(!container.isEmpty() && ( line[i] == ')' || line[i] == '}' || line[i] == ']' ))
			{
				container.pop(popsym,popline);
				if(line[i] == ')' )
				{
					if(popsym == '(')
					{
						cout << "Found the closing symbol " << line[i] << " at line " << linenum << " which closes the opening symbol " << popsym << " at line " << popline << endl;
					}
					else
					{
						cout << "ERROR!!! Found the closing symbol " << line[i] << " at line " << linenum << " but the last unclosed opening symbol is " << popsym << " at line " << popline << endl;
						container.~DynStack();
						notabreak = false;
						
					}
				}
				else if(line[i] == '}')
				{
					if(popsym == '{')
					{
						cout << "Found the closing symbol " << line[i] << " at line " << linenum << " which closes the opening symbol " << popsym << " at line " << popline << endl;
					}
					else
					{
						cout << "ERROR!!! Found the closing symbol " << line[i] << " at line " << linenum << " but the last unclosed opening symbol is " << popsym << " at line " << popline << endl;
						container.~DynStack();
						notabreak = false;
						
					}
				}
				else if(line[i] == ']')
				{
					if(popsym == '[')
					{
						cout << "Found the closing symbol " << line[i] << " at line " << linenum << " which closes the opening symbol " << popsym << " at line " << popline << endl;
					}
					else
					{
						cout << "ERROR!!! Found the closing symbol " << line[i] << " at line " << linenum << " but the last unclosed opening symbol is " << popsym << " at line " << popline << endl;
						container.~DynStack();
						notabreak = false;
						
					}
				}
				
			}
			i++;
		}
		++linenum;
		i = 0;
	}
	if(!container.isEmpty())
	{
		container.pop(popsym,popline);
		if (popsym == '(' || popsym == '{' || popsym == '[' )
		{
			cout << "ERROR!!! The following opening symbols were not closed:" << endl;
			cout << "	Symbol " << popsym << " at line " << popline << endl;
			while(!container.isEmpty())
			{
				container.pop(popsym,popline);
				cout << "	Symbol " << popsym << " at line " << popline << endl;
			
			}
		}
		else
		{
			container.~DynStack();
		}
	}
	else if (notabreak != false)
	{
	cout << "File processed successfully. No errors were found." << endl;
	}

	return 0;
}