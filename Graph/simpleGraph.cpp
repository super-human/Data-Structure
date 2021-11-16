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

void printGraph(std::vector<int> adj[], int V) {
    for(int i = 0; i<V; i++) {
        for(int x: adj[i]) {
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, E;
    std::cin>>V>>E;
    std::vector<int> adj[V];
    addEdge(adj, E);
    printGraph(adj, V);
    return 0;
}

