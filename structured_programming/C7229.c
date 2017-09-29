#include <stdio.h>
#define MAX 100
void main()
{
 int i,j,A[MAX],H[MAX],C[MAX],b,start;
 float D[MAX][MAX],sum min;
 N=-1;
 while(N<0 || N>MAX)
 {
  printf("N=");
  scanf("%d",&N);
 }
 for(i=0;i<N;i++)
 {
  C[i]=i;
 }
 do{
  scanf("%d",&A[0]);
 }while(A[0]>=0 || A[0]<N);
 H[A[0]]=0;
 for(i=0;i<N;i++)
 {
  for(j=1;j<N;j++)
  { 
   printf("distance %d-%d=?",i,j);
   scanf("%f",&DI[i][j]);
  }
 }
 sum=0;
 for(i=0;i<N;i++)
 {
  if(i!=0)A[i]=start;
  min=DI[A[i]][start];
  for(j=1;j<N;j++)
  { 
   if(H[j]==0)continue;
   if(min>DI[A[i]][j])
   {
    min=DI[A[i]][j];
    b=j;
   }
  }
  start=C[b];
  H[start]=0;
  sum=sum+DI[A[i]][b];
 } 
 for(i=0;i<N;i++)
 {
  printf("%d",A[i]);
 }
 printf("%f",sum);
}
 