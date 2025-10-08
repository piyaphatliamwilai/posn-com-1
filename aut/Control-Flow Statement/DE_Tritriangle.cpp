#include <bits/stdc++.h>
using namespace std;

int n, s, max_size;

void draw_stage(int stage) {
    int triangle_amount = 2 * stage - 1;
    int size = max_size/2;
    int index = (stage-1) * s;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < size-i-index; j++) {
            cout << "O";
        }
        for (int j = 0; j < 2 * (i+1) - 1; j++) {
            cout << "-";
        }
        if (stage > 1) {
            for (int k = 1; k <= stage-1; k++) {
                for (int j = 0; j < 2 * (s-i) - 1; j++) {
                    cout << "*";
                }
                for (int j = 0; j < 2 * (i+1) - 1; j++) {
                    cout << "-";
                }
            }
        }
        for (int j = 0; j < size-i-index; j++) {
            cout << "O";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a;
    cin >> a;
    for (int k = 0; k < a; k++) {
        cin >> n >> s;
        max_size = n * (2 * s - 1) + (n - 1);
        for (int i = 1; i <= n; i++) {
            draw_stage(i);
        }
    }
}
