#include <iostream>
#include "barisaydogan_Aydogan_BarisBaran_HW3_myfuncs.h"

using namespace std;


TwoDLinkedList::TwoDLinkedList()
{
		head = nullptr;

}

void TwoDLinkedList::add_row_sorted(string n)
{
	node *thead;
	node *tprev = nullptr;
	int counter = 0;

	for(int t = 0; t < n.size(); t++)
	{
		node *ptr = head;
		
		
		if(head == nullptr)
		{
			
			node *temp = new node;
			temp->data = n[t];
			temp->right = nullptr;
			temp->down = nullptr;
			head = temp;
			thead = head;
		}

		else
		{
			if (counter > 0)
			{
				
				while (thead->right != nullptr)
				{
					thead = thead->right;
					if(tprev != nullptr)
					{
						tprev = tprev->right;
					}
				}
				
				node *temp = new node;
				temp->data = n[t];
				temp->right = nullptr;
				if(thead->down != nullptr)
				{
					
					temp->down = thead->down->right;
					if(tprev != nullptr)
					{
						tprev->down = temp;
					}
				}
				else
				{
					
					temp->down = nullptr;
					if(tprev != nullptr)
					{
						tprev->down = temp;
					}
				}

				thead->right = temp;

				
				
			}
			else
			{
				
				if(n[t] <= head->data)
				{
					
					node *temp = new node;
					temp->data = n[t];
					temp->right = nullptr;
					temp->down = ptr;
					head = temp;
					thead = head;
				}
				else if (n[t] > head->data)

				{
					
					if(ptr->down == nullptr)
					{
						
						node *temp = new node;
						temp->data = n[t];
						temp->right = nullptr;
						temp->down = nullptr;
						ptr->down = temp;
						thead = ptr->down;
						tprev = ptr->right;
					}
					else
					{
						
						while((ptr->down != nullptr) && (ptr->down->data < n[t]))
						{
							
							ptr = ptr->down;
						}
						
						if (ptr->down == nullptr)
						{
							node *temp = new node;
							temp->data = n[t];
							temp->right = nullptr;
							temp->down = nullptr;
							ptr->down = temp;
							thead = ptr->down;
							tprev = ptr->right;
						
						}
						else if(ptr->down->data >= n[t])
						{
							
							node *temp = new node;
							temp->data = n[t];
							temp->right = nullptr;
							temp->down = ptr->down;
							ptr->down = temp;
							thead = ptr->down;
							tprev = ptr->right;
						
					
						}


					}
				}
			
			}


		}

		
		counter++;
	}
	

}

void TwoDLinkedList::displayFullMatrix()
{
	node *ptr = head;
	node *rtemp;

	while(ptr != nullptr)
	{
		rtemp = ptr;
		while(rtemp != nullptr)
		{
			cout << rtemp->data;
			rtemp = rtemp->right;
		
		}
		cout << endl;
		if(ptr->down != nullptr)
		{
			ptr = ptr->down;
		}
		else
		{
			break;
		}
	
	}


	
}

void TwoDLinkedList::displayFullMatrixReversed_prev(node *v)
{
	if(v == nullptr)
	{
		cout << endl;
		return;
	}
	node *ptr = v;

	displayFullMatrixReversed_prev(v->down);
	while(ptr != nullptr)
	{
		cout << ptr->data;
		ptr = ptr->right;
	}
	cout << endl;

}

void TwoDLinkedList::displayFullMatrixReversed()
{
	displayFullMatrixReversed_prev(head);
}


void TwoDLinkedList:: display_rows_starting_with(char n)
{
	node *ptr = head;
	node *rtemp;
	while(ptr != nullptr)
	{
		rtemp = ptr;
		if(ptr->data == n)
		{
			while(rtemp != nullptr)
			{
				cout << rtemp->data;
				rtemp = rtemp->right;
			}
			cout << endl;
		
		}
		ptr = ptr->down;
	}

}

void TwoDLinkedList:: display_cols_starting_with(char n)
{
	node *ptr = head;
	node *dtemp;
	while(ptr != nullptr)
	{
		dtemp = ptr;
		if(ptr->data == n)
		{
			
			while(dtemp != nullptr)
			{
				cout << dtemp->data << endl;
				dtemp = dtemp->down;
			}
			cout << endl;
		}
		ptr = ptr->right;
	}

}

int TwoDLinkedList:: delete_rows_starting_with(char n)
{
	node *ptr = head;
	
	node *rptr;
	node *dptr;
	int count = 0;
	while(ptr->down != nullptr)
	{
		rptr = ptr;
		
		if(head->data == n)
		{
			count++;
			head = head->down;
			
			while(rptr != nullptr)
			{
				node *temp;
				temp = rptr->right;
				
				delete rptr;
				rptr = temp;

			}
			delete rptr;
			ptr = head;
		}
		else
		{
			
			
			if(ptr->down->data == n)
			{
				count++;
				dptr = ptr;
				rptr = ptr->down;
				
				while(rptr != nullptr)
				{
					if(rptr->down == nullptr)
					{
						
						dptr->down = nullptr;
					}
					else if(rptr->down != nullptr)
					{
						dptr->down = rptr->down;
						
					}

					if(dptr->right != nullptr)
					{
						dptr = dptr->right;
					}


					node *temp;
					temp = rptr->right;
					
					delete rptr;
					rptr = temp;
				}


				delete rptr;
				ptr = head;
				
			}
			else if(ptr->data == n)
			{
				count++;
				dptr = head;
				rptr = ptr;
				while(rptr != nullptr)
				{
					if(rptr->down == nullptr)
					{
						
						dptr->down = nullptr;
					}
					else if(rptr->down != nullptr)
					{
						dptr->down = rptr->down;
						
					}

					if(dptr->right != nullptr)
					{
						dptr = dptr->right;
					}


					node *temp;
					temp = rptr->right;
					
					delete rptr;
					rptr = temp;
				}


				delete rptr;
				ptr = head;
				
			
			}

				ptr = ptr->down;
			

		
		}
		
	}

	if(head->data == n)
	{
		count++;
		
		while(head != nullptr)
		{
			node *temp;
			temp = head->right;
			
			delete head;
			head = temp;

		}
		delete head;
	}

	else if(ptr->data == n)
	{
		count++;
		node *ptrhead = head;
		while(ptr != nullptr)
		{
			node *temp;
			temp = ptr->right;
			
			ptrhead->down = nullptr;
			ptrhead = ptrhead->right;
			delete ptr;
			ptr = temp;
		
		}
		delete ptr;
	
	}

	return count;
}

int TwoDLinkedList:: delete_cols_starting_with(char n)
{
	node *ptr = head;
	node *rptr;
	node *dptr;
	int count = 0;
	
	while(ptr->right != nullptr)
	{
		rptr = ptr;

		if(head->data == n)
		{
			count++;
			head = head->right;
	
			while(rptr != nullptr)
			{
				node *temp;
				temp = rptr->down;
		
				delete rptr;
				rptr = temp;

			}
			delete rptr;
			ptr = head;
		}
		else
		{

			if(ptr->right->data == n)
			{
				count++;
				dptr = ptr;
				rptr = ptr->right;
				
				while(rptr != nullptr)
				{
					if(rptr->right == nullptr)
					{
				
						dptr->right = nullptr;
						if(dptr->down != nullptr)
						{
							dptr = dptr->down;
						}
					}
					else if(rptr->right != nullptr)
					{
						dptr->right = rptr->right;
					
						if(dptr->down != nullptr)
						{
							dptr = dptr->down;
						}
					}




					node *temp;
					temp = rptr->down;
					
					delete rptr;
					rptr = temp;
				}


				delete rptr;
				ptr = head;
				
				if(ptr->right == nullptr)
				{
					break;
				}
			}
			else if(ptr->data == n)
			{
				count++;
				dptr = head;
				rptr = ptr;
				while(rptr != nullptr)
				{
					if(rptr->right == nullptr)
					{
						
						dptr->right = nullptr;
					}
					else if(rptr->right != nullptr)
					{
						dptr->right = rptr->right;
						
					}

					if(dptr->down != nullptr)
					{
						dptr = dptr->down;
					}


					node *temp;
					temp = rptr->down;
					
					delete rptr;
					rptr = temp;
				}


				delete rptr;
				ptr = head;
				
			
			}

				ptr = ptr->right;
			

		
		}
		
	}

	if(head->data == n)
	{
		count++;
		
		while(head != nullptr)
		{
			node *temp;
			temp = head->right;
			
			delete head;
			head = temp;

		}
		delete head;
	}

	else if(ptr->data == n)
	{
		count++;
		node *ptrhead = head;
		while(ptr != nullptr)
		{
			node *temp;
			temp = ptr->right;
			
			ptrhead->down = nullptr;
			ptrhead = ptrhead->right;
			delete ptr;
			ptr = temp;
		
		}
		delete ptr;
	
	}

	return count;

}

void TwoDLinkedList:: clear()
{
	node *ptr = head;
	node *next = nullptr;

	while(head != nullptr)
	{
		head = head->down;
		while(ptr != nullptr)
		{
			next = ptr->right;
			
			delete ptr;
			ptr = next;
		
		}
		ptr = head;
		
	}


	
}
