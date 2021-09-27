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

// Shortest Path in Undirected Graph with no weight given(O(V+E))


void shortestPath(std::vector<int> adj[], std::vector<int> &distance,int V) {
    std::queue<int> q;
    distance[0] = 0;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i : adj[u]) {
            if(distance[i] > distance[u] + 1) {
                distance[i] = distance[u] + 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V,E,u,v;
    std::cin>>V>>E;
    std::vector<int> adj[V];
    for(int i = 0; i < E; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    std::vector<int> distance(V, INT_MAX);
    shortestPath(adj, distance, V);
    for(int i = 0; i< V; i++) {
        std::cout<<i<<"->"<<distance[i]<<std::endl;
    }
    return 0;
}
