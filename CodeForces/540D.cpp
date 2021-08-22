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

const int MAXN = 105;

double dp[MAXN][MAXN][MAXN];

int main() {
    FAST_IO;

    int R,S,P; cin >> R >> S >> P;

    dp[R][S][P] = 1;
    dforn (r,R+1) dforn(s,S+1) dforn(p,P+1) {
        double rs = r*s, rp = r*p, sp = s*p;
        double sum = rs+rp+sp;

        if (!sum) continue;

        if (r > 0) dp[r-1][s][p] += (dp[r][s][p]*rp/sum);
        if (s > 0) dp[r][s-1][p] += (dp[r][s][p]*rs/sum);
        if (p > 0) dp[r][s][p-1] += (dp[r][s][p]*sp/sum);

        //cerr << dp[r-1][s][p] << ' '<< dp[r][s-1][p] << ' ' << dp[r][s][p-1] << endl;
    }

    double r1 = 0, r2 = 0, r3 = 0;
    forsn(r,1,R+1) r1 += dp[r][0][0];
    forsn(s,1,S+1) r2 += dp[0][s][0];
    forsn(p,1,P+1) r3 += dp[0][0][p];

    cout << setprecision(10) << r1 << ' ' << r2 << ' ' << r3;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!