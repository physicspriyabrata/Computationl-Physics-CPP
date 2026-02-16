#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x) {
return x*x*x- 4*x +1;
}

int main(){
int i, n;
double f0=0 , f1=0, a, b,c, fc=0;
cout<< "enter the value of a and b which is the interval of the function and iteration n respectively: "<< endl;   //the good interval is [0,1]
cin>>a>>b>>n;
f0= f(a);
f1= f(b);


for (i=0; i<n; i++){
c=(a+b)/2;
fc= f(c);
if (f0*f1>0){
cout<<"wrong initial values"<<endl;
break;
}
else{
if(f0*fc<0){
b=c;
}
if (f1*fc<0){
a=c;
}
}
cout<< "no of iteration    "<< i<< "root of function   "<< c<<endl;

}



return 0;
}
