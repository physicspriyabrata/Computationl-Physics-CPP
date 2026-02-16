#include<iostream>
using namespace std;
int main(){

int n, m;

cout<<" enter the size of the matrix "<<endl;
cin>>n>>m;
int x[n][m];
cout<<"enter the elements of the matrix:  "<<endl;

for (int i=0; i<n; i++){
for ( int j=0; j<m; j++){
cin>>x[i][j];

}
}
cout<<" the matrix is "<<endl;
for (int i=0; i<n; i++){
for ( int j=0; j<m; j++){

cout<<x[i][j]<<"	";
}
cout<<"		"<<endl;
}

return 0 ; 
}
