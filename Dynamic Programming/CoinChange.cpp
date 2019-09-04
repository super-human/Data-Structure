#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

int main() 
{
	int t; 
	std::cin>>t;
	while(t--)
	{
	    int m,n; 
	    std::cin>>m; 
	    int a[m];
	    for(int i=0;i<m;i++) 
	    	std::cin>>a[i];
	    std::cin>>n;
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++)
	        for(int j=0;j<=n;j++)
	        {
	            if(i==0 && j==0) 
	            	dp[i][j]=1;
	            else if(j==0) 
	            	dp[i][j]=1;
	            else if(i==0) 
	            	dp[i][j]=0;
	            else if(j>=a[i-1]) 
	            	dp[i][j]=dp[i-1][j]+dp[i][j-a[i-1]];
	            else 
	            	dp[i][j]=dp[i-1][j];
	        }
	    std::cout<<dp[m][n]<<std::endl;
	}
	return 0;
}
