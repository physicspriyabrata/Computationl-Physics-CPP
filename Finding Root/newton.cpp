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


int i;
i=0;
do {
f0=newton(x0);
df0=dnewton(x0);
x1=x0 - f0/df0;

if (df0==0){
cout << "wrong initial value"<<endl;
break;
}
else{
x0=x1;

cout<<"interation: "<< i<<  "		Root"<<x1<<endl;
i++;
}
}while(fabs(x1-x0)>e);





return 0;
}
