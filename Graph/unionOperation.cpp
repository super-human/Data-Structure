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

/*ll log(ll x) {
    return 32 - __builtin_clz(x) - 1;
}
*/

int find(int x, std::vector<int> parent) {
    if(parent[x] == x) {
        return x;
    }
    int y = find(parent[x],parent);
    return y;
}


void unionOp(int u, int v, std::vector<int> &parent) {
    std::cout<<std::endl;
    int x_rep = find(u, parent);
    int y_rep = find(v, parent);
    if(x_rep == y_rep) {
        return;
    }
    parent[y_rep] = x_rep;
}

int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    ll n,t;
    std::cin>>n>>t; // n -> no of vertices, m-> no. of edges
    std::vector<int> parent(n);
    for(int i = 0; i< n; i++){
        parent[i] = i;
    }
    int u,v;
    while(t--) {
        std::cin>>u>>v;
        unionOp(u, v, parent);
    }
    for(int i = 0; i<n; i++) {
        std::cout<<parent[i]<<" ";
    }
    return 0;
}



