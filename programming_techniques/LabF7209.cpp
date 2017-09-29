#include <iostream>

using namespace std;


class Shape
{
protected:
	float perim;
	float E;
public:
	Shape(){};
	virtual void draw()=0;
	virtual float getPerim()=0;
	virtual float getArea()=0;
};

//---------------------Rectangle-----------------
class Rectangle:public Shape
{
protected:
	float mikos;
	float platos;
public:
	Rectangle();
	void draw();
	float getPerim();
	float getArea();
};


Rectangle::Rectangle()
{
	cout<<"Dwse to mikos\n";
	cin>>mikos;
	cout<<"Dwse to platos\n";
	cin>>platos;
}


void Rectangle::draw()
{
	cout<<"Sxediazetai orthogwneio\n";
}


float Rectangle::getPerim()
{
	perim=2*mikos+2*platos;
	return perim;
}


float Rectangle::getArea()
{
	E=mikos*platos;
	return E;
}




//-----------------------Circle---------------
class Circle:public Shape
{
protected:
	float radius;
public:
	Circle();
	void draw();
	float getPerim();
	float getArea();
};



Circle::Circle()
{
	cout<<"Dwse tin aktina tou kuklou\n";
	cin>>radius;
}


void Circle::draw()
{
	cout<<"Sxediazetai kuklos\n";
}


float Circle::getPerim()
{
	perim=2*3.14*radius;
	return perim;
}


float Circle::getArea()
{
	E=3.14*radius*radius;
	return E;
}



//---------------------------Square-----------------
class Square:public Rectangle
{
public:
	Square();
	void draw();
	float getPerim();
	float getArea();
};



Square::Square()
{
	if (mikos==platos)
	{
		cout<<"To mikos einai idio me to platos\n";
	}
	else
	{
		cout<<"Den einai tetragwno\n";
	}
}


void Square::draw()
{
	cout<<"Dimiourgeite tetragwno\n";
}


float Square::getPerim()
{
	perim=4*mikos;
	return perim;
}


float Square::getArea()
{
	E=mikos*mikos;
	return E;
}




void main()
{
	Shape *p;
	int a;
	for(;;)
	{
		cout<<"1.Orthogwneio\n";
		cout<<"2.Kuklos\n";
		cout<<"3.Tetragwno\n";
		cout<<"0.Exodos\n";
		cout<<"Pliktrologise to noumero\n";
		cin>>a;
		if (a==1)
		{
			Rectangle obj1;
			p=&obj1;
			p->draw();
			cout<<"H perimetros einai:"<<p->getPerim()<<"\n";
			cout<<"To emvadon einai:"<<p->getArea()<<"\n";
		}
		if (a==2)
		{
			Circle obj2;
			p=&obj2;
			p->draw();
			cout<<"H perimetros einai:"<<p->getPerim()<<"\n";
			cout<<"To emvadon einai:"<<p->getArea()<<"\n";
		}
		if (a==3)
		{
			Square obj3;
			p=&obj3;
			p->draw();
			cout<<"H perimetros einai:"<<p->getPerim()<<"\n";
			cout<<"To emvadon einai:"<<p->getArea()<<"\n";
		}
		else if (a==0)
		{
			break;
		}
	}
	system ("PAUSE");
}






