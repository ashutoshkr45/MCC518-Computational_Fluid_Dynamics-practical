#include<stdio.h>
float f( int i, float h)
{
    return(i*h*(1-i*h));
}
int main()

{
    int i,j,t,n;
    float r,k,h,x,u[11][11],a;
    printf("Enter the value of h : \t");
    scanf("%f",&h);
    printf("Enter the value of n : \t");
    scanf("%d",&n);
    printf("Enter the number of time levels t : \t");
    scanf("%d",&t);
    printf("Enter the value of k : \t");
    scanf("%f",&k);
    printf("Enter the value at u[0][t] :\n");
    for(i=0;i<t;i++)
    scanf("%f",&u[0][i]);
    printf("Enter the value at u[5][t] :\n");
    for(i=0;i<t;i++)
    scanf("%f",&u[5][i]);
    for(i=1;i<n;i++)
    {
        u[i][0]=f(i,h);
    }
    for(i=1;i<n;i++)
    u[i][1]=u[i][0]+0.2;
    
    for(j=1;j<t;j++)
    {
        for(i=1;i<n;i++)
        {
            u[i][j+1]=u[i+1][j]+u[i-1][j]-u[i][j-1];
        }
    }
    
    for(j=0;j<=t;j++)
    {
        printf("(i,%d)\t",j);
        for(i=0;i<=n;i++)
        printf("%.3f\t",u[i][j]);
        printf("\n");
    }
    return 0;
}
