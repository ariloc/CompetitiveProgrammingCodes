#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MOD = 998244353;
const int MAXN = 105;
const int MAXA = 26;

int dp[MAXN][MAXN];
int nxt[MAXN][MAXA];
int lastap[MAXA];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    FAST_IO;

    string s; cin >> s;
    int n = (int)s.size();

    forn(i,MAXA) lastap[i] = n;
    dforn(i,n) {
        lastap[s[i]-'a'] = i;
        forn(j,MAXA) nxt[i][j] = lastap[j];
    }

    int rta = 0;
    forsn(i,1,n) {
        forn(j,n+1) forn(k,n+1) dp[j][k] = 0;
        int fst_l = nxt[0][s[i]-'a'];
        dp[fst_l][i] = 1;
        forsn(j,fst_l,i) forsn(k,i,n) {
            forn(l,MAXA) {
                int nxt_l = nxt[j+1][l], nxt_r = nxt[k+1][l];
                dp[nxt_l][nxt_r] = sumMod(dp[nxt_l][nxt_r], dp[j][k]);
            }
        }
        forsn(j,fst_l,i) forsn(k,i,n) {
            if (nxt[j+1][s[i]-'a'] != i) continue;
            rta = sumMod(rta, dp[j][k]);
        }
    }

    cout << rta;

    return 0;
}
