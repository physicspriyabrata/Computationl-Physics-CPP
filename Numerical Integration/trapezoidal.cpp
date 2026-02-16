//Trapezoidal rules using iteration method
#include<iostream>
#include<cmath>
using namespace std;
//function
double f(double x){
return sin(x);
}
//intgration of the function
double intf(double x){
return -cos(x);
}
//Trapezoidal method
double trap(double a, double b, int n){
double h=(b-a)/n;
double sum=(f(a)+f(b))/2;
for(int i=1; i<n; i++){

double x=a+i*h;
sum+=f(x);
}
return sum*h;
}
int main(){
double a=0;
double b=1;
int n=100;
cout<<"no. of iteration:"  <<"			"<<"values of interation: "<<"		"<<"real intgration:"<<endl;
for (int i=1; i<n; i++){
cout<<i<<"	"<<trap(a,b,i)<<endl;

}
return 0;
}
