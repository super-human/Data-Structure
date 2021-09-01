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
struct Graph {
    int V, E;
    std::vector<std::pair<int, iPair> > edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int w, int u, int v) {
        edges.pb({w, {u,v}});
    }
    int kruskalMST();
};

struct DisjointSets {
    int *parent, *rank;
    int n;

    DisjointSets(int n) {
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i = 0; i< n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionOp(int src, int des) {
        if(rank[src] > rank[des]) {
            parent[des] = src;
        } else if(rank[src] < rank[des]) {
            parent[src] = des;
        } else {
            parent[src] = des;
            rank[des]++;
        }
    }

};

int Graph::kruskalMST() {
    int minCost = 0;
    std::sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    std::vector< std::pair<int, iPair> >::iterator it;
    for(it = edges.begin(); it!= edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds.find(u);
        int setV = ds.find(v);

        if(setU != setV) {
            minCost += it->first;
            ds.unionOp(setU, setV);
        }
    }
    return minCost;
}



int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, E, w, u, v;
    std::cin>>V>>E;
    Graph g(V,E);
    for(int i = 0; i< E; i++) {
        std::cin>>u>>v>>w;
        g.addEdge(w, u, v);
    }
    int cost = g.kruskalMST();
    std::cout<<cost<<std::endl;
    return 0;
}
