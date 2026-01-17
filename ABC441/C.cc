#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    long long n,k,x;
    cin>>n>>k>>x;

    long long arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<long long>());

    vector<long long>sum(n+1);
    for (int i=0; i<n; i++) {
        sum[i+1]=sum[i]+arr[i];
    }

    for (int i=n-k+1; i<=n; i++) {
        long long res=sum[i]-sum[n-k];
        if (res>=x) {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
}