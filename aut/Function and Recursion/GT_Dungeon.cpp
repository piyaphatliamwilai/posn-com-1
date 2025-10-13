#include <bits/stdc++.h>
using namespace std;

char grid[20][20];
int move_dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int h, w, max_streak, best;

void solve(int x, int y, int cnt, int streak, int last_dir) {
    if (grid[y][x] == 'e') {
        best = min(best, cnt);
        return;
    }

    char backup = grid[y][x];
    grid[y][x] = '#';

    for (int i = 0; i < 4; i++) {
        int nx = x + move_dir[i][0];
        int ny = y + move_dir[i][1];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if (grid[ny][nx] == '#') continue;

        int new_streak = (i == last_dir) ? streak + 1 : 1;
        if (new_streak > max_streak) continue;

        solve(nx, ny, cnt + 1, new_streak, i);
    }

    grid[y][x] = backup; // backtrack
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> max_streak;
    n-=1;
    while (n--) {
        cin >> h >> w;
        int startX = 0, startY = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                cin >> grid[y][x];
                if (grid[y][x] == 's') {
                    startX = x;
                    startY = y;
                }
            }
        }

        best = INT_MAX;
        solve(startX, startY, 0, 0, -1);
        if (best == INT_MAX) cout << "0"; // no path found
        else cout << best << "\n";
    }
}
