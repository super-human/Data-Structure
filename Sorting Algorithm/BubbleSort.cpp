#include<bits/stdc++.h>

#include<bits/stdc++.h>

//Improvised version of Bubble Sort
// time complexity for best case O(n) and worst case is still the same O(n^2)

void bubblesort(int arr[], int n)
{
    int flag = 1;
    for(int i = n-1 ; i>=0 && flag; i--)
    {
        flag = 0;
        for(int j = 0; j<i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = 1;
                std::swap(arr[j],arr[j+1]);
            }
        }
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
    bubblesort(arr,n);

return 0;

}

/*
void bubblesort(int arr[], int n)
{
    for(int i = n-1 ; i>=0; i--)
    {
        for(int j = 0; j<i; j++)
            if(arr[j] > arr[j+1])
                std::swap(arr[j],arr[j+1]);
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
    bubblesort(arr,n);

return 0;

}
*/
