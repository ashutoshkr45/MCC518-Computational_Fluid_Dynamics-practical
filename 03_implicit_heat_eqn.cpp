#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const float L = 10;
const float T = 0.01;
const float dx = 2;
const float dt = 0.01;
const float u0 = 100;
const float uL = 50;

int main(){
	int n = static_cast<int>(L/dx) + 1;
	int m = static_cast<int>(T/dt);
	float u[n],u_prev[n];
	
	for(int i=0; i<n; i++){
		u[i] = 0;
		u_prev[i] = 0;
	}
	u[0] = u0;
	u[n-1] = uL;
	u_prev[0] = u0;
	u_prev[n-1] = uL;
	
	float r = 0.020875;
	
	float a[n-2],b[n-2],c[n-2],d[n-2];
	
	for(int i=0; i<n-2; ++i){
		a[i] = -r;
		b[i] = 1 + 2*r;
		c[i] = -r;
	}
	for(int j=0; j<m; ++j){
		for(int i=1; i<n-1; ++i){
			d[i-1] = u_prev[i];
		}
		d[0] += r * u[0];
		d[n-3] += r * u[n-1];
		
		for(int i=1; i<n-2; ++i){
			float k = a[i] / b[i-1];
			b[i] -= k * c[i-1];
			d[i] -= k * d[i-1];
		}
		
		u[n-2] = d[n-3] / b[n-3];
		
		for(int i=n-3; i>=1; --i){
			u[i] = (d[i-1] - c[i-1]*u[i+1]) / b[i-1];
		}
		for(int i=1; i<n-1; ++i){
			u_prev[i] = u[i];
		}
	}
	cout<<"Temperature distribuition at t="<<T<<" seconds:\n";
	
	for(int i=0; i<n; ++i){
		cout<<"u("<<i*dx<<") = "<<setprecision(5) << u[i] << "'C\n";
	}
	return 0;
}
