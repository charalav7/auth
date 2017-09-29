#include <iostream>
using namespace std;

class device1{
  int id;
  float p,vd;
public:
  device1();
  float get_entasi(float p,float vd){return p/vd;};
  int get_id(){return id;};
  float get_vd(){return vd;};
};


device1::device1()
{
	cout<< "dwse ton akeraio arithmo tautotitas\n";
	cin>> id;
	cout>> "dwse tin onomastiki isxus tis suskeuis\n";
	cin>> p;
	cout<< "dwse tin tasi leitourgias\n";
	cin>> vd;
}

template <class type>
class installation{
	type *A;
public:
	int n_p,n_dev;
	installation();
	void calc_installation();
};

installation::installation(){
	cout<< "dwse ton arithmo paroxwn tou ktiriou:\n";
	cin>> n_p;
	int *E;
	E=new float[n_p];
	for(int i=0;i<n_p;i++)
	{
		cout<< "dwse tin megisti entasi reumatostis"<<i<<"paroxis\n";
		cin>>E[i];
	}
	cout<< "dwse ton arithmo twn suskeuwnpou tha sundethoun\n";
	cin>>n_dev;
	A=new type[n_dev];
}

template <class type>
void installation <type>::calc_installation()
{
	int pos;
	float temp,min=0;
	for(int i=0;i<n_p;i++)
	{
		for(int j=0;j<n_dev;j++)
		{
			temp=A[j].get_entasi(float p,float vd);
			if(temp>E[i])
				continue;
			else{
				if(min>temp){
					min=temp;
					pos=j;
				}
			}
		}
		E[i]=A[pos].get_id;
	}
}

template <class type>
void transform(float V,int *E,int n_p,int n_dev)
{
	float temp;
	for(int i=0;i<n_p;i++)
	{
		cout<< E[i];
	}
	for(i=0;i<n_dev;i++)
	{
		temp=A[i].get_vd();
		cout<< V/temp;
	}
}


void main()
{
	float V;
	cout<<"dwse tin tasi me tin opoia trofodoteitai to ktirio\n";
	cin>> V;
	installation dvc;
	dvc.transform(float V,int *E,int n_p,int n_dev);
}