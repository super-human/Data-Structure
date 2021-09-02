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

/*ll log(ll x) {
    return 32 - __builtin_clz(x) - 1;
}
*/

// Dijkstra Implementation

void addEdge(std::vector<iPair> adj[], int weight, int u, int v) {
    adj[u].pb({v, weight});
    adj[v].pb({u, weight});
}

void dijkstra(std::vector<iPair> adj[], int V) {
    int src = 0;
    std::vector<int> dis(V, INF);
    std::vector<bool> setMST(V, false);
    std::vector<int> parent(V);
    for(int i = 0; i< V; i++) {
        parent[i] = i;
    }
    dis[src] = 0;
    std::priority_queue<iPair, std::vector<iPair> , std::greater<iPair> > pq;
    pq.push(std::make_pair(0,src));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(setMST[u]){
            continue;
        }
        setMST[u] = true;
        for(auto i: adj[u]) {
            int v = i.first;
            int weight = i.second;
            if(!setMST[v] && dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                pq.push(std::make_pair(dis[v], v));
                parent[v] = u;
            }
        }
    }
    for(int i = 0; i< V; i++) {
        // std::cout<<i<<" -> "<< dis[i]<<std::endl;
        std::cout<<" U -> V: "<<parent[i]<<" -> "<<i<<" wt = "<<dis[i]<<std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, E, w, u, v;
    std::cin>>V>>E;
    std::vector<iPair> adj[V];
    for(int i = 0; i< E; i++) {
        std::cin>>u>>v>>w;
        addEdge(adj, w, u, v);
    }
    dijkstra(adj, V);
    return 0;
}
