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

// Kosaraju Implementation

void reverse(std::vector<int> adj[], std::vector<int> rev[], int V) {
    for(int i = 0; i< V; i++) {
        for(int j: adj[i]) {
            rev[j].pb(i);
        }
    }
}

void DFS1(std::vector<int> adj[], std::vector<bool> &visited, int s, std::stack<int> &st) {
    visited[s] = true;
    for(int i: adj[s]) {
        if(!visited[i]) {
            DFS1(adj, visited, i, st);
        }
    }
    st.push(s);
}

void DFS2(int i,std::vector<bool>& visited, std::vector<int> rev[])
{
    std::cout<<i<<" ";
    visited[i] = true;
    for(int j: rev[i])
        if(!visited[j])
            DFS2(j,visited, rev);
}

void kosaraju(std::vector<int> adj[], int V) {
    std::stack<int> st;
    std::vector<int> rev[V];
    std::vector<bool> visited(V, false);
    for(int i = 0; i<V; i++) {
        if(!visited[i]) {
            DFS1(adj, visited, i, st);
        }
    }
    reverse(adj, rev, V);
    for(int i = 0; i< V; i++) {
        visited[i] = false;
    }
    int count = 0;
    std::cout<<"Strongly COnnected Components are: \n";
    while(!st.empty()) {
        int s = st.top();
        st.pop();
        if(!visited[s]) {
            count++;
            DFS2(s, visited, rev);
        }
    }
    std::cout<<std::endl<<"count: "<<count;
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
    kosaraju(adj, V);
    return 0;
}
