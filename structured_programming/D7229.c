#include <stdio.h>
#include <math.h>
#include <alloc.h>

int dis_alarm(float xa,float ya,float za,float x,float y,float z,float sd)
{
 int a;
 float d;
 d=sqrt((x-xa)*(x-xa)+(y-ya)*(y-ya)+(z-za)*(z-za));
 if(d<=sd)
 {
  a=1;
  return a;
 else
 {
  a=0;
  return a;
 }
}


int main()
{
 int i,j,a,N;
 float x,y,z,C[N],d;
 printf("number of planes=");
 scanf("%d",&N);
 float *C
 C=(float*)malloc(N*sizeof(float));
 if(C==NULL)
 {
  printf("error1\n");
  return 1;
 }
 printf("safe distance=")
 scanf("%f",&sd);
 for(;;)
 {
  scanf("%f%f%f",&x,&y,&z);
  if(z==0)break;
  for(i=0;i<N-1;i++)
  {
   for(j=0;j<3;j++)
   { 
    scanf("%f",C[i][j]);
   }
   dis_alarm(C[i][0],C[i][1],C[i][2],x,y,z,sd)
   if(a==1)printf("possible collision\n");
   d=sqrt((x-C[i][0])*(x-C[i][0])+(y-C[i][1])*(y-C[i][2])+(z-C[i][2])*(z-C[i][2]));
   printf("distance",d);
  }
 }
}