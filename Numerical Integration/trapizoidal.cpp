#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x)
{
return 1/(pow(x,2)+1);
}






double trap(double a, double b, double n)
{
double sum1 = (f(a)+f(b))*0.5;
double h = (b-a)/n;
for(int i=1;i<n;i++)
{
double x = a+(i*h);
sum1 += f(x);


}

return sum1*h;
}
int main()
{
double a,b,n;
a=0;
b=6;
n=100;
double fun = atan(b)-atan(a);
for(int i=1;i<n;i++)
{
cout<<"iteration"<<i<<"\t"<<"integ"<<trap(a,b,i)<<"\t"<<"error"<<(fabs(trap(a,b,i)-fun)/fun)*100<<endl;

}
cout<<trap(a,b,n)<<endl;
cout<<trap(a,b,1)<<endl;
return 0;
}

