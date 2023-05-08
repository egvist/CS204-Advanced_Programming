#ifndef _PLAYER_H
#define _PLAYER_H
#include <iostream>
#include <string>
#include "barisaydogan_Aydogan_BarisBaran_HW6_board.h"

using namespace std;

template<class T>
class Player
{

	public:
		Player(Board<T> & b)
			:board(b), id(next_id) 
		{next_id++;}
		bool updateCell(int , int , T);
		void updateMyCells(T);
		bool unclaimOwnership(int , int );
		void unclaimOwnerships();

	private:
		int id;
		static int next_id;
		Board<T> & board;
	


};

template<class T> 
int Player<T>::next_id = 1;
#include "barisaydogan_Aydogan_BarisBaran_HW6_player.cpp"
#endif
