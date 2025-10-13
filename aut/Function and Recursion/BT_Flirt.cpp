#include <bits/stdc++.h>
using namespace std;
int grid[30][30];
int move_dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int h=0, w=0, dir=0, startX=0, startY=0, endX=0, endY=0, idx=1;
bool found = false;
void solve(int startX, int startY) {
    if (found) return;
    grid[startY][startX] = idx++;
    if (startX == endX-1 && startY == endY-1) {
        found = true;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int visitX = startX + move_dir[(dir+i)%4][0];
        int visitY = startY + move_dir[(dir+i)%4][1];
        if (visitX >= 0 && visitX < w && visitY >= 0 && visitY < h && grid[visitY][visitX] == 0) {
            solve(visitX, visitY);
        }
    }
    
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        idx = 1;
        found = false;
        memset(grid, 0, sizeof(grid));
        cin >> h >> w >> dir >> startY >> startX >> endY >> endX;
        solve(startX-1, startY-1);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }
}   
