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
   std::memset(K,0,sizeof(K));
   for (i = 1; i <= n; i++) 
   { 
       for (w = 1; w <= W; w++) 
       { 
           if (wt[i] <= w) 
                 K[i][w] = std::max(val[i] + K[i-1][w-wt[i]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
   for (int i = n, w = W; i>0; --i)
   {
   		if(K[i][w] != 0 && K[i][w] != K[i-1][w])
   		{
   			std::cout<<"We take item: "<<i<<'\n';
   			w = w-wt[i];
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
