#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // หาด้าน
    double a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    // สูตร heron
    // s = (a + b + c) / 2
    // area = root(s(s-a)(s-b)(s-c))
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s-a) * (s-b) * (s-c));
    double i = sqrt((4 * area) / sqrt(3));
    double j = i / 2;
    double k = (i * sqrt(3)) / 2;
    cout << fixed << setprecision(2);
    cout << i << " " << j << " " << k;
    return 0;
}
