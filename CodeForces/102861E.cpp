#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const INF = 2e9;

int age[MAXN],p[MAXN];
vi G[MAXN];
vector<ii> parties[MAXN];
vi setp[MAXN];
int FT[MAXN];
int rta[MAXN];

void setFT(int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT(int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

vector<ii> path;
void dfs(int st) {
    path.pb({age[st],st});

    for (auto &j : parties[st]) {
        int idx = lower_bound(all(path),(ii){j.snd,INF},greater<ii>())-path.begin();
        setp[path[idx].snd].pb(j.fst);
    }

    for (auto &i : G[st]) dfs(i);

    path.pop_back();
}

void dfs2(int st) {
    for (auto &j : setp[st]) setFT(j,1);
    rta[st] = getFT(age[st]);
    for (auto &i : G[st]) dfs2(i);
    for (auto &j : setp[st]) setFT(j,-1);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,n) cin >> age[i] >> p[i], --p[i];
    forsn(i,1,n) G[p[i]].pb(i);

    forn(i,m) {
        int o,l,r; cin >> o >> l >> r; --o;
        parties[o].pb({l,r});
    }

    dfs(0);
    dfs2(0);

    forn(i,n) cout << rta[i] << ' ';
    cout << '\n';

    return 0;
}
