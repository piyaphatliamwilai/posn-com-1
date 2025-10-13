#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
   
    int m; cin >> m;
    while (m--) {
	   int n, BUFFER = 0; cin >> n;
	   int max1 = 1;
	   for (int i = 0; i < n; i++) max1 *= 2;
	   string GRAY = "", BIN = "";
	   while (BUFFER < max1) {
		  int BUFFER2 = BUFFER;
		  BIN = "";
		  while (BUFFER2 > 0) { //int >> bin
			 BIN = (char)('0' + BUFFER2 % 2) + BIN;
			 BUFFER2 /= 2;
		  } if (BIN.size() <= n) {
			 BUFFER2 = n - BIN.size() + 1;
			 while (BUFFER2--) {
				BIN = "0" + BIN;
			 }
		  }

		  //cout << BIN << "\n";

		  for (int i = 1; i <= n; i++) {
			 cout << (int)(BIN[i] != BIN[i-1]) ;
		  }
		  cout << '\n';
		  
		  BUFFER++;
	   }
    }

    return 0;
}
