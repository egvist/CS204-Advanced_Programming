#include <iostream>
#include <string>
#include "barisaydogan_Aydogan_BarisBaran_HW6_player.h"

using namespace std;



template <class T>
bool Player<T>::updateCell(int rows, int cols, T value)
{
	// Using board member func to learn the owner of cell and if cell's owner is id or none
	if ( id == board.knowTheOwner(rows,cols) || board.knowTheOwner(rows,cols) == 0 )
	{
		// then change the cell's value and owner with given parameters by using another board member func (updateCellinBoard, updateOwnerCellinBoard)
		board.updateCellinBoard(rows, cols, value);
		board.updateOwnerCellinBoard(rows,cols,id);
		return true;
	}
	else
	{
		return false;
	}

}

template <class T>
void Player<T>:: updateMyCells(T v)
{
	//Using board member func to change given id's cells value with 'v'
	board.updateBoardCells(this->id, v);

}

// Using board member func to unclaiming ownership for single cell
template <class T>
bool Player<T>::unclaimOwnership(int rows, int cols)
{
	if(id == board.knowTheOwner(rows,cols))
	{
		board.unclaimOwnerCellinBoard(rows,cols);
		
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void Player<T>::unclaimOwnerships()
{
	int r= board.getRows();
	int c = board.getCols();
	int id_i = this->id;
	
	for (int i=0; i< r; i++)
	{
		
		for (int j=0; j< c; j++)
		{
			
			if(id_i == board.knowTheOwner(i,j))
			{
				
				board.unclaimOwnerCellinBoard(i,j);
				
			}
			
			
		}
	}
}