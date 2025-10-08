#include <bits/stdc++.h>

using namespace std;

string a[3][6] = {
    {"...", ".*.", ".*.", "*.*", "*.*", "***"},
    {".*.", "...", ".*.", "...", ".*.", "..."},
    {"...", ".*.", ".*.", "*.*", "*.*", "***"}
};

int main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < (int)s.size(); j++) {
                int r = s[j] - '0';
                cout << a[i][r-1];
                if (j != s.size() - 1) cout << "|";
            }
            cout << "\n";
        }
    }
}
