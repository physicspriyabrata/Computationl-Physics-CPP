//finding root using secant method and for loop use.
#include<iostream>
#include<cmath>
using namespace std;
float secant( float x){
float fn=x*x*x-x*x-x-5;   // equation of function
return fn;
}



int main(){
int i;  //iteration varivale
float x0, x1, x2; //guess variables
float e;  //tolerance
e=0.001;
cout<<"enter the initial values: "<<endl;
cin>>x0>>x1;
float f0, f1; // guess value of function

for(i=0; i<20; i++){
f0=secant(x0);
f1=secant (x1);

x2= x0- (f0*(x1-x0))/(f1-f0);
if((f0-f1)==0){
cout <<"wrong initial values"<<endl;
break; 
}else{
x1=x2;
cout<<"iteration:"<<i<<"	  root: "<<x1<<endl;
}
}
return 0;
}
