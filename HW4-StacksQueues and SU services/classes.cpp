#include <iostream>
#include "header.h"

using namespace std;

linkedlist::linkedlist()
{
	head=NULL;
	pos = NULL;
	orderpos = NULL;
	ordersecondpos = NULL;
	count = 0;
	endit = "";
}


void linkedlist::addToRight(string n)
{
	nodeFunc *ptr = head;
	
	
	nodeFunc *temp = new nodeFunc(n,NULL, NULL);

	if (head == NULL)
	{
	
		head = temp;
		pos = temp;
		orderpos = NULL;
		ordersecondpos = NULL;
		
		
	}
	else 
	{
		
		while (ptr->right != NULL)
		{
			
			ptr = ptr->right;

		}
		
		ptr->right = temp;
		
	
	}

}

void linkedlist::addToDown(string n)
{
	string newString = n.substr(0,n.length()-1);
	
	nodeOrder *temp = new nodeOrder(newString, NULL);
	while (pos->right != NULL)
	{
		
		pos = pos->right;
	}
	nodeOrder *ptr2 = pos->down;
	
	
	if (pos->down == NULL)
	{
		pos->down = temp;
		
	}
	else 
	{
		while(ptr2->down != NULL)
		{
			ptr2 = ptr2->down;
			
		}
		ptr2->down = temp;
	}
}


void linkedlist::printList()
{	
	nodeFunc * ptr = head;
	
	cout << "-------------------------------------------------------------------" << endl;
	cout << "PRINTING AVAILABLE SERVICES <FUNCTIONS> TO BE CHOSEN FROM THE USERS" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << endl << endl;
	if(head == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		while(ptr != NULL)
		{
			cout << ptr->funcnames << endl;
			nodeOrder * ptr2 = ptr->down;
			while (ptr2 != NULL)
			{
				cout << ptr2->data;
				if (ptr2->down == NULL)
				{
					cout << "."<< endl << endl;
					
				}
				else 
				{
					cout << ", ";
				}
				ptr2 = ptr2->down;
			
			}
			
			ptr = ptr->right;
		}
	}
}

bool linkedlist::findFunc(string f) const
{
	bool initial = false;
	nodeFunc *ptr = head;
	while (ptr != NULL)
	{
		if (ptr->funcnames == f)
		{
			initial = true;
			
		}
		ptr = ptr->right;
	}
	
	return initial;

}
string linkedlist::getfuncProperties()
{

	string willprint = orderpos->data;
	
	if (endit == "yes")
	{
		endit = "no";
		return "final";
	}
	else if (orderpos->down == NULL)
	{
		endit = "yes";
		return willprint;
		
	}
	else if (orderpos->down->data.substr(0,4) == "call" )
	{
		
		ordersecondpos = orderpos->down;
		orderpos = orderpos->down;
		

	}
	else
	{
		orderpos = orderpos->down;
		
	}

	return willprint;
	
	

	
}

void linkedlist::changetheorder()
{
	orderpos = ordersecondpos->down;
	
	
}

void linkedlist::putposfunc(string &funcName)
{
	count = 0;
	while (pos->funcnames != funcName)
	{
		pos = pos->right;
	}
	orderpos = pos->down;
	pos = head;
	
}

void linkedlist::puttheposback()
{
	pos = head;
	orderpos = NULL;
}

DynamicStringQueue::DynamicStringQueue()
{

	front = NULL;
	rear = NULL;
}

DynamicStringQueue::~DynamicStringQueue()
{
	clear();
	#ifdef _DEBUG
		cout << "Destructor is invoked\n";
		cout << endl;
	#endif
}
		
void DynamicStringQueue::enqueue(int idint, string namestr, string funcstr)
{
	if (isEmpty()) 
	{	
		front = new QueueNode(idint, namestr, funcstr);
		rear = front;
	}
	else 
	{	
		rear->next = new QueueNode(idint, namestr, funcstr);
		rear = rear->next;
	}
}
void DynamicStringQueue::dequeue(int & idint, string & namestr , string & funcstr)
{
	QueueNode *temp;
	if (isEmpty())
	{
		cout << "Attempting to dequeue on empty queue, exiting program...\n";
		exit(1);
	}
	else
	{	
		idint = front->studentID;
		namestr = front->StudentName;
		funcstr = front->functionName;
		temp = front;
		front = front->next;
		delete temp;      
	}
}
bool DynamicStringQueue::isEmpty() const
{
	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void DynamicStringQueue::clear(void)
{
	string value1;   // Dummies for dequeue
	string value2;
	int ivalue2;
	

	while(!isEmpty())
	{
		dequeue(ivalue2, value1, value2); 
	}
	front = NULL;
	rear = NULL;
}

string DynamicStringQueue::funcD()
{
	if (front != NULL)
    {
		QueueNode *ptr = front;
		return ptr->functionName;
		ptr = ptr->next;

    }
    
	
}

string DynamicStringQueue::name()
{
	if (front != NULL)
    {
		QueueNode *ptr = front;
		return ptr->StudentName;
		ptr = ptr->next;

    }

}
int DynamicStringQueue::number()
{
	if (front != NULL)
    {
		QueueNode *ptr = front;
		return ptr->studentID;
		ptr = ptr->next;

    }

}



CircularQueue::CircularQueue()
{

	head = NULL;
}

string CircularQueue::name()
{
	QueueNodeInstructors *ptr = head;
	return  ptr->InstructorName;
	ptr = ptr->next;

}

int CircularQueue::number()
{
	QueueNodeInstructors *ptr = head;
	return ptr->InstructorID;
	ptr = ptr->next;
}

string CircularQueue::funcN()
{
	QueueNodeInstructors *ptr = head;
	return ptr->functionName;
	ptr = ptr->next;


}
	
void CircularQueue::addToEnd(int &idint ,string &namestr,string &funcstr)
{
	if(head == NULL)
	{
		QueueNodeInstructors *ptr = new QueueNodeInstructors(idint,namestr,funcstr, head);
		head = ptr;
		head->next = head;
	}
	else
	{
		QueueNodeInstructors * ptr = new QueueNodeInstructors(idint,namestr,funcstr,head);
		QueueNodeInstructors* tmpHead = head;
		while(tmpHead->next != head)
		{
			tmpHead = tmpHead->next;
		}
		tmpHead->next = ptr;
	}
}

void  CircularQueue::clearList()
{
	if(head == NULL)
	{
		
	
	}		
	else if(head->next == head)
	{
		delete head;
		head=NULL;
		
	}
	else
	{
		QueueNodeInstructors * oldHead = head;
		head = head->next;
		QueueNodeInstructors * ptr = head;		
		while (head!=oldHead)
		{
			head = head->next;
			//cout<<"Deleting "<<ptr->data<<endl;
			delete ptr;
			ptr = head;
		}
		//cout<<"Deleting the head which is: "<<head->data<<endl;
		delete head;
		head = NULL;
	}	
}

bool CircularQueue::isEmpty() const
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


DynamicStringStack::DynamicStringStack()
{
	top=NULL;
}



string DynamicStringStack::topfunc(DynamicStringStack stack)
{
	return stack.top->funcName;

}

//Push back elements to the stack
void DynamicStringStack::push(string elmt, string func)
{
	StackNodeOrders *newNode;

	newNode = new StackNodeOrders;
	newNode->definedValue = elmt;
	newNode->funcName = func;

	if(isEmpty())
	{
		top = newNode;
		newNode->down = NULL;
	}
	else
	{
		newNode->down = top;
		top = newNode;
	}
}
//Pop up elements from the stack
void DynamicStringStack::print()
{
	StackNodeOrders *temp;
	temp = top;
	while (temp != NULL)
	{
		cout << temp->funcName << " " << temp->definedValue << endl;
		temp = temp->down;
	}


}
void DynamicStringStack::pop(string &elmt, string &func)
{
	StackNodeOrders *temp;

	if(isEmpty())
	{
		cout<<"Stack is empty!\n";
	}

	else 
	{
		elmt = top->definedValue;
		func = top->funcName;
		
		temp = top->down;
		delete top;
		top = temp;
	}
}

//If the stack is empty check function
bool DynamicStringStack::isEmpty()
{
	if(top == NULL)
	{
		return true;
	}
	return false;
}

void DynamicStringStack::cleartheStack()
{
	string elmt, func;
	while(top != NULL)
	{
		this->pop(elmt, func);
	
	}
	
}



