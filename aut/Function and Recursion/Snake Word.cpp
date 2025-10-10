#include <bits/stdc++.h>
using namespace std;

char grid[50][50];
int move_dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int answers[105][2];
int h, w;
bool found = false;
bool visited[50][50];

void solve(int x, int y, int index, string &word) {
    if (found) return;
    
    answers[index][0] = x;
    answers[index][1] = y;

    if (index == word.length()-1) {
        found = true;
        for (int i = 0; i < word.length(); i++) {
            cout << answers[i][1]+1 << " " << answers[i][0]+1 << "\n";
        }
        return;
    }

    for (int i = 0; i < 4 && !found; i++) {
        int visitX = x + move_dir[i][0];
        int visitY = y + move_dir[i][1];
        if (visitX < 0 || visitX >= w || visitY < 0 || visitY >= h) continue;
        if (visited[visitY][visitX]) continue;
        if (grid[visitY][visitX] != word[index+1]) continue;
        
        visited[visitY][visitX] = true;
        solve(visitX, visitY, index+1, word);
        visited[visitY][visitX] = false;
    }
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
            if(grid[i][j] <= 'Z') grid[i][j] += 'a' - 'A';
        }
    }
    int n;
    cin >> n;
    while (n--) {
        string word;
        cin >> word;
        for (int i = 0; i < word.length(); i++) {
            if(word[i] <= 'Z') word[i] += 'a' - 'A';
        }
        found = false;
        memset(visited, false, sizeof(visited));
        
        for (int y = 0; y < h && !found; y++) {
            for (int x = 0; x < w && !found; x++) {
                if (grid[y][x] == word[0]) {
                    visited[y][x] = true;
                    solve(x, y, 0, word);
                    visited[y][x] = false;
                }
            }
        }

        if (!found)
            cout << "No Matching Word\n";
    }
}
