#include<bits/stdc++.h>

// Worst case = Average Case = Worst Case = O(n^2)
//Space worst case O(1)

void selectionsort(int arr[], int n)
{
    int min,index=0;
    for(int i = 0 ; i<n ; i++)
    {
        min = arr[i];
        for(int j = i+1; j<n; j++)
        {
            if(min>arr[j])
            {
                min = arr[j];
                index = j;            }
        }
        std::swap(arr[i],arr[index]);
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
    selectionsort(arr,n);

return 0;

}
