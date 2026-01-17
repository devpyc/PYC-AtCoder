#include <bits/stdc++.h>
using namespace std;

int n,m,l;
long long s,t;

vector<vector<pair<int,int>>>graph;
vector<char>check;

void dfs(int v, int d, long long c) {
    if (c>t) return;
    if (d==l) {
        if (s<=c&&c<=t) {
            check[v]=1;
        }
        return;
    }

    for (auto [i,j]:graph[v]) {
        dfs(i,d+1,c+j);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>m>>l>>s>>t;

    graph.resize(n+1);
    while (m--) {
        int u,v,c;
        cin>>u>>v>>c;
        graph[u].push_back({v,c});
    }

    check.assign(n+1,0);

    dfs(1,0,0);

    bool chk=true;
    for (int i=1; i<=n; i++) {
        if (check[i]) {
            if (!chk) cout<<" ";
            cout<<i;
            chk=false;
        }
    }
}