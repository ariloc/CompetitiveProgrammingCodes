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
const ll INF = 9e18+2;

ll dp[MAXN][2];
int cost[MAXN];
vector<string> S;

int main() {
    FAST_IO;

    int N; cin >> N;
    forn (i,MAXN) forn (j,2) dp[i][j] = INF; // reset
    forn (i,N) cin >> cost[i];
    forn (i,N) {string s; cin >> s; S.pb(s);}

    dp[0][0] = 0; dp[0][1] = cost[0];
    forsn (i,1,N) // dado un string
        forn (j,2) // invertido o no
            forn (k,2) { // y el anterior invertido o no
                string act = S[i], prev = S[i-1];
                bool lexMore = true;
                if (j) reverse(all(act));
                if (k) reverse(all(prev));
                lexMore = (act >= prev);

                if (lexMore)
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+(j ? cost[i] : 0));
            }

    cout << (min(dp[N-1][0],dp[N-1][1]) == INF ? -1 : min(dp[N-1][0],dp[N-1][1]));

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!