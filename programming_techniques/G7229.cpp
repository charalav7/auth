#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class stathmos{
protected:
     static stathmos **S;
     static int n;
public:
     stathmos(){};
     virtual float isxys()=0;
     virtual void print_params()=0;
     virtual float get_isxy_0()=0;
     static stathmos **get_S(){return S;};
     static int get_n(){return n;};
};

stathmos **stathmos::S;
int stathmos::n;

void alert(stathmos **aray,int n,float power){
     float synolikh_isxy=0,ypoloipo,help=0;
     int i;

     for (i=0;i<n;i++)synolikh_isxy+=aray[i]->isxys();
     for (i=0;i<n;i++)help+=aray[i]->get_isxy_0();
     power+=help;

     if(power<=0.8*synolikh_isxy){
          ypoloipo=synolikh_isxy-power;
          cout << "\n\n\n\nPrasinos Synagermos!\nH perisevamenh isxys einai: " << ypoloipo << " kW";
     }
     else if(power<=0.9*synolikh_isxy && power>0.8*synolikh_isxy){
          ypoloipo=synolikh_isxy-power;
          cout << "\n\n\n\nKitrinos Synagermos!\nH perisevamenh isxys einai: " << ypoloipo << " kW";
     }
     else if(power<=synolikh_isxy && power>0.9*synolikh_isxy){
          ypoloipo=synolikh_isxy-power;
          cout << "\n\n\n\nPortokalh Synagermos!\nH perisevamenh isxys einai: " << ypoloipo << " kW";
     }
     else{
          ypoloipo=power-synolikh_isxy;
          cout << "\n\n\n\nKokkinos Synagermos!\nXreiazetai akoma: " << ypoloipo << " kW isxyws";
     }
}


void print(stathmos **aray,int n){
     for(int i=0;i<n;i++)aray[i]->print_params();
}


class petrelaio:public stathmos{
     int n1;
     char **name;
     bool *katastash;
     float *isxy_0,*wriaia_katanalwsh,*syntelesths;
public:
     petrelaio();
     void set_params();
     float isxys();
     void print_params();
     float get_isxy_0();
}oil1;
petrelaio::petrelaio(){
     cout << "Dwse ton arithmo twn stathmwn pou leitourgoun me petrelaio:";
     cin >> n1;

     set_params();

     n++;
     if(n==1) S=(stathmos **)malloc(sizeof(stathmos *));
     else S=(stathmos **)realloc(S,n*sizeof(stathmos *));
     S[n-1]=this;
}

void petrelaio::set_params(){
     int i;
     name=new char *[n1];
     for(i=0;i<n1;i++) name[i]=new char [10];
     katastash=new bool [n1];
     isxy_0=new float [n1];
     wriaia_katanalwsh=new float [n1];
     syntelesths=new float [n1];

     if(n1)cout << "\n\nPetrelaio:";
     for (i=0;i<n1;i++){
          cout << "\n" << i+1 << "os Stathmos:\n";
          cout << "Dwse thn tautothta tou stathmou (mexri 10 xarakthres):";
          cin >> name[i];
          cout << "Dwse 0 an o sthathmos den leitourgei alliws dwse 1:";
          cin >> katastash[i];
          if(!katastash[i]){
                cout << "Dwse thn isxy pou katanalwnei o stathmos otan einai se efedreia:";
                cin >> isxy_0[i];
                wriaia_katanalwsh[i]=syntelesths[i]=0;
          }
          else{
               isxy_0[i]=0;
               cout << "Dwse thn wriaia katanalwsh petrelaiou:";
               cin >> wriaia_katanalwsh[i];
               cout << "Dwse ton syntelesth apodoshs:";
               cin >> syntelesths[i];
          }
     }
}
float petrelaio::isxys(){
     float sum=0;
     for(int i=0;i<n1;i++) sum+=wriaia_katanalwsh[i]*syntelesths[i];

     return sum;
}
void petrelaio::print_params(){
     if(n1)cout << "\n\nKatastash stathmwn petrelaiou!";
     for(int i=0;i<n1;i++){
          cout << "\nTautothta " << i+1 << "ou stathmou: " << name[i];
          if(katastash[i])cout << "\nO stathmos leitourgei!\n";
          else cout << "\nStathmos ektos leitourgeias!\n";
     }
}
float petrelaio::get_isxy_0(){
     float sum=0;
     for(int i=0;i<n1;i++)sum+=isxy_0[i];
     
     return sum;
}


class hlios:public stathmos{
     int n2;
     char **name;
     bool *katastash;
     float *isxy_0,*fwthnh_isxy,*syntelesths,*epifaneia;
public:
     hlios();
     void set_params();
     float isxys();
     void print_params();
     float get_isxy_0();
}sun1;
hlios::hlios(){
     cout << "\n\nDwse ton arithmo twn stathmwn pou leitourgoun me hliakh energeia:";
     cin >> n2;

     set_params();

     n++;
     if(n==1) S=(stathmos **)malloc(sizeof(stathmos *));
     else S=(stathmos **)realloc(S,n*sizeof(stathmos *));
     S[n-1]=this;
}

void hlios::set_params(){
     int i;
     name=new char *[n2];
     for(i=0;i<n2;i++) name[i]=new char [10];
     katastash=new bool [n2];
     isxy_0=new float [n2];
     fwthnh_isxy=new float [n2];
     syntelesths=new float [n2];
     epifaneia=new float [n2];

     if(n2)cout << "\n\nHliakh Energeia:";
     for (i=0;i<n2;i++){
          cout << "\n" << i+1 << "os Stathmos:\n";
          cout << "Dwse thn tautothta tou stathmou (mexri 10 xarakthres):";
          cin >> name[i];
          cout << "Dwse 0 an o sthathmos den leitourgei alliws dwse 1:";
          cin >> katastash[i];
          if(!katastash[i]){
                cout << "Dwse thn isxy pou katanalwnei o stathmos otan einai se efedreia:";
                cin >> isxy_0[i];
                fwthnh_isxy[i]=syntelesths[i]=epifaneia[i]=0;
          }
          else{
               isxy_0[i]=0;
               cout << "Dwse thn fwthnh isxy shmera:";
               cin >> fwthnh_isxy[i];
               cout << "Dwse ton syntelesth apodoshs:";
               cin >> syntelesths[i];
               cout << "Dwse thn epifaneia tou sylekth:";
               cin >> epifaneia[i];
          }
     }
}
float hlios::isxys(){
     float sum=0;
     for(int i=0;i<n2;i++) sum+=fwthnh_isxy[i]*epifaneia[i]*syntelesths[i];

     return sum;
}
void hlios::print_params(){
     if(n2)cout << "\n\nKatastash stathmwn hliakhs energeias!";
     for(int i=0;i<n2;i++){
          cout << "\nTautothta " << i+1 << "ou stathmou:" << name[i];
          if(katastash[i])cout << "\nO stathmos leitourgei!\n";
          else cout << "\nStathmos ektos leitourgeias!\n";
     }
}
float hlios::get_isxy_0(){
     float sum=0;
     for(int i=0;i<n2;i++)sum+=isxy_0[i];
     
     return sum;
}

int main(){
     stathmos **A;
     int n;

     n=stathmos::get_n();
     A=stathmos::get_S();

     
     float power;
     for(;;){
          cout << "\n\n\nDwse thn isxy pou xreiazetai h polh(0 gia eksodo):";
          cin >> power;

          if (power!=0) alert(A,n,power);
          else break;
     }
     
     print(A,n);

     getch();
     return 0;
}