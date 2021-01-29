#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
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

int kSmallest(std::vector<int> v, int k)
{
    std::priority_queue<int> maxh;
    for(int i = 0; i<v.size() ;i++) {
        maxh.push(v[i]);
        if(maxh.size() > k)
            maxh.pop();
    }
    return maxh.top();
}


int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int n,k1,k2,sum = 0;
    std::cin>>n>>k1>>k2;
    std::vector<int> v(n);
    for(int i = 0; i<n; i++)
        std::cin>>v[i];
    std::priority_queue<int> maxh;
    for(int i = 0; i<n ;i++) {
        maxh.push(v[i]);
        if(maxh.size() > k1)
            maxh.pop();
    }
    int k1Smallest = kSmallest(v, k1);
    int k2Smallest = kSmallest(v, k2);
    for(int i = 0; i<n ;i++)
        if(v[i] > k1Smallest && v[i] < k2Smallest)
            sum += v[i];
    std::cout<<sum<<std::endl;
    return 0;
}
