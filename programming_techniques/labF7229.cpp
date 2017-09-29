#include <iostream>
using namespsce std

class Shape{
protected:
	float Area;
	float Perim;
public:
	Shape(){};
	virtual void Draw()=0;
	virtual float getPerim()=0;
	virtual float getArea()=0;
};

class Rectangular:public Shape{
protected:
	float mikos;
	float platos;
public:
	Rectangular();
	void Draw();
	float getPerim();
	float getArea();
};

Rectangular:: Rectangular(){
	cout<<"dwse tintimi tou mikous\n";
	cin>> mikos;
	cout<<"dwse tin timi tou platous\n";
	cin>> platos;
}

void Rectangular::Draw(){
	cout<<"sximatise orthogwnio\n";
}

float Rectangular::getPerim(){
	Perim=2*mikos+2*platos;
	return Perim;
}

float Rectangular::getArea(){
	Area=mikos*platos;
	return Area;
}

class Circle::public Shape{
protected:
	float radius;
public:
	Circle();
	void Draw();
	float getPerim;
	float getArea;
}
Circle::Circle(){
	cout<<"dwse tin aktina tou kuklou\n";
	cin>> radius;
}

void Circle::draw()
{
	cout<<"Sxediazetai kuklos\n";
}


float Circle::getPerim()
{
	perim=2*3.14*radius;
	return Perim;
}


float Circle::getArea()
{
	Area=3.14*radius*radius;
	return Area;
}





class Square:public Rectangle
{
public:
	Square();
	void Draw();
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
	cout<<"Sxediazetai tetragwno\n";
}


float Square::getPerim()
{
	Perim=4*mikos;
	return Perim;
}


float Square::getArea()
{
	Area=mikos*mikos;
	return Area;
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


