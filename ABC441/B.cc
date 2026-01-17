#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n,m;
    string s,t;
    cin>>n>>m>>s>>t;

    bool S[26]={false},T[26]={false};

    for (char c:s) {
        S[c-'a']=true;
    }
    for (char c:t) {
        T[c-'a']=true;
    }

    int q;
    cin>>q;
    while (q--) {
        string ss;
        cin>>ss;

        bool aa=true,bb=true;
        for (char c:ss) {
            if (!S[c-'a']) aa=false;
            if (!T[c-'a']) bb=false;
        }

        cout<<(aa&&!bb?"Takahashi":(!aa&&bb?"Aoki":"Unknown"))<<"\n";
    }
}