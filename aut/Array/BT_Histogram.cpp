#include <bits/stdc++.h>

using namespace std;

int a[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, highest = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
        highest = max(highest, x);
    }
    int best = 0;
    for (int i = 0; i <= highest; i++) {
        if (a[i] > best) {
            best = a[i];
        }
    }
    for (int i = best; i > 0; i--) {
        for (int j = 1; j <= highest; j++) {
            if (a[j] >= i) {
                cout << "*";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
}
