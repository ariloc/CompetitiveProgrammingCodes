#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0 ; i < int(n); i++)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool cero = false;
    int N;
    long long r=0, cntNeg = 0;
    cin >> N;
    forn(i,N) {
        int x;
        cin >> x;
        if (x < 0) {
            cntNeg++;
            r+=abs(x+1);
        }
        else if (x > 0) r+=x-1;
        else {
            cero = true;
            r++;
        }
    }
    if (cntNeg % 2) {
        if (cero) cout << r;
        else cout << r+2;
    }
    else cout << r;
    return 0;
}