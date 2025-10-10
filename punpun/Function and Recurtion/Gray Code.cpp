#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
   
    int m; cin >> m;
    while (m--) {
	   int n, BUFFER = 0; cin >> n;
	   int max1 = pow(2, n);  
	   string GRAY = "", BIN = "", SHFBIN = "";
	   while (BUFFER < max1) {
		  int BUFFER2 = BUFFER;
		  BIN = ""; SHFBIN = "";
		  while (BUFFER2 > 0) { //int >> bin
			 BIN = to_string(BUFFER2 % 2) + BIN;
			 if (BUFFER2 != BUFFER) SHFBIN = to_string(BUFFER2 % 2) + SHFBIN; 
			 BUFFER2 /= 2;
		  } if (BIN.size() < n) {
			 BUFFER2 = n - BIN.size();
			 while (BUFFER2--) {
				BIN = "0" + BIN;
				SHFBIN = "0" + SHFBIN;
			 }
		  }
		  
		  if (BUFFER) SHFBIN = "0" + SHFBIN;
		  
		  // cout << BIN << "\n" << SHFBIN << "\n";

		  for (int i = 0; i < n; i++) {
			 cout << (int)(BIN[i] != SHFBIN[i]) ;
		  }
		  cout << '\n';
		  
		  BUFFER++;
	   }
    }

    return 0;
}
