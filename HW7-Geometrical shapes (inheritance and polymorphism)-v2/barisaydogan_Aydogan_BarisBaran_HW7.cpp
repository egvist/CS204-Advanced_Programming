/**Artrim Kjamilji, 20.12.2021**/

/*include all the necessary files, libraries, etc. here, if any*/

/*if you choose not to write the 5 required classes in seperate .h and .cpp files, then write them here*/
#include <iostream>
#include <string>

using namespace std;


class shape
{
public:
	shape()
	{
		myName = "";
	};


	virtual float perimeter()  = 0;
	virtual float area()  = 0;
	virtual float volume() = 0;
	virtual string getName()
	{
		return myName;
	}
	~shape()
	{
		
	};

protected:
	string myName;


};



class TwoDShape: public shape
{
public:
	TwoDShape(){};

	float volume()
	{
		return 0.0;
	}


};



class ThreeDShape: public shape
{
public:
	ThreeDShape(){}
		
	

	float perimeter()
	{
		return 0.0;
	}


};



class rectangle: public TwoDShape
{
public:
	rectangle(string name_m, float width_m, float length_m)
	
	{
		myName = name_m;
		width = width_m;
		length = length_m;

	}



	float perimeter()
	{
		return 2*(width + length);
	}

	float area()
	{
		return width*length ;
	}

	
protected:
	float width;
	float length;

};


class box: public ThreeDShape
{
public:
	box(string name_m, float width_m, float length_m, float height_m)
	
	{
		myName = name_m;
		width = width_m;
		length = length_m;
		height = height_m;

	}
	float area()
	{
		return 2*(width*length+width*height+length*height);
	}

	float volume()
	{
		return width*length*height;
	}
protected:
	float width;
	float length;
	float height;

};

shape * getShape() {
	
	/*write the getShape() function body here*/
	
	int choosed;
	string name;
	float width;
	float length;
	float height;
	cout << "Choose an option <1 or 2>"<< endl;
	cout << "1. Rectangle \n2. Box" << endl;
	cin >> choosed;

	if (choosed == 1)
	{	
		cout << "You chose rectangle. Give it's width, length and name: " << endl;
		
		cin >> width;
		cin >> length;
		cin >> name;
		
		rectangle* a = new rectangle(name, width, length);
		return a;
	}

	else if (choosed == 2)
	{
		cout << "You chose box. Give it's width, length, heigth and name: " << endl;
		cin >> width;
		cin >> length;
		cin >> height;
		cin >> name;
		box* a = new box(name,width,length,height);
		return a;
	}

}//getShape()

int main()
{
	cout<<"WELCOME TO THE SHAPE COMPARISONN PROGRAM"<<endl;
	cout<<"FOR EXITIING PRESS Y/y, OTHERWISE PRESS ANY KEY"<<endl;
	shape *shape_1, *shape_2; /* define two varibles, named shape_1 and shape_2 of the class shape.*/
	/*What should they be in order to enable proper polymorphism?*/
	char c;
	while (tolower(c = getchar())!='y')
	{
		cout<<"Defining (getting) shape 1..."<<endl;
		
		shape_1 = getShape();
		cout << shape_1->getName() <<endl;
		cout<<"Defining (getting) shape 2..."<<endl;
		shape_2 = getShape();
		cout<<"********************************************************************"<<endl;
		cout<<"PRINTING SHAPE_1 INFOS:"<<endl<<"Name: "<<shape_1->getName()<<", perimeter: "
			<<shape_1->perimeter()<<", area: "<<shape_1->area()<<", volume: "<<shape_1->volume()<<endl<<endl;
		cout<<"PRINTING SHAPE_2 INFOS:"<<endl<<"Name: "<<shape_2->getName()<<", perimeter: "
			<<shape_2->perimeter()<<", area: "<<shape_2->area()<<", volume: "<<shape_2->volume()<<endl;		
		bool nothingInCommon=true; // to check whether they have anything in common (perimeter, area, volume)
		if(shape_1->perimeter()==shape_2->perimeter())
		{
			nothingInCommon = false;
			cout<<shape_1->getName()<<" and "<<shape_2->getName()<<" have the same perimeter, which is: "
				<<shape_1->perimeter()<<" cm."<<endl;
		}
		if(shape_1->area()==shape_2->area())
		{
			nothingInCommon = false;
			cout<<shape_1->getName()<<" and "<<shape_2->getName()<<" have the same area, which is: "
				<<shape_1->area()<<" cm^2."<<endl;
		}
		if(shape_1->volume()==shape_2->volume())
		{
			nothingInCommon = false;
			cout<<shape_1->getName()<<" and "<<shape_2->getName()<<" have the same volume, which is: "
				<<shape_1->volume()<<" cm^3."<<endl;
		}
		if (nothingInCommon)
			cout<<shape_1->getName()<<" and "<<shape_2->getName()<<" don't have anything in common."<<endl;		
		
		delete shape_1;
		delete shape_2;

		cout<<"********************************************************************"<<endl;
		cout<<"FOR EXITIING PRESS Y/y, OTHERWISE, FOR ANOTHER COMPARISON PRESS ANY KEY"<<endl<<endl;
		cin.ignore();//flushing the buffer for remaining character(s), in order getchar() to work
  	}//while(tolower(c = getchar())!='y')
	cout<<"PROGRAM EXITING. THANKS FOR USING IT."<<endl;
	system("pause");
	return 0;
}