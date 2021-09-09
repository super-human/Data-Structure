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

// Tarjan Implementation


void DFS(int u, std::vector<int> &disc, std::vector<int> &low, std::stack<int> &myStack, std::vector<bool> &presentInStack, std::vector<int> adj[]) {
    static int time = 0;
    disc[u] = low[u] = time;
    time++;
    myStack.push(u);
    presentInStack[u] = true;

    for(int v: adj[u]) {
        if(disc[v] == -1) { // if v is not visited
            DFS(v, disc, low, myStack, presentInStack, adj);
            low[u] = std::min(low[u], low[v]);
        }
        // Differentiate between back-edge and cross-edge
        else if(presentInStack[v]) {    // Back-edge case
            low[u] = std::min(low[u], disc[v]);
        }
    }

    // If u is head node of SCC
    if(low[u] == disc[u]) {
        std::cout<<"SCC is: ";
        while(myStack.top() != u) {
            std::cout<<myStack.top()<<" ";
            presentInStack[myStack.top()] = false;
            myStack.pop();
        }
        std::cout<<myStack.top()<<" ";
        presentInStack[myStack.top()] = false;
        myStack.pop();
    }

}

void findSCCs_Tarjan(std::vector<int> adj[], int V){
    std::vector<int> disc(V, -1), low(V, -1);
    std::vector<bool> presentInStack(V, false);
    std::stack<int> myStack;
    for(int i = 0; i<V; i++) {
        if(disc[i] == -1) {
            DFS(i, disc, low, myStack, presentInStack, adj);
        }
    }
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
    }
    findSCCs_Tarjan(adj, V);
    return 0;
}
