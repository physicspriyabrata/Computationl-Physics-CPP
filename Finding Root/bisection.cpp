#include<iostream>
#include<cmath>
using namespace std;

float bisection(float x)
{
   float fn =x*x*x - x*x - x -5; 
    return fn;
}



int main(){
int i =0; 
float a, b , c, fmean, y0, y1, e;
e=0.00001;
cin>>a>>b;

y0=bisection(a);

y1=bisection(b);
do{

c=(a+b)/2;
fmean=bisection(c);

if(y0 * y1>0){
cout << "wrong the guess value"<<endl;
break;
}
else{
if(y0 * fmean<0){
b=c;
}
if(y1 * fmean<0){
a=c;
}
}

 cout << "Iteration: " << i << "   Root: " << c << endl;
   i++;     

}while(fabs(b-a)>e);




return 0;
}

