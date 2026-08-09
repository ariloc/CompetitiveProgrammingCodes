#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fst first
#define snd second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MOD = 1e9+7;
int const MAXN = 7;
int const MAXM = 50;
int const MAXC = 17000;

char tab[MAXN][MAXM];
int dp[MAXN][MAXM][MAXC];

int pot(int b, int k) {
    int r = 1;
    forn(_,k) r *= b;
    return r;
}

int main(){
    FAST_IO;

    int n,m,k; cin >> n >> m >> k;
    
    forn(i,n) forn(j,m) cin >> tab[i][j];

    int maxc = pot(4,n);

    if (tab[0][0] == '-') forn(l,k) dp[0][0][l<<(2*(n-1))] = 1;
    else dp[0][0][(tab[0][0]-'1')<<(2*(n-1))] = 1;
    forn(j,m) {
        forn(i,n) {
            if (!i && !j) continue;
            forn(mk,maxc) {
                int di = i-1, dj = j;
                if (!i) di = n-1, dj = j-1;
                if (tab[i][j] == '-') {
                    forn(l,k) {
                        if ((j && (mk & 3) == l) || (i && ((mk>>(2*(n-1))) & 3) == l)) continue;
                        int curmk = (mk>>2)|(l<<(2*(n-1)));
                        dp[i][j][curmk] = (dp[i][j][curmk] + dp[di][dj][mk])%MOD;
                    }
                }
                else {
                    int l = tab[i][j]-'1';
                    if ((j && (mk & 3) == l) || (i && ((mk>>(2*(n-1))) & 3) == l)) continue;
                    int curmk = (mk>>2)|(l<<(2*(n-1)));
                    dp[i][j][curmk] = (dp[i][j][curmk] + dp[di][dj][mk])%MOD;
                }
            }
        }
    }

    int rta = 0;
    forn(mk,maxc) rta = (rta + dp[n-1][m-1][mk])%MOD;

    cout << rta << '\n';

    return 0;
}
