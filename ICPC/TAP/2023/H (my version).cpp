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

int const MAXN = 1005;
int const INF = 2e9;

struct cell {
    int v;
    ii pos;

    bool operator< (const cell &o) const {
        return v < o.v;
    }
};

int mat[MAXN][MAXN];
int dpr[MAXN], dpc[MAXN];
int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) forn(j,n) cin >> mat[i][j];

    forn(i,n) dpr[i] = dpc[i] = -INF;
    forn(i,n) forn(j,n) dp[i][j] = -INF;

    vector<cell> cells;
    forn(i,n) forn(j,n) cells.pb({mat[i][j],(ii){i,j}});

    sort(all(cells));

    for (auto &i : cells) {
        ii pos = i.pos;
        dp[pos.fst][pos.snd] = max(max(dpr[pos.fst], dpc[pos.snd]) + 1,1);
        int a = dpr[pos.fst], b = dpc[pos.snd];
        dpc[pos.snd] = max(dpc[pos.snd], max(a+1,1));
        dpr[pos.fst] = max(dpr[pos.fst], max(b+1,1));
    }

    int maxi = -INF;
    forn(i,n) forn(j,n) maxi = max(maxi, dp[i][j]);

    cout << maxi;

    return 0;
}
