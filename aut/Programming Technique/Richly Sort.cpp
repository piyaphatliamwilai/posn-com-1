#include <bits/stdc++.h>
using namespace std;
struct XY {
    int x, y;
    const bool operator<(const XY &o) const {
        if (x == o.x) return y > o.y;
        return x < o.x;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N;
    cin >> N;
    vector<XY> points(N);
    for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
    sort(points.begin(), points.end());
    for (int i = 0; i < N; i++) cout << points[i].x << " " << points[i].y << "\n";
    return 0;
}
