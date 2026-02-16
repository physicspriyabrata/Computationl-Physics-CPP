#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x){
return 1/(x*x +1);
}



ofstream file("simpson38.txt");
int main(){
int n;
double a, b, h, fa, fb, sum , sum2=0, sum3=0;
cout<<"enter the lower limit , upper limit and no. of iteration:"<<endl;
cin>>a>>b>>n;


if (n%3!=0){
cout<<"wrong";
return 1;
}

fa=f(a);
fb=f(b);
sum=fa+fb;
h=(b-a)/n;
for(int i=1; i<n; i++){


if(i%3==0){
sum2 += 2*f(a+ i*h);
}
else{
sum3 +=3*f(a+i*h);
}
cout<<"iteration:   "<<i<<"       root "<< (3.0/8)*h*(sum+sum2+sum3)<<endl;
file<<i<<"    "<< (3.0/8)*h*(sum+sum2+sum3)<<endl;
}
cout<< (3.0/8)*h*(sum+sum2+sum3)<<endl;

file.close();
return 0;
}
