#include <iostream>
#include <malloc.h>
#include <string.h>
#include <math.h>
using namespace std;


class site;
class sea_site;
class point
{
	float x;
	float y;
public:
	point();
	point(float a, float b){x=a; y=b;};
	void set_x(float a){x=a;};
	void set_y(float b){y=b;};
	float get_x(){return x;};
	float get_y(){return y;};
};



class site
{
	char idioktitis[30];
	int oikopedo;
	int korifes;
	point *syntetagmenes;
public:
	site();
	char* get_idioktitis(){return idioktitis;};
	int get_oikopedo(){return oikopedo;};
	float emvado();
	float ektasi(float pososto);
	float poso(float timi,float pososto);
	void provoli(float timi,float pososto);
	friend void calk(site *A,sea_site *B,int n_site,int n_seasite);
};



class sea_site:public site
{
	int n_parathalassiwn_korifwn;
	int *auxon_arithmos;
	point *syntetagmenes;
public:
	sea_site();
	float apostasi();
	void provoli(float timi,float pososto,float timi_parathalassiou);
	friend void calk(site *A,sea_site *B,int n_site,int n_seasite);
};



/*Constructor tis site*/
site::site()
{
	int i;
	float a,b;
	cout<<"Dwse to onoma tou idioktiti(to polu 30 xaraktires)\n";
	cin>>idioktitis;
	cout<<"Dwse ton kwdiko tou oikopedou\n";
	cin>>oikopedo;
	cout<<"Dwse ton arithmo twn korifwn tou oikopedou\n";
	cin>>korifes;
	syntetagmenes=(point*)malloc(korifes*sizeof(point));
	if (syntetagmenes==NULL)
	{
		cout<<"error\n";
		exit(1);
	}
	for (i=0;i<korifes;i++)
	{
		cout<<"Dwse tin suntetagmeni x tis "<<i+1<<"is korifis";
		cin>>a;
		syntetagmenes[i].set_x(a);
		cout<<"Dwse tin suntetagmeni y tis "<<i+1<<"is korifis";
		cin>>b;
		syntetagmenes[i].set_x(b);
	}
}




/*Constructor tis sea_site*/
sea_site::sea_site()
{
	int i;
	cout<<"Dwse ton arithmo twn korifwn pou orizoun tin prosopsi stin thalassa\n";
	cin>>n_parathalassiwn_korifwn;
	auxon_arithmos=(int*)malloc(n_parathalassiwn_korifwn*sizeof(int));
	if (auxon_arithmos==NULL)
	{
		cout<<"error\n";
		exit(1);
	}
	for (i=0;i<n_parathalassiwn_korifwn;i++)
	{
		cout<<"Dwse ton arithmo gia tin "<<i+1<<"i parathalassia korifi\n";
		cin>>auxon_arithmos[i];
	}
}


/*H sunartisi gia to emvado*/
float site::emvado()
{
	int i;
	float sum=0;
	for (i=0;i<korifes;i++)
	{
		sum=sum+((syntetagmenes[i+1].get_x()-syntetagmenes[i].get_x())*(syntetagmenes[i+1].get_y()+syntetagmenes[i].get_y()))/2;
	}
	return sum;
}



/*I sunartisi gia tin apostasi*/
float sea_site::apostasi()
{
	int i;
	float sum=0;
	for (i=0;i<n_parathalassiwn_korifwn;i++)
	{
		sum=sum+sqrt(pow(syntetagmenes[auxon_arithmos[i+1]].get_x()-syntetagmenes[auxon_arithmos[i]].get_x(),2)+pow(syntetagmenes[auxon_arithmos[i+1]].get_y()-syntetagmenes[auxon_arithmos[i]].get_y(),2));
	}
	return sum;
}


/*H sinartisi upologismou tis ektasis tou oikopedou*/
float site::ektasi(float pososto)
{
	float E,teliki_ektasi;
	E=emvado();
	if ((E*pososto)>100)
	{
		teliki_ektasi=E-(E*pososto);
	}
	else
	{
		teliki_ektasi=100;
	}
	return teliki_ektasi;
}



/*H sunartisi gia ton upologismo tou posou pou prepei na katavalei o idioktitis*/
float site::poso(float timi,float pososto)
{
	float E,teliki_ektasi,aksia;
	E=emvado();
	if ((E*pososto)>100)
	{
		teliki_ektasi=E-(E*pososto);
		aksia=0;
	}
	else
	{
		teliki_ektasi=100;
		aksia=E-100;
	}
	return aksia;
}



/*H sunartisi calk*/
void calk(site *A,sea_site *B,int n_site,int n_seasite)
{
	int i;
	float pososto,timi,timi_parathalassiou;
	cout<<"Dwse to pososto eisforas se gh\n";
	cin>>pososto;
	cout<<"Dwse tin timi tou kathe tetragwnikou\n";
	cin>>timi;
	cout<<"Dwse tin timi kathe metrou gia ta parathalassia oikopeda\n";
	cin>>timi_parathalassiou;
	for (i=0;i<n_site;i++)
	{
		A[i].provoli(timi,pososto);
	}
	for (i=0;i<n_seasite;i++)
	{
		B[i].provoli(timi,pososto,timi_parathalassiou);
	}
}




/*H sunartisi gia tin emfanisi apotelesmatwn gia ta antikeimena tupou site*/
void site::provoli(float timi,float pososto)
{
	float E=emvado();
	cout<<"O idioktitis "<<get_idioktitis()<<" me kwdiko oikopedou "<<get_oikopedo()<<" ,tha paraxwrisei:\n";
	cout<<(E-ektasi(pososto))<<"tetragwnika metra kai tha plirwsei "<<poso(timi,pososto)<<" euro\n";
}



/*H sunartisi gia tin emfanisi apotelesmatwn gia ta antikeimena tupou sea_site*/
void sea_site::provoli(float timi,float pososto,float timi_parathalassiou)
{
	float E=emvado();
	cout<<"O idioktitis "<<get_idioktitis()<<" me kwdiko oikopedou "<<get_oikopedo()<<" ,tha paraxwrisei:\n";
	cout<<(E-ektasi(pososto))<<"tetragwnika metra kai tha plirwsei "<<poso(timi,pososto)<<" euro\n";
	cout<<"Tha plirwsei akoma"<<apostasi()*timi_parathalassiou<<" euro, gia tin prosopsi stin thalassa\n";
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





