#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = std::max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{ 
	int numOfItems,Weight;
	std::cin>>numOfItems>>Weight;
	int val[numOfItems],wt[numOfItems];
	for (int i = 0; i < numOfItems; ++i)
	{
		std::cin>>val[i];
		std::cin>>wt[i];
	}
    std::cout<<knapSack(Weight, wt, val, numOfItems)<<'\n';
    return 0; 
} 
