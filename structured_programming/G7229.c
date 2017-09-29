#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//thewrw oti oi ari8moi thlephonou einai oloi 10pshfioi
int main()
{
long int eis;
char numb[11],temp[11];
FILE *fp,*np;
int done,j,i=0,k,*pl;
if((np=fopen("numpers.txt","w+"))==NULL)
{
printf("ERROR");
exit (1);
}
do
{
do{
printf("Dwse ton ari8mo tou %dou syndromhth:",(i+1) );
scanf("%s",numb);
}
while(strlen(numb)!=10);
fputs(numb,np);
printf("dwse 1 gia synexeia,alliws 0 :");
i++;
scanf("%d",&done);
}
while(done!=0);
rewind(np);
pl=(int *)malloc(i*sizeof(int));
for(j=0;j<i;j++)
{
pl[j]=0;
}
for(;;)
{
do
{
printf("Dwse ari8mo syndromhth(0 gia termatismo) :");
scanf("%s",temp);
}
while(strlen(numb)!=10 && temp[0]!='0');
if(temp[0]=='0') break;
done=0;
for(j=0;j<i;j++)
{
fgets(numb,11,np);
if(strcmp(numb,temp)==0){ done=1; break; }
}
if(done==0) printf("den bre8hke o zhtoumenos syndromhths.. \n");
else
{
fp=fopen(strcat(temp,".txt"),"wb");
do
{
do
{
printf("Dwse eiserxomeno ari8mo gia ton ari8mo %s :",temp);
scanf("%ld",&eis);
}
while(eis<1000000000 && eis>0);
fprintf(fp,"%ld",eis);
pl[j]++;
printf("pathste 1 gia synexeia,alliws 0 : ");
scanf("%d",&done);
}
while(done!=0);
fclose(fp);
}
rewind(np);
}




for(j=0;j<i;j++)
{
fgets(numb,11,np);
printf("Syndromhths : %s \n",numb);
fp=fopen(strcat(numb,".txt"),"rb");
if (fp==NULL) printf("Kamia eggrafh gi auton ton syndromhth. \n");
else{
for(k=0;k<pl[j];k++)
{
fscanf(fp,"%10ld",&eis);
printf("%ld \n",eis);
}}


fclose(fp);

}


scanf("%d",&i);
} 