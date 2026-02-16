#include<iostream> 
#include<cmath>
#include<fstream>
using namespace std;
double Lag_inter(double x[], double y[], double x_value, int n){

double sum=0;
for(int i=0; i<n; i++){
double term=1;
	for(int j=0; j<n; j++){
	if(i!=j)
	term=term*((x_value-x[j])/(x[i]-x[j]));
	
	
	}
	sum=sum+term*y[i];
}
return sum;

}


int main (){
ofstream file("priya.txt");
ifstream data("interpolation_data.txt");
int n;
cout<<"enter the number of data points"<<endl;
cin>>n;

double x[n], y[n], x_value;
//cout<<"enter the point of x:"<<endl;
//for (int i=0; i<n; i++){
//cin>>x[i];
//}
//cout<<"enter the points of y;"<<endl;
//for (int i=0;i<n; i++){

//cin>>y[i];
//}


        data >> x[n] >> y[n];
    
cout<<"enter the value of x for interpolation:"<<endl;
cin>>x_value;
double result=Lag_inter(x, y, x_value,n);
cout<<"the interpolation value at x is = "<<result<<endl;
file<<result;
file.close();
data.close();




return 0 ;
}
