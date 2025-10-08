#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a = i;
        bool is3 = false;
        while (a > 0) {
            if (a % 10 == 3) {
                is3 = true;
                break;
            }
            a /= 10;
        }
        if (i % 3 == 0 || is3) {
            cout << "Pong ";
        } else {
            cout << i << " ";
        }
    }
    return 0;
}
