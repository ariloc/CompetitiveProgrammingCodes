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

const int MAXN = 1005;

ll plots[MAXN];
ll dp[MAXN][MAXN], record[MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N) cin >> plots[i];

    forn (i,N) {
        dp[i][i] = plots[i];
        ll maxi = dp[i][i], sum = dp[i][i];

        forsn (j,i+1,N) {dp[i][j] = min(plots[j],maxi); maxi = min(maxi,dp[i][j]); sum += dp[i][j];}
        maxi = dp[i][i];

        dforn (j,i) {dp[i][j] = min(plots[j],maxi); maxi = min(maxi,dp[i][j]); sum += dp[i][j];}

        record[i] = sum;
    }

    ll best = -1, ind = -1;
    forn (i,N) if (record[i] > best) {best = record[i]; ind = i;}

    forn (i,N) cout << dp[ind][i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!