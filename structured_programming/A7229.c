#include <stdio.h>
#include <math.h>
void main()
{ int N,k;
  float Pi,P,d,Pmin,x,y,xr,yr,mP,MP,mx,my,Mx,My;
  scanf("%i",&N);
  scanf("%f%f",&x,&y);
  do{
   scanf("%f",&Pmin);
  }while(Pmin>0);
  mP=9999;
  MP=0;
  for(k=1;k<=N;k++){
   scanf("%f%f",&xr,&yr);
   do{
    scanf("%f",&Pi);
   }while(Pi>0);
   d=sqrt((xr-x)*(xr-x)+(yr-y)*(yr-y));
   P=Pi/(d*d);
   if(P>Pmin){
    if(P<mP){
     mP=P;
     mx=xr;
     my=yr;
    }
    if(P>MP){
     MP=P;
     Mx=xr;
     My=yr;
    }
  }
  }
  printf("%f%f%f%f%f%f/n",mx,my,Mx,My,mP,MP);
  }