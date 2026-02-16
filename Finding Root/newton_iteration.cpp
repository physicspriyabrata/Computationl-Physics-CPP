//finding the root using the newton raphson method
#include<iostream>
#include<cmath>
using namespace std;
float newton( float x){          //define the function
float function=x*x*x - x*x- x- 5;
return function;
}
float dnewton(float x){
return 3*x*x-2*x-1;   // derivative of the function
}
int main(){
float x1, x0, f0, df0;   // variable
float e= 0.001;  // tolerance
cout<< "enter the guess value"<< endl;
cin>>x0;

for(int i=0; i<20; i++){
f0=newton(x0);
df0=dnewton(x0);
x1=x0 - f0/df0;
x0=x1;
cout<<"iteration: "<<i<<"		root"<<x1<<endl;
}



return 0;
}
