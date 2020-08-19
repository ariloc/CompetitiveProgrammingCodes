#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        vi arr,dp;
        int n; cin >> n;

        dp.resize(n+1,1);

        arr.pb(-2); // dummy
        forn (j,n) {int x; cin >> x; arr.pb(x);}

        forsn (j,1,n+1)
            for (int k = 1; k*k <= j; k++) {
                if (!(j % k)) {
                    int ot = j/k;
                    if (arr[j] > arr[k]) dp[j] = max(dp[j],dp[k]+1);
                    if (ot != j and ot != k and arr[j] > arr[ot]) dp[j] = max(dp[j],dp[ot]+1);
                }
            }

        int best = 1;
        forn (j,n+1) best = max(best,dp[j]);

        cout << best << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!