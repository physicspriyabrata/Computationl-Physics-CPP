#include<iostream>
#include<cmath>
using namespace std; 
double f(double x){
return (exp(x)*sin(x))/x;
}
double central(double x, double h){
return (f(x+h)-f(x-h))/(2*h);

}
int main(){
double x0, h;
cout<<"enter the value of x0: ";
cin >>x0;
cout<<"enter the value of step size h : ";
cin >>h;
double result= central(x0, h);
cout<<"The value derivative of the function at x0 is : "<<result<<endl;
return 0;
}
