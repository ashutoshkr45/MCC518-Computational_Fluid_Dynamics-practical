#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int n, i;
	float h, k, C, q, A, B, Ua, Ub, L;
	float a[10], b[10], c[10], d[10], alpha[10], beta[10], x[10];
	cout<<"Enter the temperature at ends:\n";
	cin>>Ua >> Ub;
	cout<<"Enter Thermal conductivity, heat generation(in kW), Area, Length of rod & No. of nodal points:\n";
	cin>>k>>q>>A>>L>>n;
	
	h = L / n;
	B = (k * A) / h;
	C = 1000 * q * A * h;
	
	for(i=2; i<=n; i++)
		a[i]  = -B;
	for(i=1; i<n; i++)
		c[i] = -B;
	for(i=1; i<=n; i++){
		if(i==1 || i==n)
			b[i] = 3 * B;
		else
			b[i] = 2 * B;
	}
	for(i=2; i<n; i++)
		d[i] = C;
	d[1] = 2 * B * Ua + C;
	d[n] = 2 * B * Ub + C;
	
	
	alpha[1] = b[1];
	beta[1] = d[1] / b[1];
	
	for(i=2; i<=n; i++){
		alpha[i] = b[i] - (a[i] * c[i-1] / alpha[i-1]);
		beta[i] = (d[i] - a[i] * beta[i-1])/ alpha[i];
	}
	x[n] = beta[n];
	for(i=n-1; i>=1; i--)
		x[i] = beta[i] - (c[i] * x[i+1]) / alpha[i];
	
	cout<<endl;
	cout<<"The required solution is:\n";
	for(i=1; i<=n; i++)
		cout<<"U"<<i<<" = "<<x[i]<<endl;
		
	return 0;
}
