//eular method

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
double df(double x, double y){
return x+y;
}               //dy/dx = x+y

int main(){
int i=1, n;
double h, yn, y0, x0, x1, xn;
cout << "enter the initial values of x0, xn,y0 and interval n: "<<endl;
cin >>x0>>xn>>y0>>n;

h=(xn-x0)/n;
do{


yn=y0+h*df(x0,y0);


y0=yn;
x0=x0+h;
cout<<"itr  "<<i<<"    the value of derivative: "<<y0<<endl;
i++;
}while(x0<xn);

cout<<"itr  "<<i<<"    the value of derivative: "<<y0<<endl;


return 0;
}
