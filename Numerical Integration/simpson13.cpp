#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
float simpson( float x){

return 1/(x*x+1);
}
ofstream f("output.txt");
int main (){
int i, n;
float a, b, h;
float y0, yn, sum, sum2=0, sum4=0 ,ans;
cout<<"enter the lower, upper limit and no of iteration respectivly:"<<endl;
cin>>a>>b>>n;
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
return 0;
}
