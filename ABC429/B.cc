#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n,m;
    cin>>n>>m;

    int arr[n];
    int sum=0;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        sum+=arr[i];
    }
    bool check=false;
    for (int i=0; i<n; i++) {
        if ((sum-arr[i])==m) {
            check=true;
        }
    }
    cout<<(check?"Yes":"No");
}