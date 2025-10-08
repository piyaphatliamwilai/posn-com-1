/*
* Author:  Piyaphat Liamwilai
* Task:    Slot Machine
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int slot[16][6];

    // Input
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> slot[i][j];
        }
    }

    int q = 0;
    int answer[800000][6]; // 800000 because 15^5 = 759375

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= n; l++) {
                    for (int m = 1; m <= n; m++) {
                        if (slot[i][1] == slot[j][2] &&
                            slot[j][2] == slot[k][3] &&
                            slot[k][3] == slot[l][4] &&
                            slot[l][4] == slot[m][5]) {

                            answer[q][1] = i;
                            answer[q][2] = j;
                            answer[q][3] = k;
                            answer[q][4] = l;
                            answer[q][5] = m;
                            q++;
                        }
                    }
                }
            }
        }
    }

    cout << q << "\n";
    for (int i = 0; i < q; i++) {
        cout << answer[i][1] << " "
             << answer[i][2] << " "
             << answer[i][3] << " "
             << answer[i][4] << " "
             << answer[i][5] << "\n";
    }
}
