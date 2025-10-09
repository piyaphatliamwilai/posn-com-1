#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    char a[100];
    cin >> a;
    int x = 0, y = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == 'N') y++;
        else if (a[i] == 'S') y--;
        else if (a[i] == 'E') x++;
        else if (a[i] == 'W') x--;
        else if (a[i] == 'Z') x = 0, y = 0;
    }
    cout << x << " " << y << endl; 
}
