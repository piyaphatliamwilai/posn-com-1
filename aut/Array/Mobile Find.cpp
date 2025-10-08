/*
* Author:   Piyaphat Liamwilai
* Task:     Mobile Find
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int z;
    cin >> z;
    for (int q = 0; q < z; q++) {
        int h, w;
        cin >> h >> w;
        int grid[h][w];
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                cin >> grid[y][x];

        int x_ = -1, y_ = -1, best = -1;

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int curr = grid[y][x];
                if (y + 1 < h) {
                    int south = grid[y+1][x];
                    if (abs(south - curr) <= 10 && south + curr > best) {
                        best = south + curr;
                        x_ = x;
                        y_ = y;
                    }
                }
                if (x + 1 < w) {
                    int east = grid[y][x+1];
                    if (abs(east - curr) <= 10 && east + curr > best) {
                        best = east + curr;
                        x_ = x;
                        y_ = y;
                    }
                }
            }
        }
        cout << y_ + 1 << " " << x_ + 1 << "\n";
    }
}
