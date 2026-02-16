#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
return exp(x)-3*x;
}
int main(){
double a, fa;
cout<<"enter the value of the function a :"<<endl;
cin>>a;
fa= f(a);

cout <<" the value of the function is : "<< fa<<endl;


return 0;
}
