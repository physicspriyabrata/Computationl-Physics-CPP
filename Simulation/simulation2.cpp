//calculate the valuse of pi using simulation
#include<iostream>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
int totalpoints;
cout<<"enter the total points: "<<endl;
cin >>totalpoints;
int circlepoints=0;
srand(time(0));
for(int i=0; i<totalpoints; i++){
double x= ((double )rand() / RAND_MAX)*2.0-1.0;
double y= ((double )rand() / RAND_MAX)*2.0-1.0;
if (x*x+ y*y<=1.0){
circlepoints ++;
}
}
double result=4.0*circlepoints/totalpoints;
cout<<"Estimated values of PI is : "<<result<<endl;
cout<<"Actual values of PI is : "<< M_PI<<endl;
return 0;
}
