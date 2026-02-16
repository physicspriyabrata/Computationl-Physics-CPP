#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
double y= ((exp(x))*sin(x))/x;
return y; 
}
double forward(double x, double h){
return (f(x+h)-f(x))/h;
}
int main(){
double x0, h;
cout<<"enter the value of x0: ";
cin>>x0;
cout <<"enter the value of step size h: ";
cin>>h;
double result=forward(x0, h);
cout<<"The derivative of this function at x0 is: "<<result<<endl; 



return 0;
}
