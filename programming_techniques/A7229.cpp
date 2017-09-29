#include <iostream>
#include <string.h>
#define PASSWORD "admin"
using namespace std;

class student
{
	char onoma[30];
	int AEM;
	int n;
	int *codes;
	float *vathmoi;
public:
	student();
	void set_n(int k);
	int get_AEM();
	void set_code_vathmoi();
	void allagi_vathmwn();
	void student::get_codes_vathmoi();
};

void student::set_n(int k)
{
	n=k;
}

int student::get_AEM()
{
	return AEM;
}


/*H sunartisi domisis(constuctor) gia tis eisodo tou onomatos kai tou aem*/
student::student()
{
	int apantisi1,i;
	char apantisi2[11];
	cout<<"Eisai o diaxeiristis?(1 gia nai,2 gia oxi)\n";
	cin>>apantisi1;
	if (apantisi1==1)
	{
		cout<<"Plikrologeiste ton kwdiko prosvasis(to polu 10 xaraktires)\n";
		cin>>apantisi2;
		if (strcmp(PASSWORD,apantisi2)==0)
		{
			cout<<"Epituxis eisodos sto sustima\n";
			cout<<"Pliktrologisai to onoma tou foititi:\n";
			cin>>onoma;
			cout<<"Kai to AEM tou:\n";
			cin>>AEM;
		
		}
		else
		{
			cout<<"Lathos kwdikos\n";
			exit(1);
		}
	}
	else
	{
		exit(1);
	}
}

/*H sunartisi gia tin eisagwgi twn kwdikwn kai twn vathmwn*/
void student::set_code_vathmoi()
{
	int i;
	codes=(int*)malloc(n*sizeof(int));
	vathmoi=(float*)malloc(n*sizeof(float));
	if (codes==NULL || vathmoi==NULL)
	{
		cout<<"error\n";
		exit(1);
	}
	else
	{
		for (i=0;i<n;i++)
		{
			cout<<"Pliktrologisai ton kwdiko tou"<<i+1<<"ou mathimatos\n";
			cin>>codes[i];
			cout<<"Kai twra ton vathmo autou tou mathimatos\n";
			cin>>vathmoi[i];
		}
	}
}

/*H sunartisi gia tin allagi vathmwn*/
void student::allagi_vathmwn()
{
	int i;
	int apantisi;
	float neos_vathmos;
	for (i=0;i<n;i++)
	{
		cout<<"Thelete na allaksete ton vathmo tou mathimatos me kwdiko"<<codes[i]<<"?(1 gia nai,2 gia oxi)\n";
		cin>>apantisi;
		if (apantisi==1)
		{
			cout<<"Pliktrologiste ton neo vathmo\n";
			cin>>neos_vathmos;
			vathmoi[i]=neos_vathmos;
		}
	}
}

/*H sunartisi gia tin emfanisi twn vathmwn*/
void student::get_codes_vathmoi()
{
	int l;
	for (l=0;l<n;l++)
	{
		cout<<"Pires"<<vathmoi[l]<<"sto mathima me kwdiko"<<codes[l];
	}
}



void main()
{
	student foititis[2];
	int apantisi1,apantisi2,apantisi3,i,j,k,am,aem,position;
	int fores_eisagwgis[2];  //gia kafe foititi poses fores mpike sto sustima wste na elegxetai o kwdikos
	char cod1[11];
	char cod2[11];
	char kwdikos[11];
	for (i=0;i<2;i++)
	{
		fores_eisagwgis[i]=0;
	}
	for(;;)
	{
		cout<<"Pliktrologiste 1 gia diaxeiristis i 2 gia foititis\n";
		cin>>apantisi1;
		if (apantisi1==1)
		{
			cout<<"Gia na diaxeiristeite ta stoixeia twn foititwn pieste 1\n";
			cout<<"Gia na kleisete to sustima pieste 2\n";
			cin>>apantisi2;
			cout<<"Dwste ton kwdiko prosvasis(to polu 10 xaraktires)\n";
			cin>>kwdikos;
			if (strcmp(PASSWORD,kwdikos)==0)
			{
				if (apantisi2==1)
				{
					for(i=0;i<2;i++)
					{
						cout<<"Gia ton foititi"<<i+1<<"\n";
						cout<<"Pliktrologiste ton arithmo mathimatwn\n";
						cin>>k;
						foititis[i].set_n(k);
						cout<<"Gia eisagwgi kwdikwn kai vathmwn mathimatwn pieste 1\n";
						cout<<"Gia allagi kwdikwn kai vathmwn mathimatwn pieste 2\n";
						cin>>apantisi3;
						if (apantisi3==1)
						{
							foititis[i].set_code_vathmoi();
						}
						else
						{
							foititis[i].allagi_vathmwn();
						}
					}
				}
				else
				{
					cout<<"Termatismos programmatos\n";
					break;
				}
			}
			else
			{
				cout<<"Lathos Kwdikos\n";
				continue;
			}
		}
		else
		{
			cout<<"Kalwsorises foititi. Pliktrologise to AEM\n";
			cin>>am;
			position=-1;
			for (j=0;j<2;j++)
			{
				aem=foititis[j].get_AEM();
				if (am==aem)
				{
					position=j;
				}
			}
			if (position!=-1)
			{
				cout<<"Vrethike to aem.Dwse ton kwdiko prosvasis\n";
				if (fores_eisagwgis[position]=0)
				{
					cin>>cod1;
					foititis[position].get_codes_vathmoi();
				}
				else
				{
					cin>>cod2;
					if (strcmp(cod1,cod2)==0)
					{
						cout<<"Swstos kwdikos\n";
						foititis[position].get_codes_vathmoi();
						fores_eisagwgis[position]++;
					}
					else
					{
						cout<<"Lathos kwdikos\n";
					}
				}
			}
			else
			{
				cout<<"Den vrethike AEM\n";
			}
		}
	}


	system ("PAUSE");
}











