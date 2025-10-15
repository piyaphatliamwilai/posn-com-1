#include <bits/stdc++.h>
using namespace std;

bool diff[1012][1012];
bool ans[1012][1012];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int w, h, n;
    cin >> w >> h >> n;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        diff[x1][y1] = (diff[x1][y1] + 1) % 2;
        diff[x2 + 1][y1] = (diff[x2 + 1][y1] + 1) % 2;
        diff[x1][y2 + 1] = (diff[x1][y2 + 1] + 1) % 2;
        diff[x2 + 1][y2 + 1] = (diff[x2 + 1][y2 + 1] + 1) % 2;
    }

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            int sum = diff[x][y] + ans[x - 1][y] + dp[x][y - 1] - ans[x - 1][y - 1];
            ans[x][y] = sum % 2;
        }
    }

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++)
            cout << ans[x][y];
        cout << '\n';
    }
}
