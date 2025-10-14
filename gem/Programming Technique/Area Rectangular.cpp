#include<bits/stdc++.h>
using namespace std;

int area[1010][1010];//,qs[1010][1010];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c,q;
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> area[i][j];
            if(j==0&&i>0)area[i][j]=area[i][j]+area[i-1][j];
            if(i==0&&j>0)area[i][j]=area[i][j]+area[i][j-1];
            if(j>0&&i>0){
                area[i][j]=area[i][j]+area[i-1][j]+area[i][j-1]-area[i-1][j-1];
            }
        }
    }
    cin >> q;
    while(q--){
        int i,j,k,l,fr,se,pl;
        cin >> i >> j >> k >> l;
        {i==0?fr=0:fr=area[i-1][l];}
        {j==0?se=0:se=area[k][j-1];}
        {(i==0||j==0)?pl=0:pl=area[i-1][j-1];}
        cout << area[k][l]-fr-se+pl << "\n";
    }
}
