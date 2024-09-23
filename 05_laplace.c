#include <stdio.h>
# include<math.h>

int main(){
    int i,j,n,itera,k;
    float u[10][10];
    printf("Enter the number of sub squares in a row or column: ");
    scanf("%d",&n);
    printf("Enter the number of iterations: ");
    scanf("%d",&itera);
    printf("Enter the boundary values u(i,0):-\n");
    for(i = 0;i<n+1;i++)
    {
        scanf("%f",&u[i][0]);
    }
    printf("Enter the boundary values u(i,%d):-\n",n);
    for(i=0;i<n+1;i++)
    {
        scanf("%f",&u[i][n]);
    }
    printf("Enter the boundary values u(0,j):-\n");
    for(j=0;j<n+1;j++)
    {
        scanf("%f",&u[0][j]);
    }
    printf("Enter the boundary values u(%d,j):-\n",n);
    for(j=0;j<n+1;j++)
    {
        scanf("%f",&u[n][j]);
    }
    for(i = 1; i<n; i++)
    {
        for(j=1;j<n;j++)
        {
            u[i][j] = 0;
        }
    }
    for(k=1;k<=itera;k++)
    {
        for(i=1;i<n;i++)
        {
            for(j=1;j<n;j++)
            {
                u[i][j] = (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1])/4;
            }
        }
        printf("The Solution of Laplace Equation is-\n");
        for(j=1;j<n;j++)
        {
            for(i=1;i<n;i++)
            {
                printf("\nu(%d,%d)=%f\t",i,j,u[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}