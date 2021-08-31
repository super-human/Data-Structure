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

// Prims Code Implementation
void addEdge(std::vector<iPair> adj[], int u, int v, int weight) {
    adj[u].pb(std::make_pair(v,weight));
    adj[v].pb(std::make_pair(u,weight));
}

void primMST(std::vector<iPair> adj[], int V) {
    std::vector<int> parent(V, -1);
    std::vector<bool> setMST(V, false);
    std::vector<int> key(V,INF);

    int src = 0;
    key[src] = 0;
    std::priority_queue<iPair, std::vector<iPair> , std::greater<iPair> > pq;
    pq.push(std::make_pair(0, src));

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
            if(!setMST[v] && key[v] > weight) {
                key[v] = weight;
                parent[v] = u;
                pq.push(std::make_pair(key[v], v));
            }
        }
    }
    for(int i = 1; i<V; i++) {
        std::cout<<parent[i]<<" - "<<i<<std::endl;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, noOfEdgeToBeAdded, u, v, weight;
    std::cin>>V>>noOfEdgeToBeAdded;
    std::vector<iPair> adj[V];
    while(noOfEdgeToBeAdded--) {
        std::cin>>u>>v>>weight;
        addEdge(adj, u, v, weight);
    }
    primMST(adj, V);
    return 0;
}
