#include <iostream>
using namespace std;




/*Gia tin klassi SUN*/
class SUN
{
protected:
	float epifaneia;
	float S_k;
	float roh;
	float cost_kwh1;
	float cost_suntirisis1;
public:
	SUN(float _roh);
	float isxus1();
	float cost1();
};



SUN::SUN(float _roh)
{
	roh=_roh;
	cout<<"Dwse tin epifaneia twn sullektwn\n";
	cin>>epifaneia;
	cout<<"Dwse ton suntelesti apodosis\n";
	cin>>S_k;
	cout<<"Dwse to kostos tis kilovatoras\n";
	cin>>cost_kwh1;
	cout<<"Dwse to kostos suntirisis ana monada kilovatoras\n";
	cin>>cost_suntirisis1;
}


float SUN::isxus1()
{
	float power;
	power=epifaneia*roh*S_k;
	return power;
}



float SUN::cost1()
{
	float sum;
	sum=cost_kwh1+cost_suntirisis1;
	return sum;
}


/*Gia tin klassi GAS*/
class GAS
{
protected:
	float wriaia;
	float cost_kuvikou;
	float G_k;
	float cost_kwh2;
	float cost_suntirisis2;
public:
	GAS(float _wriaia);
	float isxus2();
	float cost2();
};



GAS::GAS(float _wriaia)
{
	wriaia=_wriaia;
	cout<<"Dwse to kostos enos kuvikou metrou enos fusikou aeriou\n";
	cin>>cost_kuvikou;
	cout<<"Dwse ton suntelesti apodosis\n";
	cin>>G_k;
	cout<<"Dwse to kostos tis kilovatoras\n";
	cin>>cost_kwh2;
	cout<<"Dwse to kostos suntirisis ana monada kilovatoras\n";
	cin>>cost_suntirisis2;
}



float GAS::isxus2()
{
	float power;
	power=wriaia*G_k;
	return power;
}



float GAS::cost2()
{
	float sum;
	sum=cost_kwh2+cost_suntirisis2+cost_kuvikou;
	return sum;
}



/*H klassi AIR*/
class AIR
{
protected:
	float speed;
	float A_k;
	float cost_kwh3;
	float cost_suntirisis3;
public:
	AIR(float _speed);
	float isxus3();
	float cost3();
};



AIR::AIR(float _speed)
{
	speed=_speed;
	cout<<"Dwse ton suntelesti apodosis tis anemogenitrias\n";
	cin>>A_k;
	cout<<"Dwse to kostos tis kilovatoras\n";
	cin>>cost_kwh3;
	cout<<"Dwse to kostos suntirisis ana monada kilovatoras\n";
	cin>>cost_suntirisis3;
}


float AIR::isxus3()
{
	float power;
	power=speed*A_k;
	return power;
}



float AIR::cost3()
{
	float sum;
	sum=cost_kwh3+cost_suntirisis3;
	return sum;
}



/*H klassi OIL*/
class OIL
{
protected:
	float wriaia_katanalwsi;
	float kostos_litrou;
	float O_k;
	float cost_kwh4;
	float cost_suntirisis4;
public:
	OIL(float _wriaia_katanalwsi);
	float isxus4();
	float cost4();
};


OIL::OIL(float _wriaia_katanalwsi)
{
	wriaia_katanalwsi=_wriaia_katanalwsi;
	cout<<"Dwse to kostos enos litrou petrelaiou\n";
	cin>>kostos_litrou;
	cout<<"Dwse ton suntelesti apodosis tou petrelaiou\n";
	cin>>O_k;
	cout<<"Dwse to kostos tis kilovatoras\n";
	cin>>cost_kwh4;
	cout<<"Dwse to kostos suntirisis ana monada kilovatoras\n";
	cin>>cost_suntirisis4;
}


float OIL::isxus4()
{
	float power;
	power=wriaia_katanalwsi*O_k;
	return power;
}



float OIL::cost4()
{
	float sum;
	sum=cost_kwh4+cost_suntirisis4+kostos_litrou;
	return sum;
}



/*H klassi Company A*/
class Company_A:public SUN,public GAS
{
public:
	Company_A(float _roh,float _wriaia);
	float calk_cost(float hours);
};


Company_A::Company_A(float _roh,float _wriaia):SUN(_roh),GAS(_wriaia)
{
	//Constructing Company_A
}


float Company_A::calk_cost(float hours)
{
	float kwh1,kwh2;
	kwh1=isxus1()*hours;
	kwh2=isxus2()*hours;
	return kwh1*cost1()+kwh2*cost2();
}




/*H klassi Company B*/
class Company_B:public AIR,public OIL
{
public:
	Company_B(float _speed,float _wriaia_katanalwsi);
	float calk_cost(float hours);
};


Company_B::Company_B(float _speed, float _wriaia_katanalwsi):AIR(_speed),OIL(_wriaia_katanalwsi)
{
	//Constructing Company_B
}


float Company_B::calk_cost(float hours)
{
	float kwh3,kwh4;
	kwh3=isxus3()*hours;
	kwh4=isxus4()*hours;
	return kwh3*cost3()+kwh4*cost4();
}



/*H klassi station*/
class station:public Company_A,public Company_B
{
public:
	station(float _roh,float _wriaia,float _speed,float _wriaia_katanalwsi);
	float calc_total_cost(float hours,float isxus);
};


station::station(float _roh, float _wriaia, float _speed, float _wriaia_katanalwsi):Company_A(_roh,_wriaia),Company_B(_speed,_wriaia_katanalwsi)
{
	//Constructing station
}


float station::calc_total_cost(float hours,float isxus)
{
	float kwh1,kwh2,kwh3,kwh4;
	if (isxus1()>=isxus)
	{
		kwh1=isxus1()*hours;
		return kwh1*cost1();
	}
	else if ((isxus1()+isxus3())>=isxus)
	{
		kwh1=isxus1()*hours;
		kwh3=isxus3()*hours;
		return kwh1*cost1()+kwh3*cost3();
	}
	else if ((isxus1()+isxus2()+isxus3())>=isxus)
	{
		kwh1=isxus1()*hours;
		kwh2=isxus2()*hours;
		kwh3=isxus3()*hours;
		return kwh1*cost1()+kwh2*cost2()+kwh3*cost3();
	}
	else
	{
		kwh1=isxus1()*hours;
		kwh2=isxus2()*hours;
		kwh3=isxus3()*hours;
		kwh4=isxus4()*hours;
		return kwh1*cost1()+kwh2*cost2()+kwh3*cost3()+kwh4*cost4();
	}

}




/*H main*/
void main()
{
	float _roh,_wriaia,_speed,_wriaia_katanalwsi,hours,isxus;
	cout<<"Dwse tis wres leitourgias\n";
	cin>>hours;
	cout<<"Dwse tin isxu pou xreiazetai o stathmos\n";
	cin>>isxus;
	cout<<"Dwse tin entasi tis fwteinis rohs\n";
	cin>>_roh;
	cout<<"Dwse tin wriaia katanalwsi fusikou aeriou\n";
	cin>>_wriaia;
	cout<<"Dwse tin taxutita tou anemou\n";
	cin>>_speed;
	cout<<"Dwse tin wriaia katanalwsi tou petrelaiou\n";
	cin>>_wriaia_katanalwsi;
	station T(_roh,_wriaia,_speed,_wriaia_katanalwsi);
	cout<<"To sunoliko kostos einai "<<T.calc_total_cost(hours,isxus)<<"\n";

	system("PAUSE");
}
