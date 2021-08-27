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

// BFS for disconnected graph

void addEdge(std::vector<int> adj[], int edges) {
    int u, v;
    for(int i = 0; i<edges; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void BFS(std::vector<int> adj[], int vertices, int edges, int s, std::vector<bool> &visited) {
    visited[s] = true;
    std::queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        std::cout<<x<<" ";
        for(int i: adj[x]) {
            if(!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    ll n,m, u, v;
    std::cin>>n>>m; // n -> no of vertices, m-> no. of edges
    std::vector<int> adj[n];
    addEdge(adj, m);
    // int source;
    // std::cin>>source;
    std::vector<bool> visited(n, false);
    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            BFS(adj, n, m, i, visited);
        }
    }
    return 0;
}

