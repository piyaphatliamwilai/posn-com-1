#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (d == 0) {
            if (r1 != r2) {
                cout << "None" << endl;
            } else {
                cout << "More" << endl;
            }
        } else if (d == r1 + r2 || (d == fabs(r1-r2))) {
            cout << "One" << endl;
        } else if (d < r1 + r2 && d > fabs(r1 - r2)) {
            cout << "More" << endl;
        } else {
            cout << "None" << endl;
        }
    }
    return 0;
}

