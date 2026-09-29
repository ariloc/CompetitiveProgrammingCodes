#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

int const MAXN = 1e5+5;
int const INF = 2e9;

int main() {
    int n; cin >> n;

    int maxi = -INF;
    int cnt = 0;
    forn(i,n) {
        int x; cin >> x;

        if (x > maxi) cnt++, maxi = max(maxi,x);
    }

    cout << cnt << '\n';

    return 0;
}
