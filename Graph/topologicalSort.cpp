#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
#include <unordered_set>
#include<queue>
#include <deque>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#include<numeric>
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define N 100001

/*ll log(ll x) {
    return 32 - __builtin_clz(x) - 1;
}
*/

// No Topological sort in cyclic graph

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    ll n,m, u, v;
    std::cin>>n>>m; // n -> no of vertices, m-> no. of edges
    std::vector<int> adj[n];
    std::vector<int> indeg(n,0);
    for(int i = 0; i<m; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        indeg[v]++;
    }
    std::queue<int> q;
    for(int i = 0; i< n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        std::cout<<x<<" ";
        for(int i: adj[x]) {
            indeg[i]--;
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
    }
    return 0;
}

