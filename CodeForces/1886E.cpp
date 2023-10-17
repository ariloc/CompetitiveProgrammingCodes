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

int const MAXN = 2e5+5;
int const MAXP = 20;
int const INF = 2e9;

ii pers[MAXN];
int proy[MAXN];
int jmp[MAXN][MAXP]; // block jump for project starting at i
int dp[1<<MAXP], P[1<<MAXP];
vi rta[MAXP];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> pers[i].fst, pers[i].snd = i;
    forn(i,m) cin >> proy[i];

    sort(pers,pers+n,greater<ii>());

    vi ptrs(m,0);
    forn(i,n) forn(j,m) {
        if (ptrs[j] == i) ++ptrs[j];
        while(ptrs[j] < n && pers[ptrs[j]-1].fst*(ll)(ptrs[j]-i) < proy[j]) ++ptrs[j];
        if (pers[ptrs[j]-1].fst*(ll)(ptrs[j]-i) >= proy[j]) jmp[i][j] = ptrs[j];
        else jmp[i][j] = -1;
    }

    dp[0] = 0, P[0] = -1;
    forsn(i,1,1<<MAXP) dp[i] = INF;
    forsn(i,1,1<<m) {
        forn(j,m) if (i&(1<<j)) {
            int prv = i^(1<<j);
            if (dp[prv] >= n) continue;
            int minind = jmp[dp[prv]][j];
            if (minind != -1 && minind < dp[i]) dp[i] = minind, P[i] = j;
        }
    }

    if (dp[(1<<m)-1] == INF) cout << "NO\n";
    else {
        cout << "YES\n";
        int cur = (1<<m)-1, r = dp[cur]-1;
        while (cur) {
            int prv = P[cur];
            int prvmk = cur^(1<<prv);
            int l = dp[prvmk];
            forsn(j,l,r+1) rta[prv].pb(pers[j].snd);
            r = l-1;
            cur = prvmk;
        }
        forn(i,m) {
            cout << (int)rta[i].size() << ' ';
            for (auto &j : rta[i]) cout << j+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
