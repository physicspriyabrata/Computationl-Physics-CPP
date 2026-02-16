#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int dice1(){
return rand()%6+1;
}
int dice2(){
return rand()%6+1;
}
int main(){

srand(time(0));
int x=0;
int array[x];
int arra[x];
for(int i=0; i<10; i++){
int roll1= dice1();
cout <<"roll1 "<<i+1<<"		" <<roll1<<endl;
int array[i]={roll1};
}
for(int i=0; i<10; i++){
int roll2= dice2();
cout <<"roll2 "<<i+1<<"		" <<roll2<<endl;
arra[i]={roll2};
}

cout <<array[x]<<"	"<<arra[x]<<endl;
return 0; 
}
