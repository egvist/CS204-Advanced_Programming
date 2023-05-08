#ifndef _TWOLINKEDLIST_H
#define _TWOLINKEDLIST_H
#include <string>
using namespace std;




struct node
{
char data;
node *right;
node *down;
};



class TwoDLinkedList
{
	private:
		node *head;
	public:
		TwoDLinkedList();
		void add_row_sorted(string n);
		void displayFullMatrix();
		void displayFullMatrixReversed_prev(node *v);
		void displayFullMatrixReversed();
		void display_rows_starting_with(char n);
		void display_cols_starting_with(char n);
		int delete_rows_starting_with(char n);
		int delete_cols_starting_with(char n);
		
		void clear();

};





#endif