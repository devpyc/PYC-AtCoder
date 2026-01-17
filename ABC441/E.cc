#include <bits/stdc++.h>
using namespace std;

vector<long long>p,tmp;
long long ans=0;

void mergeSort(int l, int r) {
    if (r-l<=1) return;

    int m=(l+r)/2;
    mergeSort(l,m);
    mergeSort(m,r);

    int i=l,j=m,k=l;

    while (i<m&&j<r) {
        if (p[i]<p[j]) {
            ans+=(r-j);
            tmp[k++]=p[i++];
        }else {
            tmp[k++]=p[j++];
        }
    }

    while (i<m) {
        tmp[k++]=p[i++];
    }

    while (j<r) {
        tmp[k++]=p[j++];
    }

    for (int t=l; t<r; t++) {
        p[t]=tmp[t];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    string s;
    cin>>n>>s;

    p.resize(n+1);
    tmp.resize(n+1);

    p[0]=0;

    for (int i=0; i<n; i++) {
        p[i+1]=p[i];
        if (s[i]=='A') p[i+1]++;
        else if (s[i]=='B') p[i+1]--;
    }

    mergeSort(0,n+1);
    cout<<ans;
}