#include <bits/stdc++.h>
using namespace std;
int q[100005];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> q[i];
    sort(q, q+N);
    while (Q--) {
        int x;
        cin >> x;
        cout << (int)(lower_bound(q, q+N, x) - q) << "\n";
    }
}
