#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;
//function
double f(double x){
if(x==0)
return 1;
else 
return (sin(x))/x;
}
//trapezoidal simple
double trape(double a, double b, double n){
double h=(b-a)/n;
double sum=(f(a)+f(b))/2;
for(int i=1; i<n; i++){
double x=a+i*h;
sum+=f(x);
}
return sum*h;
}
//trapezoidal richardson
double trape_richardson(double a, double b, double n){
double Tr1=trape(a,b,n);
double Tr2=trape(a,b,n*2);
return (pow(2,2)*Tr2-Tr1)/(pow(2,2)-1);
}

int main(){
ofstream file1("trape_r.txt");
ofstream file2 ("richa_tra.txt");
cout<<fixed<<setprecision(17);

double a=0, b=1, h=0.05;
double n=(b-a)/h;

cout<<"Trapezoidal:"<<endl;

for(int i=1; i<=n; i++){
double n=(b-a)/n;
cout<<i<<"	"<<trape(a,b,i)<<endl;
file1<<i<<"	"<<trape(a,b,i)<<endl;
}
cout<<"Richardson Trapezoidal:"<<endl;
for(int i=1; i<=n; i++){
cout<<i<<"	"<<trape_richardson(a,b,i)<<endl;
file2<<i<<"	"<<trape_richardson(a,b,i)<<endl;
}
return 0;
}
