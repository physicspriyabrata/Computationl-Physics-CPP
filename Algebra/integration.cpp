#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
float simpson( float x){

return 4*x*x*x;
}
ofstream f("output.txt");
int main (){
int i, n;
float a, b, h;


cout<<"enter the lower, upper limit and no of iteration respectivly:"<<endl;
cin>>a>>b>>n;
float sum , sum1;
h=(b-a)/n;
float y0 , yn , ym , ym1;  //the value of function at a and b and any values
y0=simpson(a);
yn= simpson(b);
sum1=(y0+yn)/2;

for(i=0; i<n; i++){


sum +=simpson(a+i*h);


f<<i<<"\t"<<(sum1+sum)*h<<endl;



}
sum= (sum1+sum)*h;
cout<<"trapezoidal rule : "<<sum<<endl;


float sum2=0, sum4=0 ;

y0=simpson(a);
if (n % 2 != 0) {
        cout << "Error: Number of intervals (n) must be even for Simpson's 1/3 Rule!" << endl;
        return 1;
        }
yn=simpson(b);
h=(b-a)/n;
sum=y0+yn;
f<<"iteration\tintegration value: "<<endl;
for(i=1; i<n; i++){
if(i%2==0){
sum2 +=2*simpson(a+i*h);
}
else{
sum4 += 4*simpson(a+i*h);
}
cout<<"iteration: "<<i<<"integration value: "<<(h/3)*(sum+sum2+sum4)<<endl;
f<<i<<"\t"<<(h/3)*(sum+sum2+sum4)<<endl;
}
cout<<(h/3)*(sum+sum2+sum4)<<endl;

f.close();


cout<<"simpson 3/8 method<<endl"<<endl;
float ans;

y0=simpson(a);
if (n % 3 != 0) {
        cout << "Error: Number of intervals (n) must be even for Simpson's 1/3 Rule!" << endl;
        return 1;
        }
yn=simpson(b);
h=(b-a)/n;
sum=y0+yn;
f<<"iteration\tintegration value: "<<endl;
for(i=1; i<n; i++){
if(i%3==0){
sum2 +=2*simpson(a+i*h);
}
else{
sum4 += 3*simpson(a+i*h);
}
cout<<"iteration: "<<i<<"integration value: "<<(h*3/8)*(sum+sum2+sum4)<<endl;
f<<i<<"\t"<<(h/3)*(sum+sum2+sum4)<<endl;
}
cout<<"simpson38rule"<<(h*3/8)*(sum+sum2+sum4)<<endl;


return 0;
}
