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
    int n,k,x;
    std::cin>>n>>k;
    std::vector<std::vector<int>> v;
    for(int i = 0; i<n; i++){
        std::vector<int> col;
        for (int j = 0; j < 2; ++j){
            std::cin>>x;
            col.pb(x);
        }
        v.pb(col);
        col.clear();
    }
    std::priority_queue<std::pair<int, std::pair<int, int>>> maxh;
    for(int i = 0; i<n; i++){
        maxh.push({v[i][0] * v[i][0] + v[i][1] * v[i][1], {v[i][0], v[i][1]}});
        if(maxh.size() > k)
            maxh.pop();
    }
    while(maxh.size() > 0) {
        std::pair<int, int> p = maxh.top().second;
        std::cout<<p.first<<" "<<p.second<<std::endl;
        maxh.pop();
    }

    return 0;
}