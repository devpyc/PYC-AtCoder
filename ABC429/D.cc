#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    ll m, c;
    cin >> n >> m >> c;

    vector<ll> arr(n);
    for (auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    vector<ll> pos, cnt;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && arr[j] == arr[i]) ++j;
        pos.push_back(arr[i]);
        cnt.push_back(j - i);
        i = j;
    }

    int k = pos.size();

    vector<ll> res(k);
    for (int i = 0; i + 1 < k; ++i)
        res[i] = pos[i + 1] - pos[i];
    res[k - 1] = (m - pos[k - 1]) + pos[0];

    vector<ll> cnt2(2 * k);
    for (int i = 0; i < 2 * k; ++i)
        cnt2[i] = cnt[i % k];

    ll ans = 0;
    ll sum = 0;
    int r = 0;

    for (int i = 0; i < k; ++i) {
        while (sum < c) {
            ++r;
            sum += cnt2[r];
        }
        ans += res[i] * sum;
        sum -= cnt2[i + 1];
    }

    cout << ans;
}