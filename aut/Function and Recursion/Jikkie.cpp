#include <bits/stdc++.h>
using namespace std;

int ans[30];
bool found[30][30];
int mxa,mxb,mxc;

void cc(int a, int b ,int c){
    if(a<0||b<0||c<0||a>mxa||b>mxb||c>mxc)return;
    if(a==0&&!ans[c])ans[c]=1;
    if(!found[a][b]){
        found[a][b] = 1;
        cc(0,b+a,c);
        cc(a-(mxb-b),mxb,c);
        cc(0,b,c+a);
        cc(a-(mxc-c),b,mxc);
        cc(a+b,0,c);
        cc(mxa,b-(mxa-a),c);
        cc(a,0,c+b);
        cc(a,b-(mxc-c),mxc);
        cc(a,b+c,0);
        cc(a,mxb,c-(mxb-b));
        cc(a+c,b,0);
        cc(mxa,b,c-(mxa-a));
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> mxa >> mxb >> mxc;
        cc(0,0,mxc);
        for(int i=0;i<=20;i++){
            if(ans[i]) cout << i << " ";
        }
}
