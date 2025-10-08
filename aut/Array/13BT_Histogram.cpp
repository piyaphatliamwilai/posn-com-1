#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int arr[10000];
    int freq[10000] = {0};
    int mxnum = 0;
    int mxfreq = 0;
    int freqsize = sizeof(freq) / sizeof(freq[0]);

    // Read input and find max number
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > mxnum) mxnum = arr[i]; // find max value
    }

    // Count frequencies
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        if (x > 0) freq[x]++;
    }
    for(int i=0; i<freqsize; i++){
        mxfreq = max(mxfreq, freq[i]);

    }

    for(int i=mxfreq; i>=1; i--){
        for(int j=1; j<=mxnum; j++){
            if(freq[j]>=i){
                cout << "*";
            }
            else{
                cout << ".";
            }
        }
        cout << endl;
        
    }



}
