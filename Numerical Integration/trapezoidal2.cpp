#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x){
return 1/(pow(x, 2) + 1);
}



int main(){

double a, b,itr;
cout<<"enter the lower limit , upper limit and no. of iteration: "<<endl;
cin>>a>>b>>itr;
double fun=atan(b)-atan(a);
double h, fa , fb , sum;
for (int n=1; n<itr; n++){
fa= f(a);
fb= f(b);
h=(b-a)/n;
sum= fa+fb;
for(int i=1; i<n; i++)
{
sum += 2*f(a+ i*h);

}
double error= fabs((sum*h/2)-fun)*100/fun;
cout <<"iteration "<<n<<"     root "<<sum*h/2<<"   error in % "<<error<<endl;
}

return 0;
}
