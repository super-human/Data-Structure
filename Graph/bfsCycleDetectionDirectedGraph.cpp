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

// Detect cycle in Directed Graph using BFS Implementation


bool BFSCycleDetection(std::vector<int> adj[], std::vector<int> &indeg,int V) {
    std::queue<int> q;
    for(int i = 0; i<V; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for(int i: adj[u]) {
            indeg[i]--;
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
    }
    if(count == V)
        return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V,E,u,v;
    std::cin>>V>>E;
    std::vector<int> adj[V];
    std::vector<int> indeg(V,0);
    for(int i = 0; i < E; i++) {
        std::cin>>u>>v;
        adj[u].pb(v);
        indeg[v]++;
    }
    if(BFSCycleDetection(adj, indeg, V)) {
        std::cout<<"true"<<std::endl;
    } else {
        std::cout<<"false"<<std::endl;
    }
    return 0;
}
