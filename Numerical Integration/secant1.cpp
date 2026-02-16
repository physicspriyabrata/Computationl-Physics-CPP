#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x){
return x*x*x- 4*x +1;
}



int main(){
int i, n;
double x0, x1,x2, f0=0, f1=0;
cout<<"enter the initial values x1 and x0 :"<< endl;
cin>>x0>>x1;
for(i=0; i<20; i++){
f0=f(x0);
f1=f(x1);

x2=x0-((f0*(x1-x0))/(f1-f0));
if(f1-f0 ==0){
cout<<"wrong initial value"<<endl;
break;
}
else{


x1=x2;

cout<<"no. of iteration: "<<i<<"   root of function: "<< x2<<endl;


}
}
return 0;
}
