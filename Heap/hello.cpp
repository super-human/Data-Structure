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



int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int n,tcost = 0;
    std::cin>>n;
    std::vector<int> v(n);
    for(int i = 0; i<n; i++)
        std::cin>>v[i];
    std::priority_queue<int, std::vector<int>, std::greater<int>> minh;
    for (int i = 0; i < n; ++i)
        minh.push(v[i]);
    while(minh.size() > 1) {
        int a = minh.top();
        minh.pop();
        int b = minh.top();
        minh.pop();
        minh.push(a+b); // Not necessarily a+b will be at top
        tcost += a+b;   
    }
    std::cout<<tcost<<std::endl;
    return 0;
}