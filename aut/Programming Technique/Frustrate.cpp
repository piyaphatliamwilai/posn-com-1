#include <bits/stdc++.h>
using namespace std;
int prefixSums[100005];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> prefixSums[i];
    for (int i = 1; i <= n; i++) prefixSums[i] += prefixSums[i-1];
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixSums[r] - prefixSums[l-1] << "\n";
    }
}
