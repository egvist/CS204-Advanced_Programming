#ifndef _HEADER_H
#define _HEADER_H
#include <string>
using namespace std;

struct QueueNode
{
	string functionName;;
	string StudentName;
	int studentID;
	QueueNode *next;
	QueueNode::QueueNode(int idint ,string namestr,string funcstr, QueueNode *ptr = NULL)
	{
		functionName = funcstr;
		StudentName = namestr;
		studentID = idint;
		next = ptr;
	}
};

class DynamicStringQueue
{
	private:
		QueueNode *front;
		QueueNode *rear;

	public:
		DynamicStringQueue();
		~DynamicStringQueue();

		void enqueue(int, string, string);
		void dequeue(int &, string &,string &);
		bool isEmpty() const; 
		void clear(void);
		string name();
		int number();
		string funcD();


};

struct QueueNodeInstructors
{
	string functionName;;
	string InstructorName;
	int InstructorID;
	QueueNodeInstructors *next;
	QueueNodeInstructors::QueueNodeInstructors(const int idint ,const string namestr,const string funcstr, QueueNodeInstructors *ptr = NULL)
	{
		functionName = funcstr;
		InstructorName = namestr;
		InstructorID = idint;
		next = ptr;
	}
};

class CircularQueue
{
	private:
	QueueNodeInstructors *head;		//Head node, start of LinkedList
	


	public:
		CircularQueue();			//Constructor
		string funcN();		//Prints the given LinkedList from head to end
		void addToEnd(int &idint , string &namestr, string &funcstr);
		void clearList(); //Deletes all of the dynamically allocated list nodes 
		bool isEmpty() const;
		int number();
		string name();


};


struct StackNodeOrders
{
	string definedValue;
	string funcName;
	
	StackNodeOrders *down;
};


class DynamicStringStack
{
	private:
		StackNodeOrders *top;
		

	public:
		string topfunc(DynamicStringStack);
		DynamicStringStack(void);
		void push(string,string);
		void pop(string &, string &);
		bool isEmpty(void);
		void print();
		void cleartheStack();
		
		
};


struct nodeOrder
{
	string data;
	nodeOrder *down;

	nodeOrder::nodeOrder()
	{}

	nodeOrder::nodeOrder(const string &s, nodeOrder * link)
		: data(s), down(link)
	{}
};

struct nodeFunc
{
	
	string funcnames;
	nodeFunc * right;
	nodeOrder * down;
	nodeFunc::nodeFunc()
	{}

	nodeFunc::nodeFunc(const string &s, nodeFunc * link, nodeOrder * link2)
		: funcnames(s), right(link), down(link2)
	{}
};

class linkedlist
{
private:
	nodeFunc *head;		//Head node, start of LinkedList
	nodeFunc *pos;
	nodeOrder *orderpos;
	nodeOrder *ordersecondpos;
	int count;
	string endit;


public:

	linkedlist();			//Constructor
	void printList();		//Prints the given LinkedList from head to end
	void addToDown(string n);	//Inserts new node at the end of the LinkedList with given data
	void addToRight(string n);
	void add(string n, int count);
	bool findFunc(string f) const;
	void clearList(); //Deletes all of the dynamically allocated nodes of the list
	string getfuncProperties();
	void puttheposback();
	void putposfunc(string &funcName);
	void changetheorder();
};






#endif