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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;

int stat[MAXN], col[MAXN];
vi G[MAXN];
ii rooms[MAXN];

void dfs (int st, int myCol = 0) {
    col[st] = myCol;
    for (auto &i : G[st])
        if (col[i] == -1) dfs(i, 1^myCol);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,MAXN) col[i] = -1; // init
    forn(i,n) cin >> stat[i];
    forn(i,m) {
        int cnt; cin >> cnt;
        forn(j,cnt) {
            int x; cin >> x; x--;
            rooms[x].fst = i;
            swap(rooms[x].fst, rooms[x].snd);
        }
    }

    int prox_libre = m;
    forn(i,n) {
        int u = rooms[i].fst, v = rooms[i].snd;
        if (!stat[i]) G[u].pb(v), G[v].pb(u);
        else {
            G[u].pb(prox_libre), G[prox_libre].pb(u);
            G[prox_libre].pb(v), G[v].pb(prox_libre);
            prox_libre++;
        }
    }

    forn(i,m) if (col[i] == -1) dfs(i);

    bool posib = true;
    forn(i,n) {
        if (stat[i] && col[rooms[i].fst] != col[rooms[i].snd]) posib = false;
        if (!stat[i] && col[rooms[i].fst] == col[rooms[i].snd]) posib = false;
    }

    cout << (posib ? "YES" : "NO");

    return 0;
}