// Binary Search
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int farm[100005];
ll l_bound, r_bound=1e18+7,mid;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> farm[i];
    while (l_bound < r_bound) {
        mid = (l_bound + r_bound) / 2;
        ll total = 0;
        for (int i = 0; i < N; i++) {
            total += mid / farm[i];
        }
        if (total >= M) r_bound = mid;
        else l_bound = mid + 1;
    }
    cout << l_bound << endl;
    return 0;
}
