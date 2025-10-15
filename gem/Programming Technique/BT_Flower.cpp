#include<bits/stdc++.h>
using namespace std;

vector <long long> hand;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q,opr,pick_up;
    cin >> q;
    while(q--){
        cin >> opr;
        if(opr == 1){
            cin >> pick_up;
            hand.push_back(pick_up);
        }
        else if(opr == 2){
            if(!hand.empty()){
                auto getout=hand.end();
                hand.pop_back();
                --getout;
                cout << *getout << "\n";
            }
            else if(hand.empty()){
                cout << -1 << "\n";
            }
        }
    }
}
