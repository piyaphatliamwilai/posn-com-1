#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, z, d0, d1, d2, d3 = 1e7;
    scanf("%d %d %d %d %d %d %d", &x, &y, &z, &d0, &d1, &d2, &d3);
    int kp_x = (x - (d1- d0)) / 2;
    int kp_y = (y - (d2 - d0)) / 2;
    int kp_z = (z - (d3 - d0)) / 2;
    cout << kp_x << " " << kp_y << " " << kp_z << endl;
    int n;
    scanf("%d", &n);
    int t_;
    for (int i = 0; i < n; i++) {
        double vx, vy, vz;
        scanf("%lf %lf %lf", &vx, &vy, &vz);
        int t = (kp_x/vx + kp_y/vy + kp_z/vz) * 2;
        if (t < t_) {
            t_ = t;
        }
    }
    cout << t_ << endl;
    return 0;
}
