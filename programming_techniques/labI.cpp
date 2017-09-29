#include <stdlib.h>
#include <malloc.h>
#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;

template <class type>
class calculator
{
      type x;
      type y;
      float k,mo;
public:
      calculator();
      type calc_sum();
      type calc_average();
      bool check_average(float k);
 };
  
  
template <class type>
calculator<type>:: calculator()
{
                   cout<<"dwse to x:";
                   cin>>x;
                   cout<<"dwse to y";
                   cin>>y;
}


template <class type>
type calculator<type>:: calc_sum()
{
                  type result;
                  result = x + y;
                  return result;
}

template <class type>
float calculator<type>:: calc_average()
{
      mo = (x+y)/2;
      return mo;
}

template <class type>
bool calculator<type>::check_average(float k)
{
     float t;
     k=t;
     if(t==mo){
               cout<<"i timi tautizetai";
               return (true);
     }
     else{
          cout<<"i timi den tautizetai";
          return (false);
     }
}

void main(){
     calculator<int> A;
     float k;
     cout<<"dwse to k:\n";
     cin>>k;
     cout<<A.calc_average;
     cout<<A.check_average(k);
}
               
               
                   
           
             
