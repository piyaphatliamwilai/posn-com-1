#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        bool answer = false;
        string s;
        cin >> s;
        for (int i = s.length()-1; i>0; i--) {
            if (s[i] == '0') {
                cout << "1";
                answer = true;
            } else {
                break;
            }
        }
        if (!answer) cout << "0";
        cout << endl;
    }
}
