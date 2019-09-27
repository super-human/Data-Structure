#include<bits/stdc++.h>

// Best Case = O(n) Avg Case = Worst case = O(n^2)

void insertionsort(int arr[], int n)
{
    int value,j;
    for(int i = 1; i<n; i++)
    {
        value = arr[i];
        j = i;
        while(arr[j-1]>value && j > 0)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
    }
    //printing the array
    for(int i = 0; i<n; i++)
        std::cout<<arr[i]<<" ";
}

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n;
    std::cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        std::cin>>arr[i];
    insertionsort(arr,n);

return 0;

}
