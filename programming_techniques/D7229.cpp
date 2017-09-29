#include <iostream>
using namespace std;

class SUN {
protected:
	float epifaneia,s_k,light;
	float cost_s,cost_sh;
public:
	SUN(float light);
	float s_power();
	float s_cost();
};

SUN::SUN (float light)
{
	cout<<"dwse epifaneies sulektwn\n";
	cin>>epifaneia;
	cout<<"dwse suntelesti apodosis\n";
	cin>> s_k;
	cout<<"dwse kostos kilovatwras\n";
	cin>> cost_s;
	cout<<"dwse to ana kilovatwra kostos suntirisis\n";
	cin>> cost_sh;
}

float SUN::s_power()
{
	float power;
	power=epifaneia*light*s_k;
	return power;
}

float SUN::s_cost()
{
	float cost;
	cost=cost_s+cost_sh;
	return cost;
}

class GAS{
protected:
	float wriaia,s_k,meter_g;
	float cost_g,cost_gh;
public:
	GAS(float wriaia);
	float g_power(float wriaia);
	float g_cost();
}

GAS::GAS(float wriaia)
{
	cout<<"dwse kostos enos kuvikou metrou fusikou aeriou\n";
	cin>>meter_g;
	cout<<"dwse suntelesti apodosis\n";
	cin>>s_k;
	cout<<"dwse kostos kilovatwras\n";
	cin>> cost_g;
	cout<<"dwse to ana kilovatwra kostos suntirisis\n";
	cin>> cost_gh;
}

float GAS::g_power(float wriaia)
{
	float power;
	power= s_k*wriaia;
	return power;
}

float GAS::g_cost()
{
	float cost;
	cost= cost_g+cost_gh+meter_g;
	return cost;
}


class AIR {
protected:
	float a_k,speed;
	float cost_a,cost_ah;
public:
	AIR(float speed);
	float a_power();
	float a_cost();
};

AIR::AIR (float speed)
{
	cout<<"dwse suntelesti apodosis\n";
	cin>> a_k;
	cout<<"dwse kostos kilovatwras\n";
	cin>> cost_a;
	cout<<"dwse to ana kilovatwra kostos suntirisis\n";
	cin>> cost_ah;
}

float AIR::a_power()
{
	float power;
	power=speed*a_k;
	return power;
}

float AIR::s_cost()
{
	float cost;
	cost=cost_a+cost_ah;
	return cost;
}

class OIL{
protected:
	float o_wriaia,o_k,meter_o;
	float cost_o,cost_oh;
public:
	OIL(float wriaia);
	float o_power(float o_wriaia);
	float o_cost();
}

OIL::OIL(float o_wriaia)
{
	cout<<"dwse kostos enos litrou petrelaiou\n";
	cin>>meter_o;
	cout<<"dwse suntelesti apodosis\n";
	cin>>o_k;
	cout<<"dwse kostos kilovatwras\n";
	cin>> cost_o;
	cout<<"dwse to ana kilovatwra kostos suntirisis\n";
	cin>> cost_oh;
}

float OIL::o_power(float o_wriaia)
{
	float power;
	power= o_k*o_wriaia;
	return power;
}

float OIL::o_cost()
{
	float cost;
	cost= cost_o+cost_oh+meter_o;
	return cost;
}

class company_A: public SUN, public GAS
{
public:
	company_A(float light,float wriaia);
	float calc_cost(float hours);
	float total_cost;
}

company_A::company_A(float light,float wriaia): SUN(light), GAS(wriaia)
{
	//Constructing Company_A
}

float company_A::calc_cost(float hours);
{
	float kwh_s,kwh_g;
	kwh_s=s_power()*hours;
	kwh_g=g_power()*hours;
	return kwh_s*s_cost+kwh_g*g_cost;
}


class company_B: public AIR, public OIL
{
public:
	company_B(float speed,float o_wriaia);
	float calc_cost(float hours);
	float total_cost;
}

company_B::company_B(float speed,float o_wriaia): AIR(speed), OIL(o_wriaia)
{
	//Constructing Company_B
}

float company_B::calc_cost(float hours);
{
	float kwh_a,kwh_o;
	kwh_a=a_power()*hours;
	kwh_o=o_power()*hours;
	return kwh_a*a_cost+kwh_o*o_cost;
}

class station:public company_A,public company_B
{
public:
	float calc_total_cost(float hours,float power);
	station(float light,float wriaia,float speed,float o_wriaia);
}

station::station(float light, float wriaia, float speed, float o_wriaia):Company_A(light,wriaia),Company_B(speed,o_wriaia)
{
	//Constructing station
}


float station::calc_total_cost(float hours,float power)
{
	float kwh_s,kwh_g,kwh_a,kwh_o;
	if (s_power()>=power)
	{
		kwh_s=s_power()*hours;
		return kwh_s*s_cost();
	}
	else if ((s_power()+g_power())>=power)
	{
		kwh_s=s_power()*hours;
		kwh_g=g_power*hours;
		return kwh_s*s_cost()+kwh_g*g_cost();
	}
	else if ((s_power()+g_power()+a_power())>=power)
	{
		kwh_s=s_power()*hours;
		kwh_g=g_power()*hours;
		kwh_a=a_power()*hours;
		return kwh_s*s_cost()+kwh_g*s_cost()+kwh_a*s_cost();
	}
	else
	{
		kwh_s=s_power()*hours;
		kwh_g=g_power()*hours;
		kwh_a=a_power()*hours;
		kwh_o=o_power()*hours;
		return kwh_s*s_cost()+kwh_g*g_cost()+kwh_a*a_cost()+kwh_o*o_cost();
	}

}




/*H main*/
void main()
{
	float light,wriaia,speed,o_wriai,hours,power;
	cout<<"Dwse tis wres leitourgias\n";
	cin>>hours;
	cout<<"Dwse tin isxu pou xreiazetai o stathmos\n";
	cin>>power;
	cout<<"Dwse tin entasi tis fwteinis rohs\n";
	cin>>light;
	cout<<"Dwse tin wriaia katanalwsi fusikou aeriou\n";
	cin>>wriaia;
	cout<<"Dwse tin taxutita tou anemou\n";
	cin>>speed;
	cout<<"Dwse tin wriaia katanalwsi tou petrelaiou\n";
	cin>>o_wriaia;
	station T(light,wriaia,speed,o_wriaia);
	cout<<"To sunoliko kostos einai: "
    cout<<T.calc_total_cost(hours,power);

	system("PAUSE");
}
