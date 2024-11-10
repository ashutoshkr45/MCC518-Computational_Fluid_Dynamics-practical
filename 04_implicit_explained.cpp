#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

float f(float x){
    float val = x * (8 - x) / 2;
    return val;
}

int main(){
    int i,j,m,n;
    float C,h,k,r,u[10],u_prev[10];
    float a[10],b[10],c[10],d[10],alpha[10],beta[10],x[10];
    cout<<"Enter c,h,k,m,n:\n";
    cin>>C>>h>>k>>m>>n;
    
    r = k * (C * C) / (h * h);
    
    for(i=0;i<=n;i++){
        u[i] = f(i*h);
        u_prev[i] = u[i];
    }
    for(i=1;i<=n;i++){
        if(i==n)
            a[i] = 0;
        else
            a[i] = -r;
    }
        
    for(i=0;i<n;i++){
        if(i==0)
            c[i] = 0;
        else
            c[i] = -r;
    }
        
    for(i=0;i<=n;i++){
        b[i] = 1 + 2*r;
        if(i==0 || i==n)
            b[i] = 1;
    }
        
    cout<<fixed<<setprecision(2);
    for(i=0;i<=n;i++)
        cout<<u[i]<<"\t";
    cout<<endl;
    
    for(j=1; j<=m; j++){
        for(i=1;i<n;i++)
            d[i] = u_prev[i];
    
        d[0] = u[0];
        d[n] = u[n];
        
        alpha[0] = b[0];
	    beta[0] = d[0] / b[0];
	
	    for(i=1; i<=n; i++){
		    alpha[i] = b[i] - (a[i] * c[i-1] / alpha[i-1]);
		    beta[i] = (d[i] - a[i] * beta[i-1])/ alpha[i];
	    }
	    
	    x[n] = beta[n];
	    for(i=n-1; i>=0; i--)
		    x[i] = beta[i] - (c[i] * x[i+1]) / alpha[i];
		    
		for(i=0;i<=n;i++)
		    u[i] = x[i];
		for(i=1;i<n;i++){
		    u_prev[i] = u[i];
		}
		for(i=0;i<=n;i++)
            cout<<u[i]<<"\t";
        cout<<endl;
    }
    return 0;
}
