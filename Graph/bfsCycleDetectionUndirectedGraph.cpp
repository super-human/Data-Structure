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
#define INF 0x3f3f3f3f

typedef std::pair<int, int> iPair;


void addEdge(std::vector<int> adj[], int edges) {
    int u, v;
    for(int i = 0; i<edges; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

// void printGraph(std::vector<int> adj[], int V) {
//     for(int i = 0; i<V; i++) {
//         std::cout<< i <<"=> ";
//         for(int x: adj[i]) {
//             std::cout<<x<<" ";
//         }
//         std::cout<<std::endl;
//     }
// }

bool BFS(std::vector<int> adj[], int s, std::vector<bool> &visited) {
    std::queue<iPair> q;
    visited[s] = true;
    q.push({s, -1});
    while(!q.empty()) {
        int x = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int u: adj[x]) {
            if(!visited[u]) {
                visited[u] = true;
                q.push({u, x});
            } else if(u != parent) {
                return true;
            }
        }
    }
    return false;
}


bool isCyclic(std::vector<int> adj[], int V) {
    std::vector<bool> visited(V, false);
    for(int i = 0; i< V; i++) {
        if(!visited[i] && BFS(adj, i, visited)) {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, E;
    std::cin>>V>>E;
    std::vector<int> adj[V];
    addEdge(adj, E);
    std::cout<<isCyclic(adj, V)<<std::endl;
    // printGraph(adj, V);
    return 0;
}
