//Jacobi Iteration Method

#include<iostream>
#include<cmath>

using namespace std;

//define function
double f1(double x,double y,double z){
return ((17-y+2*z)/20);
}
double f2(double x,double y,double z){
return ((-18-3*x+z)/20);
}
double f3(double x,double y,double z){
return ((25-2*x+3*y)/20);
}

int main(){
int i=0, n;    //for iteration
double x0, x1, y0, y1, z0, z1;   //initial values
cout<<"enter the initial values of x0, y0 and z0 respectively:  "<<endl;
cin>>x0>>y0>>z0;
double e;        // tolerance
cout<<"enter the tolerance: "<<endl;
cin>>e;
double e1, e2, e3;
do{

x1=f1(x0, y0, z0);
y1=f2(x0, y0, z0);
z1=f3(x0, y0, z0);

e1=fabs(x0-x1);
e2=fabs(y0-y1);
e3=fabs(z0-z1);

x0=x1;
y0=y1;
z0=z1;


cout<<"iteration  "<< i<< "	value of x: "<<x0<< "	values of y: "<<y0<< "      values of z: "<<z0<<endl;
i++;
}while(e1>e , e2>e , e3>e);
cout<<"iteration  "<< i<< "	value of x: "<<x0<< "	values of y: "<<y0<< "      values of z: "<<z0<<endl;


return 0;
}
