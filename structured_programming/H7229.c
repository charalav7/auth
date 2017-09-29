#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
int N,i,done;
FILE *fp;

printf("Dwse plh8os ypallhlwn :");
scanf("%d",&N);
struct flight {
int kwdikosy;
char name[41];
int flightnum;
char tproorismos[4],arxh[4],terma[4];
}Ypallhlos[N];
printf("Dwse ari8mo pthshs :");
scanf("%d",&Ypallhlos[0].flightnum);


for(i=0;i<N;i++)
{
printf("Dwse kwdiko tou %dou ypallhlou :",(i+1));
scanf("%d",&Ypallhlos[i].kwdikosy);
printf("Dwse onoma tou %dou ypallhlou :",(i+1));
scanf("%s",Ypallhlos[i].name);
printf("Dwse proorismo(kwdiko aerodromiou) %dou ypallhlou :",(i+1));
scanf("%s",Ypallhlos[i].tproorismos);
Ypallhlos[i].flightnum=Ypallhlos[0].flightnum;
strcpy(Ypallhlos[i].arxh,"000");
strcpy(Ypallhlos[i].terma,"000");

}
fp=fopen("flights","a+b");
if(fp==NULL) exit(1);

fwrite(Ypallhlos,2*sizeof(int)+41+4+4+4,N,fp);
done=0;
printf("Dwse afethria aeroplanou(kwdiko aerodromiou)");
scanf("%s",Ypallhlos[0].arxh);
while(done==0){
rewind(fp);
printf("Dwse epomenh stash aeroplanou(kwdiko aerodromiou)");
scanf("%s",Ypallhlos[0].terma);
for(i=0;i<N;i++)
{
fseek(fp,2*sizeof(int)+41+4,SEEK_CUR);
strcpy(Ypallhlos[i].arxh,Ypallhlos[0].arxh);
strcpy(Ypallhlos[i].terma,Ypallhlos[0].terma);
}
for(i=0;i<N;i++)
{
if(Ypallhlos[i].kwdikosy!=0){
if (strcmp(Ypallhlos[i].terma,Ypallhlos[i].tproorismos)==0){
printf("o Ypallhlos me kwdiko %d kai onoma %s 8a apobibastei sto aerodromio %s \n",Ypallhlos[i].kwdikosy,Ypallhlos[i].name,Ypallhlos[i].tproorismos);
Ypallhlos[i].kwdikosy=0;
}}
strcpy(Ypallhlos[i].arxh,Ypallhlos[i].terma);
}
fwrite(Ypallhlos,2*sizeof(int)+41+4+4+4,N,fp);
done=1;
for(i=0;i<N;i++){
if (Ypallhlos[i].kwdikosy!=0){
done=0;
break;}
}
}
printf("Oloi oi ypallhloi apobibasthkane!");
scanf("%d",&i);
}
