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

// Floyd Warshall Implementation

void FloydWarshall(std::vector<std::vector<int>> &graph, int V) {
    int dis[V][V];
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++) {
            dis[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k<V; k++) {
        for(int i = 0; i< V; i++) {
            for(int j = 0; j< V; j++) {
                if(dis[i][k] == INF || dis[k][j] == INF)
                    continue;
                else if(dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    //Check for negative edge weight cycle
    for(int i=0;i<V;++i)
        if(dis[i][i] < 0)
        {
            std::cout<<"Negative edge weight cycle is present\n";
            return;
        }

    //Print Shortest Path Graph
    //(Values printed as INF defines there is no path)
    for(int i=1;i<V;++i)
    {
        for(int j=0;j<V;++j)
            std::cout<<i<<" to "<<j<<" distance is "<<dis[i][j]<<"\n";
        std::cout<<"=================================\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    int V, E, w, u, v, distance;
    std::cin>>V>>E;
    std::vector<std::vector<int>> graph(V, std::vector<int>(V, INF));
    for(int i = 0; i<E; i++) {
        std::cin>>u>>v>>w;
        if(u == v) {
            graph[u][v] = 0;
            continue;
        }
        graph[u][v] = w;
    }
    FloydWarshall(graph, V);
    return 0;
}
