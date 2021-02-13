#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<map>
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define N 100001

void reverse(std::queue<int> &q) {
    if(q.empty())
        return;
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}



int main()
{
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    std::queue<std::string> q;
    int n;
    std::cin>>n;
    q.push("5");
    q.push("6");
    for (int i = 0; i < n; ++i)
    {
        /* code */
        std::cout<<q.front()<<" ";
        q.push(q.front() + "5");
        q.push(q.front() + "6");
        q.pop();
    }
    
    return 0;
}

// 1800 0012 7219 39277
