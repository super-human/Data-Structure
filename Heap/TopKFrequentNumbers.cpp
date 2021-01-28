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
    int testcases,n,k,x;
    std::cin>>testcases;
    while(testcases--) {
        std::cin>>n>>k;
        std::vector<int> v(n);
        std::vector<int> result;
        std::unordered_map<int, int> mp;
        for(int i = 0; i<n; i++)
            std::cin>>v[i];
        for(int i = 0; i<n; i++)
            mp[v[i]]++;
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>minh;
        for(auto i:mp) {
            minh.push({i.second, i.first});
            if(minh.size() > k)
                minh.pop();
        }
        while(!minh.empty()){
            result.push_back(minh.top().second);
            minh.pop();
        }
        std::reverse(result.begin(), result.end());
        for(auto i = result.begin(); i != result.end(); i++)
            std::cout<<*i<<" ";
        std::cout<<std::endl; 
    }

    return 0;
}
