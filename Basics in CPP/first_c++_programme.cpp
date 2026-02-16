#include<iostream>
using namespace std;
#include <cmath>
#include <fstream>

//harmonic oscillattor;

int main()
{
  int t,s;//itrative 
  float x0;//amplitude
  float x[100];//position 
  float phi;//phase
  float w,time,dt;//frequency 
  phi=0.0;w=2.0;x0=2.0;time = t*dt;dt=0.01;
  do
  {
    x[t] = x0*cos(w*time+phi);
    cout<<time<<"   "<<x[t]<<endl;
    t++;
    
  }while(t<200);
  return 0;
}
