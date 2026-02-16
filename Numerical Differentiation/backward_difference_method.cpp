#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
return (exp(x)*sin(x))/x;

}
double backward(double x, double h){
return (f(x)-f(x-h))/h ;
}

int main(){
double x0, h;
cout<<"enter the value of x0: ";
cin>>x0;
cout<<"enter the value of step size h: ";
cin>>h;
double result=backward(x0, h);
cout <<"The derivative of this function at x0 is: "<<result<<endl;


return 0;
}
