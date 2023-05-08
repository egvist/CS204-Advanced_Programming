#include <iostream>
#include <string>

using namespace std;

struct Card
{
	string name;
	int energy;

};

class Deck
{

	private:

		Card * dyDeck;
		int size;

	public:

		Deck();
		Deck(const Deck &);
		~Deck();
		

		Deck operator +=(const Deck & deck);
		Deck operator +(const Card & card);
		Deck operator = (const Deck & deck);
		Deck operator - (int n_cards);
		Card & operator [] (int index) const;

		bool operator == (const Deck &deck) const;
		bool operator < (const Deck &deck) const;
		bool finder(const Card & card) const;
		int get_size() const {return size;}


};

Deck operator + (const Deck & lhs,const Deck & rhs);
ostream & operator << (ostream & os, const Deck & dck);
bool operator <= (const Card & card, const Deck & deck);
bool operator >(const Deck & lhs,int n_cards);
