#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a[2][10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, k;
    cin >> n >> r >> k;

    a[0][0] = 1 % k;

    for (int i = 1; i <= n; i++) {
        a[i & 1][0] = 1 % k;
        for (int j = 1; j <= min(i, r); j++) {
            a[i & 1][j] = (a[(i - 1) & 1][j - 1] + a[(i - 1) & 1][j]) % k;
        }
    }

    cout << a[n & 1][r] << "\n";
}
