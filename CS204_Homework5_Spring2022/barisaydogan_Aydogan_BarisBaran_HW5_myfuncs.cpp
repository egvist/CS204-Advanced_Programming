#include <iostream>
#include <string>
#include <sstream>
#include "barisaydogan_Aydogan_BarisBaran_HW5_myfuncs.h"

using namespace std;


//Default Constructor
Deck::Deck()
{
	dyDeck = NULL;
	size = 0;
}

//Destructor
Deck::~Deck()
{
	
	size = 0;
}

//Deep Copy Constructor
Deck::Deck(const Deck & dck)
{
	//Checking whether deck is empty
	if (dck.dyDeck == nullptr)
	{
		dyDeck = nullptr;
		size = 0;
	}
	else
	{
		//Creating a temporary dynamic array to store copied elements
		Card * temp = new Card[dck.size];
		for(int i = 0; i< dck.size; i++)
		{
			temp[i] = dck.dyDeck[i];
		}
		//Assigning temporary dynamic array to copied deck's dynamic array and changing the size according to the real size
		dyDeck = temp;
		size = dck.size;
	}

}



Deck Deck::operator +=(const Deck & deck)
{
	//Storing new size here and creating a temporary dynamic array with elements until we reach the end of the real array
	int new_size = size + deck.size;
	Card *temp = new Card[new_size];
	for(int i = 0; i< size; i++)
	{
		temp[i] = dyDeck[i];
	}
	//Appending the rhs deck's dynamic array elements to the temporary dynamic array
	for(int i = 0; i< deck.size; i++)
	{
		temp[size+i] = deck.dyDeck[i];
	}
	//Deleting the previous one because I'll assign new dynamic array and I'll change the size with the new one.
	delete [] dyDeck;	
	dyDeck = temp;
	size = new_size;
	return *this;
}


Deck Deck::operator +(const Card & card)
{
	//Creating a copy for lhs Deck
	Deck deckObj(*this);
	int exsize = deckObj.size;
	deckObj.size = deckObj.size+1;
	//Again, creating temporary array to store previous dyn array elements and appending the new Card obj inside of it.
	Card *temp = new Card[deckObj.size];
	if(exsize != 0)
	{

		for (int i = 0; i<exsize; i++)
		{
			temp[i] = deckObj.dyDeck[i];

		}
		temp[exsize] = card;
		
		delete [] deckObj.dyDeck;
		deckObj.dyDeck = temp;
		
	}
	//If there is no element in lhs Deck then it assign card as a first element of the temporary dyn array
	else
	{
		temp[0] = card;
		deckObj.dyDeck = temp;

		
		
	}
	// Returning copied deck
	return deckObj;
	
	
	
	
}

Deck Deck ::operator - (int n_cards)
{
	//Creating a deep copy for lhs
	Deck new_Deck(*this);

	//If n_cards is greater or equal to size of Deck, then it will return empty Deck
	if(new_Deck.size <= n_cards)
	{
		Deck Empty;
		return Empty;
	}

	//If n_cars is NOT greater or equal to size of Deck, then temporary dyn array is created with new size (size-n_cards)
	else
	{
		Card *temp = new Card[new_Deck.size - n_cards];
		// Starting to pass the values from i-n_cards, it maintain to delete (not actually delete but tricky delete) desired number of cards from the array
		for(int i = n_cards; i < new_Deck.size; i++)
		{
			temp[i-n_cards] = new_Deck.dyDeck[i];
		}
		// Deleting previous one and assign the new temporary as a real one.
		delete [] new_Deck.dyDeck;
		new_Deck.dyDeck = temp;
		new_Deck.size = new_Deck.size - n_cards;
		return new_Deck;
	
	}

}

Deck Deck::operator = (const Deck & deck)
{
	//Deleting lhs dynamic array and make it same with rhs array and size and returning the lhs Deck.
	delete [] this->dyDeck;
	this->size = deck.size;
	this->dyDeck = deck.dyDeck;
	return *this;

}

bool operator >(const Deck & deck,int n_cards)
{
	//Using a getter func to get size of a deck and compare it with n_cards
	if ( deck.get_size() > n_cards)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Comparing total energy of rhs and lhs 
bool Deck::operator == (const Deck &rhs) const
{
	 
	int l_energy = 0;
	int r_energy = 0;
	for (int i=0;i<this->size;i++)
	{
		l_energy += this->dyDeck[i].energy;
	}
	for (int i = 0; i<rhs.size; i++)
	{
		r_energy += rhs.dyDeck->energy;
	}

	if (l_energy == r_energy)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Comparing total energy of rhs and lhs 
bool Deck::operator < (const Deck &rhs) const
{
	
	int l_energy = 0;
	int r_energy = 0;
	for (int i=0;i<this->size;i++)
	{
		l_energy += this->dyDeck[i].energy;
	}
	for (int i = 0; i<rhs.size; i++)
	{
		r_energy += rhs.dyDeck->energy;
	}

	if (l_energy < r_energy)
	{
		return true;
	}
	else
	{
		return false;
	}
}


// Returning Card element from lhs Deck according to given index
Card & Deck::operator [] (int index) const
{
	
	return this->dyDeck[index];

}



bool operator <= (const Card & card, const Deck & deck)
{
	//Using another func that is called finder to find whenter card is inside the deck or not.
	if(deck.finder(card) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

//Finding whenter card is inside the deck or not
bool Deck::finder(const Card & card) const
{
	for(int i = 0; i < size; i++)
	{
		if((card.name == dyDeck[i].name) && (card.energy == dyDeck[i].energy))
		{
			return true;
		}
	
	}
	return false;

}

Deck operator + (const Deck &lhs, const Deck & rhs)
{
	//Creating a deep copy for lhs
	Deck copied(lhs);
	
	//Using another overload operator and adding rhs to copied lhs deck and returining copied lhs deck
	copied += rhs;
	return copied;
}

ostream & operator << (ostream & os, const Deck & dck)
{
	ostringstream ostr;
    ostr.fill('0');

	//Using getter func get_size() to achieving size of rhs deck's size
	for (int i = 0; i< dck.get_size(); i++)
	{
		//Using another overload operator [] to achieving Card obj at the given index
		ostr << i+1 << ": " << dck[i].name << " - " << dck[i].energy << endl;
	}
	os << ostr.str();
	return os;
}

