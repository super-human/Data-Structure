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

// Topological Sort using DFS

void addEdge(std::vector<int> adj[], int edges) {
    int u, v;
    for(int i = 0; i<edges; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
    }
}

void DFSRec(std::vector<int> adj[], int s, std::vector<bool> &visited, std::stack<int> &recStack) {
    visited[s] = true;
    for(int i: adj[s]) {
        if(!visited[i]) {
            DFSRec(adj, i, visited, recStack);
        }
    }
    recStack.push(s);
}


void DFS(std::vector<int> adj[], int n ) {
    std::vector<bool> visited(n, false);
    std::stack<int> recStack;
    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            DFSRec(adj, i, visited, recStack);
        }
    }
    while(!recStack.empty()) {
        std::cout<<recStack.top()<<" ";
        recStack.pop();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    ll n,m, u, v;
    std::cin>>n>>m; // n -> no of vertices, m-> no. of edges
    std::vector<int> adj[n];
    addEdge(adj, m);
    DFS(adj, n);
    return 0;
}
