#include <bits/stdc++.h>
using namespace std;
char grid[1010][90];
int gridW = 0, gridH = 0;
int move_dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int get_longest_path(int x, int y) {
    if (grid[y][x] == '.') return 0;
    int longest = 1;
    grid[y][x] = '.';
    for (int i = 0; i < 4; i++) {
        int visitX = x + move_dir[i][0];
        int visitY = y + move_dir[i][1];
        if (visitX < 0 || visitX >= gridW || visitY < 0 || visitY >= gridH) continue;
        if (grid[visitY][visitX] == '.') continue;
        longest = longest+get_longest_path(visitX, visitY);
    }
    return longest;
}

int main () {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> gridW >> gridH;
    for (int y = 0; y < gridH; y++) {
        for (int x = 0; x < gridW; x++) {
            cin >> grid[y][x];
        }
    }
    int longest = 0;
    for (int y = 0; y < gridH; y++) {
        for (int x = 0; x < gridW; x++) {
            longest = max(longest, get_longest_path(x, y));
        }
    }
    cout << longest;
}
