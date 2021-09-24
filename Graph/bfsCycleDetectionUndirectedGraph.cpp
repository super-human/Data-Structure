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

// Detect cycle using BFS Implementation


bool BFSCycle(std::vector<int> adj[], std::vector<bool> &visited,int s) {
    visited[s] = true;
    std::queue<iPair> q;
    q.push({s, -1});
    while(!q.empty()) {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int v: adj[u]) {
            if(visited[v] && u != parent) {    // If its not an adjacent node but visited then there is a cycle
                return true;
            } else {
                q.push({v, u});
            }
        }
    }
    return false;
}

bool BFS(std::vector<int> adj[], int V) {
    std::vector<bool> visited(V, false);
    for(int i = 0; i<V; i++) {
        if(!visited[i]) {
            if(BFSCycle(adj, visited, i)) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, E, u, v;
    std::cin>>V>>E;
    std::vector<int> adj[V];
    for(int i = 0; i<E; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(BFS(adj, V)) {
        std::cout<<"Cycle is Present"<<std::endl;
    } else {
        std::cout<<"Cycle not Present"<<std::endl;
    }
    return 0;
}
