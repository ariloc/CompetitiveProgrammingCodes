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

int const MAXN = 1e5+5;
int const MAXR = 250 + 10;
int const MAXA = 26;
int const INF = 2e9;

int dp[MAXR][MAXR][MAXR];
int ap[MAXN][MAXA];

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    string s; cin >> s;

    vi curap(MAXA,INF);
    dforn(i,n) {
        curap[s[i]-'a'] = i;
        forn(j,MAXA) ap[i][j] = curap[j];
    }

    string r[3];

    auto upd = [&](int i, int j, int k) {
        if (i && dp[i-1][j][k] < n-1) dp[i][j][k] = min(dp[i][j][k], ap[dp[i-1][j][k]+1][r[0][i-1]-'a']);
        if (j && dp[i][j-1][k] < n-1) dp[i][j][k] = min(dp[i][j][k], ap[dp[i][j-1][k]+1][r[1][j-1]-'a']);
        if (k && dp[i][j][k-1] < n-1) dp[i][j][k] = min(dp[i][j][k], ap[dp[i][j][k-1]+1][r[2][k-1]-'a']);
    };

    forn(i,MAXR) forn(j,MAXR) forn(k,MAXR) dp[i][j][k] = INF;
    dp[0][0][0] = -1;
    forn(_,q) {
        char op; cin >> op;

        if (op == '+') {
            int p; cin >> p;
            char c; cin >> c;

            r[p-1].pb(c);

            if (p == 1) {
                int i = r[0].size();
                forn(j,r[1].size()+1) forn(k,r[2].size()+1)
                    upd(i,j,k);
            }
            else if (p == 2) {
                int j = r[1].size();
                forn(i,r[0].size()+1) forn(k,r[2].size()+1)
                    upd(i,j,k);
            }
            else {
                int k = r[2].size();
                forn(i,r[0].size()+1) forn(j,r[1].size()+1)
                    upd(i,j,k);
            }

        }
        else {
            int p; cin >> p;
            r[p-1].pop_back();

            if (p == 1) {
                int i = (int)r[p-1].size()+1;
                forn(j,r[1].size()+1) forn(k,r[2].size()+1) dp[i][j][k] = INF;
            }
            else if (p == 2) {
                int j = (int)r[p-1].size()+1;
                forn(i,r[0].size()+1) forn(k,r[2].size()+1) dp[i][j][k] = INF;
            }
            else {
                int k = (int)r[p-1].size()+1;
                forn(i,r[0].size()+1) forn(j,r[1].size()+1) dp[i][j][k] = INF;
            }
        }
        
        cout << (dp[(int)r[0].size()][(int)r[1].size()][(int)r[2].size()] < n ? "YES" : "NO") << '\n';
    }

    return 0;

}
