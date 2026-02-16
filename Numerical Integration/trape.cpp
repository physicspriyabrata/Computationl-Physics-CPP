//trapizoidal rule using for loop.
#include <iostream>
#include<cmath>
#include<fstream>
using namespace std;
double trapizoidal(double x){
return 1/(pow(x,2)+1);   //this function to integrate

}
ofstream f("trap.txt");
int main(){
double i , n; //iteration variable
double a,b;  //a is lower limit and b is upper limit
cout<<"enter the lower, upper limit and no of iteration respectivly:"<<endl;
cin>>a>>b>>n;
double sum=0 , h, sum1=0, ans, error;
h=(b-a)/n;
double y0 , yn ;  //the value of function at a and b and any values
y0=trapizoidal(a);
yn= trapizoidal (b);


double fun=1.4056;
for(i=1; i<n; i++){
sum1=(y0+yn)/2;
sum1 +=h*(trapizoidal(a+i*h));


error=fabs(sum1-fun);
double rerr = (error/fun)*100;
cout<<"iteration: "<<i<<"   value of integration:  "<<sum1<<"    error in %:  "<<rerr<<endl;

}

cout<<ans<<endl;
cout<<(sum1+2*trapizoidal(a+1*h))*h*0.5<<endl;
f.close();
return 0;
}

