#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x){
return 1/(x*x +1);
} 




int main (){
double a,b, h;
int itr;
cout<< "enter the lower limit, upper limit and no. of iteration : "<<endl;
cin>>a>>b>>itr;
if (itr % 2 != 0) {
        cout << "Error: Number of intervals (n) must be even for Simpson's 1/3 Rule!" << endl;
        return 1;
        }
double fa, fb, sum, sum4, sum2;
fa= f(a);
fb= f(b);
for(int n=1; n<itr; n++){
h=(b-a)/n;
sum= fa+fb;
for(int i=1; i<n; i++){
if (n%2==0){
sum +=2*f(a+ i*h);
}
else{
sum +=4*f(a+i*h);
}
}

cout<<"no. of iteration: "<<n<< "      root "<< (h/3)*sum<<endl;
}



return 0;}
