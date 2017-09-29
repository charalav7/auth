#include <iostream>
using namespsce std

class circuit {
public:
	int a,b;
	circuit(int k,int l){a=k; b=l;};
	virtual float calc_circuit(int a, int b);
}

class A {
public:
	int c,d;
	A();
	float calc_circuit(int &a,int &b,int &c, int&d);
}

class B {
public:
	int c,d;
	B();
	float calc_circuit(int &a,int &b,int &c, int&d);
}

float A::calc_circuit(int &a,int &b,int &c, int&d)
{
	float power;
	if(a==b==0){
		c=d=0;
		power=0;
	}
	else if((a==1)&(b==0)){
		c=0;
		d=1;
		power=0.5+0.5;
	}
	else if((a==0)&(b==1)){
		c=0;
		d=1;
		power=0.5+0.5;
	}
	else{
		d=1;
		c=1;
		power=1+1;
	}
	return power;
}


float B::calc_circuit(int &a,int &b,int &c, int&d)
{
	float power;
	if(a==b==0){
		c=d=0;
		power=0.5;
	}
	else if((a==1)&(b==0)){
		c=1;
		d=1;
		power=0.5+0.5;
	}
	else if((a==0)&(b==1)){
		c=0;
		d=1;
		power=1+0.5;
	}
	else{
		d=0;
		c=1;
		power=1+1+0.5;
	}
	return power;
}

void main(){
	int a,b,c,d;
	float sum=0;
	char tupos;
	cout<<"dwse arithmo kuklwmatwn tupou A\n";
	cin>>k;
	cou<<"dwse arithmo kuklwmatwn tupou B\n";
	cin>>l;
	circuit *p;
	A type_A;
	B type_B;
	for(int i=0;i<(k+l);i++)
	{
		cout<<"dwse typo kuklwmatos A h B\n";
		cin>>typos;
		if(typos==A){
			p=&type_A;
			sum=sum+calc_circuit(int &a,int &b,int &c, int&d);
			a=c;
			b=d;
		}
		else{
			p=&type_B;
			sum=sum+calc_circuit(int &a,int &b,int &c, int&d);
			a=c;
			b=d;
		}
		if(i==(k+l)-1){
			cout<<"i isxus tou kuklwmatos einai: "<<sum;
			cout<<"oi times twn akrodektwn eisodou einai: c=: "<<c<<"d= "<<d;
		}
		system("PAUSE");
	}


