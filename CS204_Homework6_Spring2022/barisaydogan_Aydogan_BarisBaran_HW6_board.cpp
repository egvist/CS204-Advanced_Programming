#include <iostream>
#include <string>
#include <iomanip>
#include "barisaydogan_Aydogan_BarisBaran_HW6_board.h"

using namespace std;


//Parametric Constructor
template <class T>
Board<T>::Board(int r, int c)
{
	rows = r;
	cols = c;
	matrix = new structBoard<T>*[r];
	for (int i = 0; i<r; i++)
	{
		matrix[i] = new structBoard<T>[c];
	}

	for (int i = 0; i<r; i++)
	{
		for (int j = 0; j<c; j++)
		{
			matrix[i][j].player = 0;
			
		}
	}

}

//Destructor
template <class T>
Board<T>::~Board()
{
	delete [] matrix;
	matrix = nullptr;
}


//Deep Copy Constructor
template <class T>
Board<T>::Board(const Board<T> & b)
{
	// Getting the rows and cols of given board class 
	rows = b.rows;
	cols = b.cols;
	// Creating a new matrix for deep copy
	matrix = new structBoard<T>*[rows];
	for (int i = 0; i<rows; i++)
	{
		matrix[i] = new structBoard<T>[cols];
	}
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			//Assign the given values of player and values of given board class to the new deep copy class
			matrix[i][j].player = b.knowTheOwner(i,j);
			matrix[i][j].value = b.knowTheChar(i,j);
		}
	}
}


template <class T>
T Board<T>::knowTheChar(int rows, int cols) const //make it const because I dont want it to change anything here
{
	return matrix[rows][cols].value;

}

template <class T>
void Board<T>::displayBoard()
{
	// I used formating (setw) while displaying the cells
	cout << "Displaying the board: Each cell is shown as tuple (CURRENT OWNER ID, VALUE):"<<endl;
	for (int i = 0; i<cols; i++)
	{
		
		if (i == 0)
		{
			cout<<setw(12)<<right<<i ;
		}
		else
		{
			cout<<setw(12)<<right<<i ;
		}
		
	
	}
	cout << endl;
	
	for (int i = 0; i<rows; i++)
	{
		cout << setw(8) << left <<  i ;
		
		for (int j = 0; j<cols; j++)
		{
			
			cout << setw(2) <<"(" << matrix[i][j].player << "," << setw(2) << matrix[i][j].value << ")" << setw(5) <<" ";
		
			
			
		}
		
		cout << endl;
	}

}

template <class T>
void Board<T> :: updateBoardCells(int ID, T rep)
{
	// It moves one by one in the cell and if given 'id' is equal to the a cell's id than it changes the value with 'rep'
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			
			if (matrix[i][j].player == ID)
			{
				matrix[i][j].value = rep;
			}
		}
		
	}

}

template <class T>
int Board<T>::getPlayerCellsCount(int ID)
{
	int owns = 0; // Counter
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<cols; j++)
		{
			// If it finds an occurence than counter increment
			if (matrix[i][j].player == ID)
			{
				++owns;
			}
		}
		
	}
	return owns;

}

template <class T>
int Board<T>::knowTheOwner(int rows, int cols) const
{

	return matrix[rows][cols].player;

}

template <class T>
void Board<T>::updateCellinBoard(int rows,int cols, T v)
{
	//Change the given (row,col) value with 'v'
	matrix[rows][cols].value = v;
	
}

template <class T>
void Board<T>::updateOwnerCellinBoard(int rows, int cols, int p)
{
	//Change the given (row,col) player with 'p'
	matrix[rows][cols].player = p;
}

template <class T>
void Board<T>::unclaimOwnerCellinBoard(int rows, int cols)
{
	//Change the given (row,col) player with '0'
	matrix[rows][cols].player = 0;
}


template <class T>
int Board<T>::getRows()
{
	return rows;
}


template <class T>
int Board<T>::getCols()
{
	return cols;
}