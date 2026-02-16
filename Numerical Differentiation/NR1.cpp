#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x){
return exp(x)-3*x;
}
double df( double x){
return exp(x)-3;
}


int main(){
int i, n;
double x0,x1, f0, df0;
cout<<"enter the initial value"<<endl;
cin>>x0;
for(i=0; i<20; i++){
f0=f(x0);
df0= df(x0);
x1=x0 - (f0/df0);
if (df0==0){
cout<<"wrong initial value "<<endl;
break;
}
else{
x0=x1;
}
cout<<"no. of interation: "<<i<< "    root of the function: "<< x1<<endl;

}
return 0;
}
