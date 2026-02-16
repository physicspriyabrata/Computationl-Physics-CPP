//bisection method using iteration process{for loop)
#include<iostream>
#include<cmath>
using namespace std;
float bisection( float x){
float fn= x*x*x -x*x -x-5;
return fn;
}

int main(){
float a, b, c, y0, y1, fmean;
int i;
cout <<"enter the guess value"<<endl;
cin >>a >>b;
y0= bisection(a);
y1= bisection(b);

for(int i=0; i<20; i++){
c=(a+b)/2;
fmean= bisection(c);

if(y0*y1>0){
cout<<"wrong initial value"<<endl;
break;
}

else{
if(y0*fmean<0){
b=c;
}
if(y1*fmean<0){
a=c;
}
}
cout<<"iteration: "<< i<< "            Root: " <<c<<endl;
}


return 0;
}
