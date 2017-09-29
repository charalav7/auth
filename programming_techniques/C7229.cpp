#include <iostream>
#include <stdlib.h>

using namespace std;

class border_tax;
class tax
{
protected:

    char onoma[31];
    int afm;
    float forol_eis,foros,par_for,rate_for;

public:

    tax(float rate_eis);
    tax(float rate_eis,float kr_eis);
    float calk_tax();
    void out();
};

tax::tax(float rate_eis) : par_for(0)
{
    cout<<"Onoma forologoumenou:";
    do{
    cin.getline(onoma,30);
    }while(!onoma[0]);

    cout<<"AFM forologoumenou:";
    cin>>afm;
    cout<<"Eisodhma forologoumenou:";
    cin>>forol_eis;
}

tax::tax(float rate_eis,float kr_eis) : par_for(kr_eis)
{
    cout<<"Onoma forologoumenou:";
    do{
    cin.getline(onoma,30);
    }while(!onoma[0]);
    cout<<"AFM forologoumenou:";
    cin>>afm;
    cout<<"Eisodhma forologoumenou:";
    cin>>forol_eis;
}

float tax::calk_tax()
{
    return (foros=rate_for*forol_eis - par_for);
}

void tax::out()
{
    cout<<"\nO kos/H ka "<<onoma<<",me AFM:"<<afm<<" kai forologhteo eisodhma:"<<forol_eis<<" prepei na katavalei foro:"<<foros<<" eurw.\n";
}

class border_tax : public tax
{
protected:
    float rate_param;
public:

    border_tax(float rate_eis,float rate_p);
    border_tax(float rate_eis,float kr_eis,float rate_p);
    float calk_tax();
};

border_tax::border_tax(float rate_eis,float rate_p) : tax(rate_eis)
{
    rate_param = rate_p;
}

border_tax::border_tax(float rate_eis,float kr_eis,float rate_p) : tax(rate_eis,kr_eis)
{
    rate_param = rate_p;
}

float border_tax::calk_tax()
{
    return (foros = rate_for*forol_eis*(1- rate_param) - par_for);
}

class new_border_tax : public border_tax
{
    int xron;
    float rate_xron;

public:

    new_border_tax(float rate_eis,float rate_p,int xronia,float rate_newn);
    new_border_tax(float rate_eis,float kr_eis,float rate_p,int xronia,float rate_newn);
    float calk_tax();
};

new_border_tax::new_border_tax(float rate_eis,float rate_p,int xronia,float rate_newn) : border_tax(rate_eis,rate_p)
{
    xron=xronia;
    rate_xron=rate_newn;
}

new_border_tax::new_border_tax(float rate_eis,float kr_eis,float rate_p,int xronia,float rate_newn) : border_tax(rate_eis,kr_eis,rate_p)
{
    xron=xronia;
    rate_xron=rate_newn;
}

float new_border_tax::calk_tax()
{
    return (foros=rate_for*forol_eis*(1- rate_param)*(1 - rate_xron) - rate_for*forol_eis*rate_param*rate_xron - par_for);
}

float calk_total_tax(tax *a1,border_tax *a2,new_border_tax *a3,int k,int l,int m,float &tax_a1,float &tax_a2,float &tax_a3)
{
    int i;
    for(i=0; i<k; i++)
    {
        tax_a1 += a1[i].calk_tax();
    }
    for(i=0; i<l; i++)
    {
        tax_a2 += a2[i].calk_tax();
    }
    for(i=0; i<m; i++)
    {
        tax_a3 += a3[i].calk_tax();
    }
     return (tax_a1 + tax_a2 + tax_a3);
}

int main()
{
    float rate_tax,rate_para[10],rate_age;
    int k,l,m,n,i;
    float tax_a1,tax_a2,tax_a3;
    tax *a1;
    border_tax *a2;
    new_border_tax *a3;

    cout<<"Pososto forologhshs olwn twn forologoumenwn(%):";
    cin>>rate_tax;


    for(i=0; i<10; i++)
    {
        cout<<"Pososto meiwshs tou forou gia thn"<<" "<<i+1<<"h paramethorio perioxh(%):";
        cin>>rate_para[i];
    }

    cout<<"Pososto meiwshs tou forou gia tous katw twn 30 etwn forologoumenous twn paramethoriwn perioxwn(%):";
    cin>>rate_age;

    cout<<"\nArithmos forologoumenwn pou den katoikoun se paramethwria perioxh:";
    cin>>k;

    cout<<"Arithmos forologoumenwn pou katoikoun se paramethwria perioxh kai einai anw twn 30 etwn:";
    cin>>l;

    cout<<"Arithmos forologoumenwn pou katoikoun se paramethwria perioxh,einai katw twn 30 etwn k den exoun parakrathsh forou:";
    cin>>m;

    cout<<"Arithmos forologoumenwn pou katoikoun se paramethwria perioxh,einai katw twn 30 etwn k exoun parakrathsh forou:";
    cin>>n;



    a1=(tax*)malloc(k*sizeof(tax));
    if (a1==NULL)
    {
        exit(1);
    }

    if(k>0)
    {
    cout<<"\nGia thn forologhsh ekeinwn pou den katoikoun se paramethorio perioxh :\n";
    for(i=0;i<k;++i)
    {
        int pos;
        float krat(0);

        cout << "\nAp'to eisodhma tou "<<i+1<<"ou forologoumenou exoun ginei krathseis? Ean exei ginei pathste to 0: ";
        cin >> pos;
        if(pos == 0)
        {
            cout << "\nDwste krathseis forologoumenou:";
            cin >> krat;
        }

        tax temp(rate_tax,krat);
        a1[i]=temp;
    }
    }

    a2=(border_tax*)malloc(l*sizeof(border_tax));
    if (a2==NULL)
    {
        exit(1);
    }
    if(l>0)
    {
    cout<<"\nGia thn forologhsh ekeinwn pou katoikoun se paramethorio perioxh kai einai anw twn 30 etwn :\n";
    for (i=0; i<l; i++)
    {
        int pos;
        float krat(0);

        cout<<"\nAp'to eisodhma tou "<<i+1<<"ou forologoumenou exei ginei kapoia parakrathsh? Ean exei ginei pathste 0 : ";
        cin >> pos;
        if(pos == 0)
        {
            cout << "\nDwste krathseis forologoumenou:";
            cin >> krat;
        }

        int perioxh;
        do
        {
            cout << "O forologoumenos diamenei sthn perioxh me auxonta arithmo:";
            cin >> perioxh;
        }while(perioxh > 9 || perioxh <0);

        border_tax temp(rate_tax,krat,rate_para[perioxh]);
        a2[i]=temp;
    }
    }

    a3=(new_border_tax*)malloc((m+n)*sizeof(new_border_tax));
    if (a3==NULL)
    {
        exit(1);
    }
    if(m>0)
    {
    cout<<"\nGia thn forologhsh ekeinwn pou katoikoun se paramethorio perioxh,einai katw twn 30 etwn kai den exoun parakrathsh forou :\n";
    for (i=0; i<m; i++)
    {

        int age;
        cout<<"Dwste thn hlikia tou forologoumenou:";
        cin>>age;

        int perioxh;
        do
        {
            cout << "O forologoumenos diamenei sthn perioxh me auxonta arithmo:";
            cin >> perioxh;
        }while(perioxh > 9 || perioxh <0);


        new_border_tax temp(rate_tax,0,rate_para[perioxh],age,rate_age);
        a3[i]=temp;
    }
    }
    if(n>0)
    {
    cout<<"\nGia thn forologhsh ekeinwn pou katoikoun se paramethorio perioxh,einai katw twn 30 etwn kai exoun parakrathsh forou :\n";
     for (i=0; i<n; i++)
    {
        float krat(0);

            cout << "\nDwste krathseis forologoumenou:";
            cin >> krat;

    int age;
        cout<<"Dwste thn hlikia tou forologoumenou:";
        cin>>age;

        int perioxh;
        do
        {
            cout << "O forologoumenos diamenei sthn perioxh me auxonta arithmo:";
            cin >> perioxh;
        }while(perioxh > 9 || perioxh <0);

        new_border_tax temp(rate_tax,perioxh,age,rate_age);
        a3[i + m]=temp;
    }
    }


    for(i=0;i<k;++i)
    {

        a1[i].calk_tax();
        a1[i].out();
    }

    for(i=0;i<l;++i)
    {
        a2[i].calk_tax();
        a2[i].out();
    }

    for(i=0;i<(m+n);++i)
    {
        a3[i].calk_tax();
        a3[i].out();
    }

    float sun_tax=calk_total_tax(a1,a2,a3,k,l,m,tax_a1,tax_a2,tax_a3);
    cout<<"\nO sunolikos foros pou tha eispraxthei ap'tous forologoumenous pou den katoikoun se paramethorio perioxh einai:"<<tax_a1<<"\n";
    cout<<"O sunolikos foros pou tha eispraxthei ap'tous forologoumenous pou katoikoun se paramethorio perioxh einai:"<<tax_a2<<"\n";
    cout<<"O sunolikos foros pou tha eispraxthei ap'tous forologoumenous pou katoikoun se paramethorio perioxh kai einai katw twn 30 etwn einai:"<<tax_a3<<"\n";

    cout<<"O sunolikos foros pou tha eispraxthei apo olous tous forologoumenous einai:"<<sun_tax<<"\n";

    free(a1);
    free(a2);
    free(a3);

    cin.get();

    return 0;
}
