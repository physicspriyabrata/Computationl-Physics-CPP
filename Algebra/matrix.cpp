#include<iostream>
using namespace std; 
int main() {
int n,m;
cout<<"enter the no. of rows and columns: "<<endl;
cin>>n>>m;
double mat[n][m];

for(int i=0; i<n; i++){
	for (int j=0; j<m; j++){
	cin >> mat[i][j];
	}}
// output of the matrix display
for (int i=0; i<n; i++){
	for (int j=0; j<m; j++){
	cout<<mat[i][j]<<"     ";
	}
	cout<<endl;
	}




return 0; 
}
