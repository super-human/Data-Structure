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

// Shortest Path in DAG using topological sort

void addEdge(std::vector<int> adj[], int edges, std::vector<std::vector<int>> &matrix) {
    int u, v, weight;
    for(int i = 0; i<edges; i++) {
        std::cin>>u>>v>>weight;
        adj[u].pb(v);
        matrix[u][v] = weight;
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


std::vector<int> DFS(std::vector<int> adj[], int n ) {
    std::vector<bool> visited(n, false);
    std::stack<int> recStack;
    for(int i = 0; i<n; i++) {
        if(!visited[i]) {
            DFSRec(adj, i, visited, recStack);
        }
    }
    std::vector<int> topoResult;
    while(!recStack.empty()) {
        topoResult.pb(recStack.top());
        recStack.pop();
    }
    return topoResult;
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    ll n,m, u, v;
    std::cin>>n>>m; // n -> no of vertices, m-> no. of edges
    std::vector<int> adj[n];
    std::vector<std::vector<int>> matrix(n, std::vector<int> (m, 0));
    addEdge(adj, m, matrix);
    std:: vector<int> r = DFS(adj, n);
    std::vector<int> distance(n);
    for(int i = 0; i<n; i++) {
        distance[i] = INT_MAX;
    }
    int source;
    std::cin>>source;
    distance[source] = 0;
    for(int i = source; i < n; i++) {
        for(int j: adj[i]) {
            if(distance[j] > distance[i] + matrix[i][j]) {
                distance[j] = distance[i] + matrix[i][j];
            }
        }
    }
    return 0;
}



