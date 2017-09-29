#include <iostream>
#include <string.h>
#include <malloc.h>
#include <math.h>
using namespace std;

class site {
    int n;
	int code;
	char name[30];
public:
	site();
	float emvado(float **sun,int n);
	float ektasi(float pososto,float area);
	void print(float plirwmi,float oikopedo);
	friend void calk();
};
site::site(){
	char name[30];
	int code,i,j;
	cout << "dwse onoma idioktiti\n";
	cin >> name[30];
	cout >> "dwse kwdiko oikopedou\n";
	cin >> code;
	cout << "dwse arithmo korufwn oikopedou\n";
	cin >> n;
	float **sun;
	sun=(float**)malloc(2*sizeof(float*));
	for(i=0;i<2;i++)
	{
		sun[i]=(float*)malloc(n*sizeof(float));
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==1)
			{
				cout << "dwse to x tis j korufis";
				cin >> sun[i][j];
			}
			else
			{
				cout << "dwse to y tis j korufis";
				cin >> sun[i][j];
			}
		}
	}	
}

float site::emvado(float **sun,int n){
	float area;
	int i,j;
	area=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<n;j++)
		{
			area=area-((sun[1][j+1]-sun[1][j]))*(sun[2][j+1]+sun[2][j]))/2;
		}
	}
	return area;
}

float site::ektasi(float pososto,float area,float add)
{
	float oikopedo,plirwmi;
	oikopedo=area-(area*pososto);
	if(oikopedo<100)
	{
		cout<<"ektasi mikroteri apo 100 t.m.prepei na plirwthei epipleon poso";
		plirwmi=(100-oikopedo)*add;
		return plirwmi;
	}
	else
	{
		return oikopedo;
	}
}

void site::print(float plirwmi,float oikopedo){
	cout<<"onoma idiktiti:";
	cout<< char[30];
	cout<<"kwdikos oikopedou:";
	cout<< code;
	if(oikopedo<100)
	{
		cout<<"i ektasi pou apomenei einai 100 t.m.";
		cout<<"poso plirwmis";
		cout<< plirwmi;
	}
	else{
		cout<<"ekstasi pou apomenei";
		cout<< oikopedo;
	}
}

class sea_site:public site{
	int n_korifes,*auxon_arithmos;
	float
public:
	sea_site();
	friend void calk();
	float distance();
	void print2(float plirwmi,float oikopedo,float sum,float add2);
};

sea_site::sea_site()
{
	int i;
	cout<<"Dwse ton arithmo twn korifwn pou orizoun tin prosopsi stin thalassa\n";
	cin>>n_korifes;
	auxon_arithmos=(int*)malloc(n_korifes*sizeof(int));
	for (i=0;i<n_parathalassiwn_korifwn;i++)
	{
		cout<<"Dwse arithmo gia tin i+1 parathalassia korifi\n";
		cin>>auxon_arithmos[i];
	}
}

float sea_site::distance()
{
	int i;
	float sum=0;
	for (i=0;i<n_korifes;i++)
	{
		sum=sum+sqrt()
	}
	return sum;
}

void sea_site::print2(float plirwmi,float oikopedo,float sum,float add2){
	cout<<"onoma idioktiti:";
	cout<< char[30];
	cout<<"kwdikos oikopedou";
	cout<< code;
	if(oikopedo<100)
	{
		cout<<"i ektasi pou apomenei einai 100 t.m.";
		cout<<"poso plirwmis";
		cout<< plirwmi;
	}
	else{
		cout<<"ekstasi pou apomenei";
		cout<< oikopedo;
	}
	cout<<"plirwmi gia tin parathalassia ektasi:";
	cout<<(sum*add2);
}

void calk(site *A,sea_site *B,int n_site,int n_seasite)
{
	int i;
	float pososto,add,add2;
	cout<<"Dwse to pososto eisforas se gh\n";
	cin>>pososto;
	cout<<"Dwse tin timi tou kathe tetragwnikou\n";
	cin>>add;
	cout<<"Dwse tin timi kathe metrou gia ta parathalassia oikopeda\n";
	cin>>add2;
	for (i=0;i<n_site;i++)
	{
		A[i].provoli(add,pososto);
	}
	for (i=0;i<n_seasite;i++)
	{
		B[i].provoli(add,pososto,add2);
	}
}

void main()
{
	int i;
	int n_site,n_seasite;
	cout<<"Dwse ton arithmo twn oikopedwn pou den exoun prosopsi stin thalassa\n";
	cin>>n_site;
	site *A;
	A=(site*)malloc(n_site*sizeof(site));
	if (A==NULL)
	{
		cout<<"error\n";
		exit(1);
	}
	for (i=0;i<n_site;i++)
	{
		site temp;
		A[i]=temp;
	}
	cout<<"Dwse ton arithmo twn oikopedwn pou exoun prosopsi stin thalassa\n";
	cin>>n_seasite;
	sea_site *B;
	B=(sea_site*)malloc(n_seasite*sizeof(sea_site));
	if (B==NULL)
	{
		cout<<"error\n";
		exit(1);
	}
	for (i=0;i<n_seasite;i++)
	{
		sea_site temp;
		B[i]=temp;
	}
	calk(A,B,n_site,n_seasite);

	free(A);
	free(B);



	system("PAUSE");
}



 






