#include<iostream>
#include<cmath>
using namespace std;
float function(float x){
float fn= x*x*x - x*x -x -5;
return fn;
}
float dfn( float x){
return 3*x*x- 2*x-1;
}



int main(){
cout<<"1. Bisection Method "<<endl<<endl<<endl;
int i; // iteration variable
float a, b, c; //a and b are guess variable and c is mean of a and b
float y0, y1, x0,x1, dy0, fmean; // these are the valuse of function at a, b, c
cout<<"enter the guess values a and b: "<<endl;
cin>>a>>b;
i=0;
float e ; //tolerance
e=0.00001;

do{
c=(a+b)/2;
y0= function(a);
y1= function(b);
fmean= function (c);
if(y0*y1>0){
cout<<"wrong guess values"<<endl;
break;
} else{
if(y0*fmean<0){
b=c;
}
if(y1*fmean<0){
a=c;
}
}
cout<<"interation: "<<i<<"       root: "<<c<<endl;

i++;
}while(fabs(b-a)>e);

cout<<endl<<endl<<"2. Newton Raphson Method: "<<endl<<"enter the initial values: "<<endl;
cin>>x0;


for(i=0; i<20; i++){
y0= function(x0);
dy0 = dfn(x0);
x1= x0- y0/dy0;
if(dy0 ==0){
cout <<"wrong initial value "<<endl;
}
else{
x0=x1;
cout<<"iteration: "<<i<<"		root: "<<x1<<endl;
}
}




return 0;
}
