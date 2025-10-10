#include <bits/stdc++.h>

using namespace std;

long long sumfacmod(int n, int m) {
    long long sum_rem = 0, prevrem, rem;
    for (int i = 0; i <= n; i++) {
	   if (i == 0) {sum_rem += 1; prevrem = 1;}
	   else {sum_rem += (prevrem*i)%m; prevrem = (prevrem*i)%m;}
    }
    return sum_rem;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int q; cin >> q;
    while (q--) {
	   string n, m, newn = ""; cin >> n >> m;
	   if (n.size() > m.size()) {
		  int i = n.size()-1;
		  while (newn.size()<m.size()) {
			 newn = m[i] + newn;
			 i--;
		  }
		  cout << sumfacmod(stoi(m)-1, stoi(m))%stoi(m) << '\n';
	   } else {
		  cout << sumfacmod(stoi(n), stoi(m))%stoi(m) << '\n';
	   }
    }

        
    return 0;
}
