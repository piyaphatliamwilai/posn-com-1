#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    int limit = n + 1;
    vector<bool> prime(limit + 1, true);
    for (int p = 2; p * p <= limit; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;
    for (int p = 2; p <= limit; p++)
        if (prime[p]) res.push_back(p);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> res = sieve(n);
    if (n - 1 < res.size())
        cout << res[n - 1] << endl; // nth prime
}
