#include<iostream>
#include<cmath>
#define pi 3.14159

using namespace std;

float f(float x){
	return sin(pi * x);
}

int main(){
	int i,j,m,n;
	float h,k,u[10][10],r,c;
	
	cout<<"Enter c,h,k,m,n:--"<<endl;
	cin>>c>>h>>k>>m>>n;
	
	for(j=0;j<=m;j++){
		u[0][j] = 0;
		u[n][j] = 0;
	}
	for(i=1;i<n;i++)
		u[i][0] = f(i*h);
		
	r = (c*c)*k/(h*h);
	
	for(j=0;j<m;j++){
		for(i=1;i<n;i++){
			u[i][j+1] = r*(u[i-1][j]+u[i+1][j]) + (1-2*r)*u[i][j];
		}
	}
	cout<<"Solution of Heat equation is--\n\n";
	
	for(j=0;j<=m;j++){
		for(i=0;i<=n;i++){
			printf("%.2f\t",u[i][j]);
		}
		cout<<endl;
	}
	return 0;
}
