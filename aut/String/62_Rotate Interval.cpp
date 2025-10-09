#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    string c;
    while (q--) {
        int n,k; 
        cin >> c;
        cin >> n >> k;
        int len = c.length();
        int parts = len/n;
        int rotatecnt = k%n;
        for (int i = 0; i < parts; i++) {
            for (int j = 0; j < n; j++) {
                cout << c[((n-rotatecnt+j)%n)+(i*n)];
            }
        }
        cout << endl;
    }    
    return 0;
}
