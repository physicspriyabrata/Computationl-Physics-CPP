// finite difference method
#include<iostream>
#include<cmath>
using namespace std;
//function
double f(double x){
return (exp(x)*sin(x))/x;
}
//function of forward difference method
double forward(double x, double h){
return (f(x+h)-f(x))/h;
}
//function of backward difference method
double backward(double x, double h){
return (f(x)-f(x-h))/h;
}
//function of central diffeerence method
double central(double x, double h){
return (f(x+h)-f(x-h))/(2*h);
}
int main(){
double x0, h;   //h is the step size
cout<<"Enter the value of x0: ";
cin>>x0;
cout<<"Enter the value of step size h: ";
cin>>h;
double points_forward=forward(x0, h);
cout<<"derivative of this function at x0 using forward difference method is :  "<<points_forward<<endl;
double points_backward=backward(x0, h);
cout<<"Derivative of this function at x0 using backward difference method is :  "<<points_backward<<endl;
double points_central=central(x0, h);
cout<<"Derivative of this function at x0 using central difference method is :  "<<points_central<<endl;
return 0;
}
