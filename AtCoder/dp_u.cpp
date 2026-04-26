#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 16;

int mat[MAXN][MAXN];
ll dp[1<<MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) forn(j,n) cin >> mat[i][j];

    forn(i,1<<n) {
        forn(j,n) forsn(k,j+1,n) {
            if ((i&(1<<j)) && (i&(1<<k)))
                dp[i] += mat[j][k];
        }
    }

    forn(mk,1<<n) 
        for (int s = mk; s; s = (s-1)&mk) 
            dp[mk] = max(dp[mk], dp[s]+dp[mk^s]);

    cout << dp[(1<<n) - 1] << '\n';

    return 0;
}
