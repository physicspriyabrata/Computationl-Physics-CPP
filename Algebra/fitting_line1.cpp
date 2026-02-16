#include <iostream>
#include<cmath>
#include <fstream>
using namespace std;

int main () {
int n;
ifstream file("pointdata.txt");
double x[n], y[n], a, b;
x[n]=0;
y[n]=0;
cout <<"enter the no of observation: "<<endl;
cin>>n;
 for (int i = 0; i < n; i++) {
        file >> x[i] >> y[i];
    }
double sumx, sumy, sumxy , sumxx;
sumx=sumy=sumxy=sumxx=0;
for(int i=0; i<n ; i++){
sumx=sumx+x[i];
sumy=sumy + y[i];
sumxy= sumxy + x[i]*y[i];
sumxx= sumxx + x[i]*x[i];
}
double am[2][3];
am[0][0]=n;
am[0][1]=sumx;
am[0][2]=sumy;
am[1][0]=sumx;
am[1][1]=sumxx;
am[1][2]=sumxy;

float ratio=am[1][0]/am[0][0];
for (int i=0; i<3; i++){
am[1][i]=am[1][i]-ratio*am[0][i];
b=am[1][2]/am[1][1];
a=(am[0][2]-am [0][1]*b)/am[0][0];
}
double Y, X;
cout<<"the line equation is :  "<<"y = "<<a<<"+ "<<b<<"x";

file.close();


return 0;
}
