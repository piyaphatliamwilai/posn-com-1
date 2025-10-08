#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int z = 0; z < n; z++) {
        int s;
        cin >> s;
        if (s % 2 == 0) continue;
        for (int i = 0; i < s; i++) {
            // P
            for (int j = 0; j<s; j++) {
                if (i == 0 || i == (s/2) || j == 0 || (i < s/2 && j == s-1)) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
            cout << "-";
            // O
            for (int j = 0; j<s; j++) {
                if (i == 0 || i == s-1 || j == 0 || j == s-1) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
            cout << "-";
            // S
            for (int j = 0; j<s; j++) {
                if (i == 0 || i == s/2 || (i < s/2 && j == 0) || (i > s/2 && j == s-1) || i == s-1) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
            cout << "-";
            for (int j = 0; j<s; j++) {
                if (j == 0 || j == s-1 || j == i) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
             cout << "\n";
        }
    }
}
