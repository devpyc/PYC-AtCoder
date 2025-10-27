#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        if (i<=m) {
            cout<<"OK\n";
        }else {
            cout<<"Too Many Requests\n";
        }
    }
}