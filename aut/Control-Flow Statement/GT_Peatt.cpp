#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int energy, e, f, g, h;
        e = min(a, b) * d + abs(a - b) * c;
        f = (a + b) * c;
        g = max(a, b) * d;
        h = max(a, b) * d - d + c;
        if (abs(a -b) % 2 == 1) {
            energy = min(e, min(f, h));
        } else {
            energy = min(e, min(f, g));
        }
        cout << energy << endl;
    }
    return 0;
}
