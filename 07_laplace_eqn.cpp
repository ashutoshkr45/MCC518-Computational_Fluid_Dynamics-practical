#include <iostream>
using namespace std;

int main(){
    int i,j,n,iter,k;
    float u[10][10];
    cout<<"Enter no. of mesh points, no. of iterations : ";
    cin>>n>>iter;
    
    cout<<"Enter the boundary values u(i,0):-\n";
    for(i=0; i<=n; i++)
    {
        cin>>u[i][0];
    }
    cout<<"Enter the boundary values u(i,"<<n<<"):-\n";
    for(i=0;i<n+1;i++)
    {
        cin>>u[i][n];
    }
    cout<<"Enter the boundary values u(0,j):-\n";
    for(j=0;j<n+1;j++)
    {
        cin>>u[0][j];
    }
    cout<<"Enter the boundary values u("<<n<<",j) except corners:-\n";
    for(j=0;j<n+1;j++)
    {
        cin>>u[n][j];
    }
    for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            u[i][j] = 0;
        }
    }
    for(k=1;k<=iter;k++)
    {
    	if(k==1)
    		u[1][2] = (u[0][3] + u[2][3] + u[0][1] + u[2][1]) / 4;
    		
        for(i=1;i<n;i++)
        {
            for(j=n-1;j>0;j--)
            {
            	if(i==1 && j==2)
            		continue;
            	else
                	u[i][j] = (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1])/4;
            }
        }
        printf("\n\nThe Solution of Laplace Equation is-\n");
        for(j=n;j>=0;j--)
        {
            for(i=0;i<=n;i++)
            {
                cout<<u[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}
