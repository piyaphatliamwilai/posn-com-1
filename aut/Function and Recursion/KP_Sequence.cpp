#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> solve(ll position, int n, int k) {
    ll pos = position - 1;
    vector<ll> sequence;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ll seq = 1;
            seq = pow(seq * (k + 1), n - 1); // seq = (k+1)^(n-1)
            ll num = pos / seq;
            sequence.push_back(num);
            pos %= seq;
        } else {
            ll last = sequence[i - 1];
            if (n-i-1 == 0) {
                sequence.push_back(last + pos);
            } else {
                ll factor = pow(k + 1, n-i-1);
                sequence.push_back(last + (pos/factor));
                pos %= factor;
            }
        }
    }
    return sequence;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    ll p, q;
    cin >> n >> k >> p >> q;
    for (ll pos = p; pos <= q; pos++) {
        vector<ll> seq = solve(pos, n, k);
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << seq[i];
        }
        cout << "\n";
    }
    
    return 0;
}
