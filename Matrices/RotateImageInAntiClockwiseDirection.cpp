#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define N 100001


int main()
{
    ll n;
    std::cin>>n;
    int arr[n][n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            std::cin>>arr[i][j];
    
    // reverse each row
    for(int row = 0; row<n; row++)
    {
        int start_col = 0;
        int end_col = n-1;
        while(start_col < end_col)
        {
            std::swap(arr[row][start_col],  arr[row][end_col]);
            start_col++;
            end_col--;
        }
    }
    for (int i = 0; i < n; i++)     //Transpose of a matrix
        for (int j = 0; j < i; j++) 
                std::swap(arr[i][j], arr[j][i]);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
            std::cout<<arr[i][j]<<" ";
        std::cout<<'\n';
    }
        

    return 0;
}
