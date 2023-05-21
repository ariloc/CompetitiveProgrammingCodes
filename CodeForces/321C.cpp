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

const int MAXN = 1e5+5;

vi G[MAXN];

char rta[MAXN];
bitset<MAXN> done, centroid;
vi pass;
int cent;

void reset() {
    for (auto &i : pass) done[i] = false;
    pass.clear();
}

int find_centroid (int st, int n) {
    done[st] = true;
    pass.pb(st);

    bool posib = true;
    int s = 0;
    for (auto &i : G[st]) {
        if (!done[i] && !centroid[i]) {
            int aux = find_centroid(i,n);
            s += aux;
            if (aux > n/2) posib = false;
        }
    }

    if (n-s-1 > n/2) posib = false;

    if (posib) cent = st;

    return s+1;
}

int dfs (int st) {
    pass.pb(st);
    done[st] = true;

    int s = 1;
    for (auto &i : G[st]) if (!done[i] && !centroid[i]) s += dfs(i);

    return s;
}

void solve (int st, char c) {
    int n = dfs(st);
    reset();

    find_centroid(st,n);
    reset();

    rta[cent] = c;
    centroid[cent] = true;

    for (auto &i : G[cent])
        if (!centroid[i])
            solve(i,c+1);
}

int main() {
    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    
    solve(0, 'A');

    forn(i,n) cout << rta[i] << ' ';
    
    return 0;
}
