#include <iostream>
#include <math.h>
using namespace std;




class Point
{
public:
	float x;
	float y;
	Point();
	Point(float _x,float _y);
	void print();
	Point operator+(Point p2);
	friend Point operator+(Point,float);
	float operator-(Point p2);
	int operator==(Point p2);
};


Point::Point()
{
	x=0;
	y=0;
}


Point::Point(float _x, float _y)
{
	x=_x;
	y=_y;
}


void Point::print()
{
	cout<<"x="<<x<<"\n";
	cout<<"y="<<y<<"\n";
}



Point Point::operator+(Point p2)
{
	Point p3;
	p3.x=x+p2.x;
	p3.y=y+p2.y;
	return p3;
}


Point operator+(Point p1,float a)
{
	Point p2;
	p2.x=p1.x+a;
	p2.y=p1.y+a;
	return p2;
}



float Point::operator -(Point p2)
{
	float d;
	d=sqrt(pow(p2.x-x,2)+pow(p2.y-y,2));
	return d;
}


int Point::operator ==(Point p2)
{
	int i;
	if (p2.x==x && p2.y==y)
	{
		i=1;
	}
	else
	{
		i=0;
	}
	return i;
}




void main()
{
	float x1,x2,y1,y2;
	cout<<"x1=\n";
	cin>>x1;
	cout<<"y1=\n";
	cin>>y1;
	cout<<"x2=\n";
	cin>>x2;
	cout<<"y2=\n";
	cin>>y2;
	Point p1(x1,y1);
	Point p2(x2,y2);
	Point p3;
	p3=p1+p2;
	p3.print();
	float d;
	d=p1-p2;
	cout<<"d="<<d<<"\n";
	Point p4;
	p4=p1+3;
	p4.print();
	int i;
	i=p1==p2;
	if (i==1)
	{
		cout<<"Idia simeia\n";
	}
	else
	{	
		cout<<"Diaforetika simeia\n";
	}

	system("PAUSE");
}