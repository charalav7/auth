#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>

int  **penalty(int k,float *limit,int *A,float **speed);

void main()
{
    int k,i,j,*A,**number,**paravasi;
	float *limit,**speed;
	
	do
	    {
		    printf("Dwse ari8mo kamerwn:\n");
			scanf("%d",&k);
		}
    while (k<=0);
    limit=(float *)malloc(k*sizeof(float));
	if (limit==NULL)
	    {
		    printf("error1\n");
			exit (0);
	    }
    A=(int *)malloc(k*sizeof(int));
	if (A==NULL)
	    {
		    printf("error2\n");
			exit (0);
	    }

    for (i=0;i<k;i++)
        {
            do
                {
                    printf("Dwse orio taxutitas gia tin %d kamera:\n",i+1);
                    scanf("%e",&limit[i]);
                }
            while (limit[i]<=0);
        
            do 
                {
                    printf("Dwse ton ari8mo twn autokinitwn pou paraviasan tin %d kamera:\n",i+1);
                    scanf("%d",&A[i]);
                }
            while (A[i]<0);
        }
    
	speed=(float **)malloc(k*sizeof(float *));
    if (speed==NULL)
        {
            printf("error3\n");
            exit (0);
        }
    for (i=0;i<k;i++)
        {
            speed[i]=(float *)malloc(A[i]*sizeof(float));
            if (speed[i]==NULL)
                {
                    printf("error4\n");
                    exit (0);
                }
        }

    number=(int **)malloc(k*sizeof(int *));
    if (number==NULL)
        {
            printf("error5\n");
            exit (0);
        }
    for (i=0;i<k;i++)
        {
            number[i]=(int *)malloc(A[i]*sizeof(int));
            if (number[i]==NULL)
                {
                    printf("error6\n");
                    exit (0);
                }
        }

    for (i=0;i<k;i++)
        {
            for (j=0;j<A[i];j++)
                {
                            printf("Dwse tin taxutita tou autokinitou %d, pou paraviase tin %d camera:\n",j+1,i+1);
                            scanf("%e",&speed[i][j]);
							
                    do
                        {
                            printf("Dwse ton ari8mo kukloforias tou autokinitou %d,pou paraviase tin %d kamera:\n",j+1,i+1);
                            scanf("%d",&number[i][j]);
                        }
                    while (number[i][j]<=0);
                }
        }

    paravasi=penalty(k,limit,A,speed);
	
	for (i=0;i<k;i++)
	    {
		    for (j=0;j<A[i];j++)
			    {
				    printf("O paravatis me ari8mo kukloforias\n -->%d\n pou ton entopise i kamera %d\n etrexe me taxutita\n -->%f\n kai gi auto entasetai stin %d katigoria\n",number[i][j],i+1,speed[i][j],paravasi[i][j]);
				}
        }

    free(limit);
    free(A);
    for (i=0;i<k;i++)
        {
            free(speed[i]);
            free(number[i]);
            free(paravasi[i]);
        }
	free(speed);
    free(number);
    free(paravasi);	

}	



int **penalty(int k,float *limit,int *A,float **speed)
    {
	    int i,j,**paravasi;
	    
        paravasi=(int **)malloc(k*sizeof(int *));
        if (paravasi==NULL)
            {
                printf("error7\n");
                exit (0);
            }
        for (i=0;i<k;i++)
            {
                paravasi[i]=(int *)malloc(A[i]*sizeof(int));
				if (paravasi[i]==NULL)
				    {
					    printf("error8\n");
						exit (0);
                    }
            }
       
        for (i=0;i<k;i++)
            {
                for (j=0;j<A[i];j++)
                    {
                        if ((speed[i][j]-limit[i])<=((10/100)*limit[i])) paravasi[i][j]=1;
                        else if ((speed[i][j]-limit[i])<=((20/100)*limit[i])) paravasi[i][j]=2;
                        else paravasi[i][j]=3;
                    }
            }
		return paravasi;	
    }			
        				
			
	
    		