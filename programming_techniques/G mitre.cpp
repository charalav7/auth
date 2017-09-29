#include <iostream>
#include <malloc.h>

using namespace std;



//---------------------------source---------------------
class source
{
 protected:
    char cid[31];
    static source **S;
    static int SN;
    static source **C;
    static int CN;   
 public:
    source(char *c);
    source();
    virtual float get_power()=0;
    virtual int get_state()=0;
    virtual void set_state(int)=0;
    virtual char *get_source_id()=0;
    virtual char *get_class_id()=0;
	virtual int get_seira()=0;
    virtual float return_power()=0;
    virtual void create_units(int num)=0;
    
    
    static source **get_S(){return S;}
    static int get_SN(){return SN;}
    static source **get_C(){return C;}
    static int get_CN(){return CN;}
  
};

source **source::S;
int source::SN;
source **source::C;
int source::CN;

source::source()
{
  SN++;
  if(SN==1)
    S=(source **)malloc(sizeof(source *));
  else
    S=(source **)realloc(S,SN*sizeof(source *));
  if(S==NULL){
    cout<<"error\n";
    exit(1);
  }
  S[SN-1]=this;
}          

source::source(char *c)
{
  int i=0;
  while(c[i]){
    cid[i]=c[i];
    i++;
  }
  cid[i]='\0';
  CN++;
  if(CN==1)
    C=(source **)malloc(sizeof(source *));
  else
    C=(source **)realloc(C,CN*sizeof(source *));
  if(C==NULL){
    cout<<"error\n";
    exit(1);
  }
  C[CN-1]=this;
}             



//-------------------------------------------calk_system--------------------
void calc_system(float *isxus,int perioxes)
{
	float isxus_perioxwn=0;
	float *sum;
	sum=new float[perioxes];
	for (int j=0;j<perioxes;j++)
	{
		isxus_perioxwn=isxus_perioxwn+isxus[j];
		sum[j]=isxus_perioxwn;
	}
	float power=0;
	int n,state;
	source **p;
	n=source::get_SN();
	p=source::get_S();
	for(int i=0;i<n;i++)
	{
		for (int m=0;m<n;m++)
		{
			if (p[i]->get_state() && p[m]->get_seira()==i+1)
			{
				power=power+p[i]->get_power();
				cout<<"O stathmos "<<p[i]->get_source_id()<<" tethike se leitourgeia\n";
				if (isxus_perioxwn<=power)
				{
					cout<<"To sustima leitourgei omala\n";
					break;
				}
			}
		}
		if (isxus_perioxwn<=power)
		{
			break;
		}
	}
	if (sum[0]>power)
	{
		cout<<"Geniko blackout\n";
	}
	else 
	{
		for (int k=0;k<perioxes;k++)
		{
			if(sum[k]>power)
			{
				cout<<"H perioxi "<<k<<" den tha ilektrodotithei\n";
			}
		}
	}
}


//-----------------------------main--------------------------------
void main()
{
  float power;
  int i,num;
  int CN;
  source **C;
  C=source::get_C();
  CN=source::get_CN();
  for(i=0;i<CN;i++)
  {
		cout<<"Dwse ton arithmo twn stathmwn tupou "<<C[i]->get_class_id();
	    cin>>num;
		C[i]->create_units(num);
  }
  float sum=0;
  int perioxes;
  cout<<"Dwse ton arithmo twn perioxwn\n";
  cin>>perioxes;
  float *isxus;
  isxus=new float[perioxes];
  for(;;)
  {
	  for (int l=0;l<perioxes;l++)
	  {
		  cout<<"Dwse tin isxu tis "<<l+1<<"hs perioxhs\n";
		  cin>>isxus[l];
		  sum=sum+isxus[l];
	  }
	  if (sum==0)
	  {
		  break;
	  }
	  else
	  {
		  calc_system(isxus,perioxes);
	  }
  }


  system ("PAUSE");

}





//-----------------------------------coal_source------------------------------
class coal_source:public source
{
private:
    char id[30];
    int state;
	int seira;
	float karvouno;
	float k_c;
	float power;
public:
	char *get_source_id(){return id;}
	char *get_class_id(){return cid;};
    int get_state(){return state;}
    void set_state(int k){state=k;}
	int get_seira(){return seira;};
    float get_power();
    float return_power(){return power;}
    void create_units(int n);

    coal_source();
    coal_source(char *p);

}coal("coal");

void coal_source::create_units(int num)
{
  coal_source *p;
  p=new coal_source[num];
}

coal_source::coal_source(char *p):source(p)
{
	//Stelnei to p sto constructor tis source
}

coal_source::coal_source()
{
  cout<<"Pigi tupou coal source\n";
  cout<<"Dwse tin tautita tis pigis\n";
  cin>>id;
  cout<<"Dwse tin katastasi tis pigis(1 an vriskete se leitourgeia,0 gia ektos leitourgeias)\n";
  cin>>state;
  cout<<"Dwse tin seira protaireotitas tis pigis\n";
  cin>>seira;
  cout<<"Dwse tin wriaia katanalwsi karvounou\n";
  cin>>karvouno;
  cout<<"Dwse ton suntelesti apodosis\n";
  cin>>k_c;
}

float coal_source::get_power()
{
  power=karvouno*k_c;
  return power;
}




//-----------------------------------water_source------------------------------
class water_source:public source
{
private:
  char id[30];
  int state;
  int seira;
  float stathmi;
  float paroxi;
  float k_w;
  float power;
 public:
	char *get_source_id(){return id;};
    char *get_class_id(){return cid;};
    int get_state(){return state;};
    void set_state(int k){state=k;}
	int get_seira(){return seira;};
    float get_power();
    float return_power(){return power;}
    void create_units(int n);

    water_source();
    water_source(char *p);

}water("water");

void water_source::create_units(int num)
{
	water_source *p;
	p=new water_source[num];
}

water_source::water_source(char *p):source(p)
{
	//Stelnei to p sto constructor tis source
}

water_source::water_source()
{
	cout<<"Pigi tupou water source\n";
	cout<<"Dwse tin tautotita tis pigis\n";
	cin>>id;
	cout<<"Dwse tin katastasi tis pigis(1 an vriskete se leitourgeia,0 gia ektos leitourgeias)\n";
	cin>>state;
	cout<<"Dwse tin seira protaireotitas tis pigis\n";
	cin>>seira;
	cout<<"Dwse tin stathmi tou nerou\n";
	cin>>stathmi;
	cout<<"Dwse tin paroxi tou nerou\n";
	cin>>paroxi;
	cout<<"Dwse ton suntelesti apodosis\n";
	cin>>k_w;
}

float water_source::get_power()
{
  power=stathmi*paroxi*k_w;
  return power;
}

                                                