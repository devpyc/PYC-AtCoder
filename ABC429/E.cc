#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    string s;
    cin >> s;

    vector<int> d1(n + 1, INF), d2(n + 1, INF);
    vector<int> s1(n + 1, -1), s2(n + 1, -1);

    struct State {
        int u, d, s;
    };
    queue<State> q;

    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'S') {
            d1[i] = 0;
            s1[i] = i;
            q.push({i, 0, i});
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int u = cur.u, dist = cur.d, ss = cur.s;
        for (int v : graph[u]) {
            int idx = dist + 1;
            bool check = false;
            if (s1[v] == ss) {
                if (idx < d1[v]) {
                    d1[v] = idx;
                    check = true;
                }
            } else if (s2[v] == ss) {
                if (idx < d2[v]) {
                    d2[v] = idx;
                    check = true;
                }
            } else {
                if (idx < d1[v]) {
                    d2[v] = d1[v]; s2[v] = s1[v];
                    d1[v] = idx;  s1[v] = ss;
                    check = true;
                } else if (idx < d2[v]) {
                    d2[v] = idx;  s2[v] = ss;
                    check = true;
                }
            }
            if (check) q.push({v, idx, ss});
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'D') {
            long long ans = (long long)d1[i] + (long long)d2[i];
            cout << ans << "\n";
        }
    }
}