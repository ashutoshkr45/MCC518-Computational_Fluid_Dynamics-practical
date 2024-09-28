#include <iostream>
using namespace std;

int main(){
    int i,j,n,iter,k;
    float u[10][10], u_prev[10][10];
    cout<<"Enter no. of mesh points, no. of iterations : ";
    cin>>n>>iter;
    
    for(i=0; i<=n; i++){
        cout<<"Enter u("<<i<<",0): ";
        cin>>u[i][0];
    }
    for(i=0; i<=n; i++){
        cout<<"Enter u("<<i<<","<<n<<"): ";
        cin>>u[i][n];
    }
    for(j=1; j<n; j++){
        cout<<"Enter u(0,"<<j<<"): ";
        cin>>u[0][j];
    }
    for(j=1; j<n; j++){
        cout<<"Enter u("<<n<<","<<j<<"): ";
        cin>>u[n][j];
    }

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            u[i][j] = 0;
        }
    }

    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            u_prev[i][j] = u[i][j];

    for(k=1;k<=iter;k++){
    	if(k==1){
    		u[1][2] = (u[0][3] + u[2][3] + u[0][1] + u[2][1]) / 4;
    		
            for(i=1;i<n;i++){
                for(j=n-1;j>0;j--){
            	    if(k==1 && i==1 && j==2)
            		    continue;
            	    else
                	    u[i][j] = (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1])/4;
                }
            }
        }
        else{
            for(i=1;i<n;i++)
                for(j=n-1;j>0;j--)
                	u[i][j] = (u_prev[i-1][j] + u_prev[i+1][j] + u_prev[i][j-1] + u_prev[i][j+1])/4;
        }
        for (i = 1; i < n; i++) 
            for (j = 1; j < n; j++) 
                u_prev[i][j] = u[i][j];

        printf("\n\nIteration - %d: \nThe Solution of Laplace Equation is-\n",k);
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
