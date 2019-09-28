#include<bits/stdc++.h>

//Worst = Best = Average = O(nlogn)
// Space = O(n) Auxillary Space

void merge(int arr[], int l, int mid, int h)
{
    int i,j,k;
    i=l,j=mid+1,k = l;
    int B[h+1];
    while(i<=mid && j <= h)
    {
        if(arr[i] < arr[j])
        {
            B[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            B[k] = arr[j];
            k++;
            j++;
        }
    }
    for(;i<=mid; i++)
    {
        B[k] = arr[i];
        k++;
    }
    for(;j<=h; j++)
    {
        B[k] = arr[j];
        k++;
    }
    for(i = l; i<=h; i++)
        arr[i] = B[i];
}

void mergesort(int arr[], int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
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
    mergesort(arr,0,n-1);
    for(int i = 0; i<n; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<'\n';
return 0;

}
