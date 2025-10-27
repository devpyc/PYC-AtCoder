#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int>cnt(n+1);
    for (int i:arr) {
        cnt[i]++;
    }

    long long ans=0;
    for (int i=1; i<=n; i++) {
        long long res=cnt[i];
        if (res>=2) ans+=(res*(res-1)/2)*(n-res);
    }
    cout<<ans;
}