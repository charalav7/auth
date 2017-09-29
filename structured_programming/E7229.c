#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>

int Rshort(int A,int N)
{
 int i,j,temp;
 for(i=1;i<N;i++)
 { 
  for(j=N;j<i;j--)
  {
   if(A[j-1]>A[j])
   {
    temp=A[j-1];
    A[j-1]=A[j];
    A[j]=temp;
   }
  }
 }
 return A;
}

int main()
{
 int N,A,R,j,i,number,number2,d,z,l,k;
 printf("N=");
 scanf("%d",&N);
 int *A;
 A=(int*)malloc(N*sizeof(int));
 if(A==NULL)
 {
  printf("error1\n");
  return 1;
 }
 do{
  printf("arxikos arithmos xwritikothtas=");
  scanf("%d",&R);
 }while(R<=N);
 for(i=0;i<R;i++)
 {
  scanf("%d",&A[i]);
 }
 Rshort(A,R);
 printf("arithmos diagrafwn=");
 scanf("%d",&k);
 for(i=0;i<k;i++)
 {
  scanf("%d",&number);
  for(j=0;j<R;j++)
  {
   if(number==A[j])
   {
    free(A[j]);
   }
  }
 }
 d=R-k;
 Rshort(A,d);
 printf("nees egrafes=");
 do{
  scanf("%d",&l);
 }while(R-k+l<=N);
 for(i=0;i<l;i++)
 {
  scanf("%d",&number2);
  A[R-k+i]=number2;
 }
 z=R-k+l;
 Rshort(A,z);
 for(i=0;i<z;i++)
 {
  printf("%d",A[i]);
 }
 free(A);
}