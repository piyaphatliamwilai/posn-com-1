#include <bits/stdc++.h>
using namespace std;

string multiply(const string &a, const string &b) {
    if (a == "0" || b == "0") return "0";

    bool neg = false;
    string A = a, B = b;
    if (A[0] == '-') { neg = !neg; A = A.substr(1); }
    if (B[0] == '-') { neg = !neg; B = B.substr(1); }

    int n = A.size(), m = B.size();
    vector<int> result(n + m, 0);

    // Multiply digits
    for (int i = n - 1; i >= 0; i--) {
        int ai = A[i] - '0';
        for (int j = m - 1; j >= 0; j--) {
            int bj = B[j] - '0';
            result[i + j + 1] += ai * bj;
        }
    }

    // Propagate carry once
    for (int i = n + m - 1; i > 0; i--) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    // Convert to string and remove leading zeros
    string ans;
    int start = 0;
    while (start < result.size() && result[start] == 0) start++;
    for (int i = start; i < result.size(); i++)
        ans.push_back(result[i] + '0');

    if (neg) ans = "-" + ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    cout << multiply(a, b) << "\n";
}
