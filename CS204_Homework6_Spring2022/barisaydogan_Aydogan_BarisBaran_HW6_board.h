#ifndef _BOARD_H
#define _BOARD_H
#include <iostream>
#include <string>

using namespace std;


template<class T>
struct structBoard
{
	int player;
	T value;

};

template<class T>
class Board
{
	private:
		int rows;
		int cols;
		structBoard<T> **matrix; 

	public:

		Board(int rows, int cols); //Parametric Constructor
		Board(const  Board<T> & b);  //Deep Copy Constructor
		~Board(); //Destructor
		void displayBoard();
		void updateBoardCells(int ID, T rep);
		int getPlayerCellsCount(int ID);
		int knowTheOwner(int rows, int cols) const;
		T knowTheChar(int rows, int cols) const; // To learn the char in the given (row,col)
		void updateCellinBoard(int rows, int cols, T v); // Make given (row,col) value 'v'
		void updateOwnerCellinBoard(int rows, int cols, int p); // Make given (row,col) player 'p'
		void unclaimOwnerCellinBoard(int rows, int cols); // Make given (row,col) player 0
		int getRows(); // Getter func
		int getCols(); // Getter func

};
#include "barisaydogan_Aydogan_BarisBaran_HW6_board.cpp"
#endif
