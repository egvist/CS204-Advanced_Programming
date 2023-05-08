#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>
#include "randgen.h"
#include "randgen.cpp"

using namespace std;

void PrintReal(const vector<vector<char>> & GameArena) // This function is for the developer (debugging) and also for the end of the game screen, to show every position of the bombs and the neighbours numbers etc.
{
    for (int j=0; j < GameArena.size(); j++)
    {
		cout << endl;
		for (int k=0; k < GameArena[0].size(); k++)
        {
			cout << setw(4) << GameArena[j][k];
        }
        cout << endl;
    }
	cout << endl;
}
void PrintUser(const vector<vector<char>> & UserGameArena) // UserGameArena is for the player itself. Players' decisions change it. Therefore, PrintUser is the printing func for the UserGameArena
{
    for (int j=0; j < UserGameArena.size(); j++)
    {
		cout << endl;
		for (int k=0; k < UserGameArena[0].size(); k++)
        {
			cout << setw(4) << UserGameArena[j][k];
        }
        cout << endl;
    }
	cout << endl;
}

char WhatIsInside(vector<vector<char>> & GameArena, int xRow, int yCol) // This function is for the 2nd choice, to see how many neighbours bomb does the cell has.
{
	int neighbourbombCount = 0; // counting first as int and then converting it to char by using char(+48).
	// Looking every possible neighbours and if find bomb(s) then increase the count.
	if ((xRow != 0) && (xRow != (GameArena.size()-1)))
	{
		if ((yCol !=0) && (yCol != (GameArena[0].size()-1)))
		{
			if (GameArena[xRow-1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}
		else if (yCol == 0)
		{
			if (GameArena[xRow-1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);

		}
		else if (yCol == (GameArena[0].size()-1))
		{
			if (GameArena[xRow-1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}
	}



	else if (xRow == 0)
	{
		if (yCol == (GameArena[0].size()-1))
		{

			if (GameArena[xRow][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}
		else if (yCol == 0)
		{
			if (GameArena[xRow][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}

		else
		{


			if (GameArena[xRow][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow+1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}
	}


	else if ((xRow == GameArena.size()-1))
	{
		if ((yCol == GameArena[0].size()-1))
		{
			if (GameArena[xRow-1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}
		else if ((yCol == 0))
		{
				if (GameArena[xRow-1][yCol] == 'B')
				{
					neighbourbombCount += 1;
				}
				if (GameArena[xRow-1][yCol+1] == 'B')
				{
					neighbourbombCount += 1;
				}
				if (GameArena[xRow][yCol+1] == 'B')
				{
					neighbourbombCount += 1;
				}
				return char(48+neighbourbombCount);
		}

		else
		{
			if (GameArena[xRow-1][yCol] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol-1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow-1][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			if (GameArena[xRow][yCol+1] == 'B')
			{
				neighbourbombCount += 1;
			}
			return char(48+neighbourbombCount);
		}
	}
	return char(48+neighbourbombCount);

}

void InstallBombsandNeighbours(vector<vector<char>> & GameArena, int nBombs) // This function fill the all of the matrixes with bombs neighbour counts. Actually, using it for PrintReal func.
{
	// Putting bombs on a random position by using RandGen.
    RandGen myRandom;
    while (nBombs > 0)
    {

        int RanColIndex, RanRowIndex;
        RanRowIndex = myRandom.RandInt(0,GameArena.size()-1);
        RanColIndex = myRandom.RandInt(0,GameArena[0].size()-1);
        if (GameArena[RanRowIndex][RanColIndex] == 'X')
        {
            GameArena[RanRowIndex][RanColIndex] = 'B';
            nBombs -= 1;
        }
    }
	for (int j= 0; j < GameArena.size(); j++)
	{
		for (int k=0; k < GameArena[0].size(); k++)
		{
			int neighbourbombCount = 0;
			if(GameArena[j][k] != 'B')
			{
				if ((j != 0) && (j != (GameArena.size()-1)))
				{
					if ((k !=0) && (k != (GameArena[0].size()-1)))
					{
						if (GameArena[j-1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}
					else if (k == 0)
					{
						if (GameArena[j-1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);

					}
					else if (k == (GameArena[0].size()-1))
					{
						if (GameArena[j-1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}
				}



				else if (j == 0)
				{
					if (k == (GameArena[0].size()-1))
					{

						if (GameArena[j][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}
					else if (k == 0)
					{
						if (GameArena[j][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}

					else
					{


						if (GameArena[j][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j+1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}
				}


				else if ((j == GameArena.size()-1))
				{
					if ((k == GameArena[0].size()-1))
					{
						if (GameArena[j-1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}
					else if ((k == 0))
					{
							if (GameArena[j-1][k] == 'B')
							{
								neighbourbombCount += 1;
							}
							if (GameArena[j-1][k+1] == 'B')
							{
								neighbourbombCount += 1;
							}
							if (GameArena[j][k+1] == 'B')
							{
								neighbourbombCount += 1;
							}
							GameArena[j][k] = char(48+neighbourbombCount);
					}

					else
					{
						if (GameArena[j-1][k] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k-1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j-1][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						if (GameArena[j][k+1] == 'B')
						{
							neighbourbombCount += 1;
						}
						GameArena[j][k] = char(48+neighbourbombCount);
					}
				}
			}
		}
	}

}

int main()
{
    int InputRow, InputCol, nBombs, choice, xRow, yCol;
	int number_of_moves = 0;
    cout << "Please enter the number of row and columns: ";
    cin >> InputRow >> InputCol;
    vector<vector<char>> GameArena(InputRow, vector<char>(InputCol,'X'));
	vector<vector<char>> UserGameArena(InputRow, vector<char>(InputCol,'X'));




    cout << "How many bombs: ";
    cin >> nBombs;
    while( (nBombs >= (InputRow*InputCol)) || (nBombs < 1) )
    {
        if (nBombs >= (InputRow*InputCol))
        {
            cout << "The number of bombs cannot be greater than the whole number of cells minus one. Please give the number of bombs again: ";
            cin >> nBombs;
        }
        else if (nBombs < 1 )
        {
            cout << "The number of bombs could not be less than one. Please give the number of bombs again: ";
            cin >> nBombs;
        }

    }

    InstallBombsandNeighbours(GameArena, nBombs); // Putting Bombs and calculating neighbours numbers.
	PrintUser(UserGameArena); // Showing the game area.
	cout << "Press:" << endl << endl;
	cout << "1. If you want to find out the surrounding of a cell\n\n2. If you want to open the cell\n\n3. If you want to exit."<< endl;

	do
	{
		cout << endl;
		cin >> choice;
		cout << endl;
		if ((choice < 4) && (choice > 0))
		{
			if (choice == 1)
			{
				cout << "Give the coordinates: ";

				do
				{
					cin >> xRow >> yCol;
					cout << endl << endl;
					if (((xRow >= 0) && (xRow < UserGameArena.size())) && ((yCol >= 0) && (yCol < UserGameArena[0].size())))
					{
						cout << "Displaying the surrounding of (" << xRow << "," << yCol << "): " << endl;
						UserGameArena[xRow][yCol] = WhatIsInside(GameArena,xRow,yCol);
						PrintUser(UserGameArena);
						cout << "Around (" << xRow<< "," << yCol << ") you have " << WhatIsInside(GameArena,xRow,yCol) << " bomb(s)" << endl<<endl<<endl;
						UserGameArena[xRow][yCol] = 'X';
						break;
					}
					else
					{
						cout << "It is out of range. Please give a valid coordinates: ";
						cin.clear(); // Using it because compiler sticking the first error and not continuing anymore.
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Using numeric_limits to prevent overprinting (If not using it, compiler prints the error messages the length of the input times.)
						continue;
					}

				}
				while(true);
			}
			else if (choice == 2)
			{
				cout << "Give the coordinates: ";
				cin >> xRow >> yCol;
				cout << endl << endl;
				cout << "Opening cell (" << xRow << "," << yCol << "): " << endl;
				UserGameArena[xRow][yCol] = GameArena[xRow][yCol];
				PrintUser(UserGameArena);
				if (UserGameArena[xRow][yCol] == 'B')
				{
					cout <<	"Unfortunately, you stepped on a mine" << endl << endl;
					cout << "Arrangement of mines:" << endl << endl;
					PrintReal(GameArena);
					cout << endl;
					cout << ">>>>> Game Over! <<<<<"<< endl;
					break;
				}
				else
				{
					number_of_moves += 1; // number of moves if equal to total number of "X" - nBombs, than there is no place to player can choice except the bombs.
					if (number_of_moves == (((InputRow*InputCol)-nBombs)))
					{
						cout << "Congratulations! All the non-mined cells opened successfully" << endl << endl;
						cout << "You won!" << endl << endl;
						cout << ">>>>> Game Over! <<<<<" << endl;
						break;
					}

				}

			}
			else if (choice == 3)
			{
				cout << "Program exiting ..." << endl;
				break;
			}
			cout << "Press:" << endl << endl;
			cout << "1. If you want to find out the surrounding of a cell\n\n2. If you want to open the cell\n\n3. If you want to exit."<< endl;
		}

		else
		{
			cout << "Your input is wrong. Please select one of the options: 1, 2 or 3." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Using numeric_limits to prevent overprinting (If not using it, compiler prints the error messages the length of the input times.)
			continue;
		}
	}
	while ((choice != 3) || !(cin >> choice) );



	return 0;

}
