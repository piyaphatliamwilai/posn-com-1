#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int z;
    cin >> z;
    while (z--) {
        int a, b;
        string num;
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cin >> a >> b;
        cin >> num;
        int base10 = 0;
        int q = 0;
        for (int i = num.length()-1; i >=0; i--) {
            int p = num[i];
            if (p <= '9') {
                p = p-'0';
            } else {
                p = p-'A'+10;
            }
            base10 += p * pow(a, q);
            q++;
        }
        string answer = "";
        while (base10 > 0) {
            int remainder = base10 % b;
            answer += digits[remainder];
            base10 /= b;
        }
        reverse(answer.begin(), answer.end());
        cout << answer << endl;
    }
}
