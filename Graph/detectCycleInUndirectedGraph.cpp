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

// Detect Cycle in an Undirected Graph using DFS


void addEdge(std::vector<int> adj[], int edges) {
    int u, v;
    for(int i = 0; i<edges; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

bool isCyclic(std::vector<int> adj[], int s, std::vector<bool> &visited, int parent) {
    visited[s] = true;
    for(int i: adj[s]) {
        if(i!= parent) {    // To check if the node is not adjacent
            if(visited[i])
                return true;
            if(!visited[i] && isCyclic(adj, i, visited, s)) {
                return true;
            }
        }
    }
    return false;
}

bool DFS(std::vector<int> adj[], int n) {
    std::vector<bool> visited(n, false);
    for(int i = 0; i<n; i++) {
        if(!visited[i] && isCyclic(adj, i, visited, -1)) {
            return true;
        }
    }
    return false;
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
    std::cout<<DFS(adj, n)<<'\n';
    return 0;
}
