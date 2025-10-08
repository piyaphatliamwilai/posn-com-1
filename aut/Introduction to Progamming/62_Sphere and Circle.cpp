#include <bits/stdc++.h>

using namespace std;

int main () {
    int r;
    cin >> r;
    cout << fixed << setprecision(3);
    double s = 4 * M_PI * r * r;
    double v = (4 * M_PI * r * r * r) / 3;
    double a = M_PI * r * r;
    double p = 2 * M_PI * r;
    cout << s << endl;
    cout << v << endl;
    cout << a << endl;
    cout << p << endl;
    return 0;
}
