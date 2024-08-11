#include<iostream>
using namespace std;

float f(float x){
    return 4*x - (x*x)/2;
}

int main(){
    int i,j,m,n;
    float h,k,c,u[20][20],r;

    printf("Enter h,k,c,m,n:\n");
    scanf("%f %f %f %d %d",&h,&k,&c,&m,&n);

    for(j=0;j<=m;j++){
        u[0][j] = 0;
        u[n][j] = 0;
    }

    for(i=1;i<n;i++){
        u[i][0] = f(i*h);
    }
    r = (c*c)*k / (h*h);

    for(j=0;j<m;j++){
        for(i=1;i<n;i++){
            u[i][j+1] = r*(u[i-1][j]+u[i+1][j]) + (1-2*r)*u[i][j];
        }
    }
    printf("Solution of Heat Equation is--\n\n");
    for(j=0;j<=m;j++){
        for(i=0;i<=n;i++){
            printf("%.2f\t",u[i][j]);
        }
        printf("\n");
    }
    return 0;
}
