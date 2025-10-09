#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    string left = "", right = "", undo_L="";
    int lest_hand = 0;
    for (int i = 0; i < n; i++) {
        char command;
        cin >> command;
        if (command == 'q') {
            cout << (left.empty() ? "-" : left) << " " << (right.empty() ? "-" : right) << endl;
        } else if (command == 'p') {
            char hand;
            string t;
            cin >> hand >> t;
            if (hand == 'L') {
                left = t;
            } else if (hand == 'R') {
                right = t;
            }
        } else if (command == 'b') {
            char hand;
            int p;
            cin >> hand >> p;
            if (hand == 'L') {
                lest_hand = 0;
                undo_L = left;
                left = left.substr(0, p);
            } else if (hand == 'R') {
                lest_hand = 1;
                undo_L = right;
                right = right.substr(0, p);
            }
        } else if (command == 'c') {
            char hand;
            cin >> hand;
            if (hand == 'R') {
                right += left;
                left = "";
            } else {
                left += right;
                right = "";
            }
        } else if (command == 'r') {
            if (lest_hand == 0) {
                left = undo_L;
            } else if (lest_hand == 1) {
                right = undo_L;
            }
        }
    }
}
