#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int p,q,x,y;
    cin>>p>>q>>x>>y;
    cout<<(p<=x&&x<=p+99&&q<=y&&y<=q+99?"Yes":"No");
}