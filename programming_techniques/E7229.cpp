#include <iostream>
#include <malloc.h>
#include <math.h>
using namespace std;



class Array
{
	int n;
	int m;
	float **a;
public:
	Array(){};
	int getn(){return n;};
	int getm(){return m;};
	Array operator()(int r,int c);
	Array operator~();
	Array operator*(Array ap);
	Array operator++();
	void operator!();
	friend void operator<<(float **&p,Array ar);
};





Array Array::operator ()(int r,int c)
{
	Array ar;
	ar.n=r;
	ar.m=c;
	ar.a=(float**)malloc(r*sizeof(float));
	if (ar.a==NULL)
	{
		cout<<"error\n";
	}
	for (int i=0;i<r;i++)
	{
		ar.a[i]=(float *)malloc(c*sizeof(float));
		if (ar.a[i]==NULL)
		{
			cout<<"error\n";
		}
	}
	return ar;
}



Array Array::operator~()
{
	Array ar;
	ar.n=n;
	ar.m=m;
	ar=ar(n,m);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			ar.a[i][j]=a[j][i];
		}
	}
	return ar;
}




Array Array::operator *(Array ap)
{
	if (m=ap.n)
	{
		Array temp;
		temp=temp(n,ap.m);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<ap.m;j++)
			{
				float sum;
				sum=0;
				for (int k=0;k<m;k++)
				{
					sum=sum+(a[i][k])*(ap.a[k][j]);
				}
				temp.a[i][j]=sum;
			}
		}
		return temp;
	}
	else
	{
		cout<<"Den mporei na ginei o pollaplasiasmos pinakwn\n";
	}
}





Array Array::operator ++()
{
	Array ar;
	ar=ar(n,m);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]=\n";
			cin>>ar.a[i][j];
		}
	}
	return ar;
}




void Array::operator!()
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			cout<<"a["<<i<<"]["<<j<<"]="<<a[i][j]<<"\n";
		}
	}
}
			



void operator<<(float **&p,Array ar)
{
	p=(float**)malloc(ar.n*sizeof(float*));
	for (int i=0;i<ar.n;i++)
	{
		p[i]=(float*)malloc(ar.m*sizeof(float));
	}
	for (int k=0;k<ar.n;k++)
	{
		for (int l=0;l<ar.m;l++)
		{
			p[k][l]=ar.a[k][l];
		}
	}
}




void make_pos(float **p,int n,int m)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			p[i][j]=abs((int)p[i][j]);
		}
	}
}




void main()
{
	Array a,b;
	float **p;
	int r,c;
	cout<<"Dwse ton arithmo twn grammwn tou pinaka a\n";
	cin>>r;
	cout<<"Dwse ton arithmo twn stilwn tou pinaka a\n";
	cin>>c;
	a=a(r,c);
	a=++a;
	b=a*(~a);
	cout<<"O pinakas a tou antikeimenou b einai:\n";
	!b;
	p<<b;
	make_pos(p,b.getn(),b.getm());
	for (int i=0;i<b.getn();i++)
	{
		for (int j=0;j<b.getm();j++)
		{
			cout<<"p["<<i<<"]["<<j<<"]="<<p[i][j]<<"\n";
		}
	}

	
	system("PAUSE");
}

