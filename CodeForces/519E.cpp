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
const int MAXK = 18;

bitset<MAXN> done;
vi G[MAXN];
int P[MAXK][MAXN], D[MAXN];
int children[MAXN];

int dfs(int st, int lvl = 0) {
    done[st] = true;
    D[st] = lvl;

    int child = 0;
    for (auto &i : G[st]) {
        if (!done[i]) child += dfs(i, lvl+1), P[0][i] = st;
    }

    return children[st] = child + 1;
}

int lca (int a, int b) {
    if (D[a] > D[b]) swap(a,b);
    int dif = D[b] - D[a];
    forn(i,MAXK) if (dif&(1<<i)) b = P[i][b];
    if (a == b) return a;
    dforn(i,MAXK)
        if (P[i][a] != P[i][b])
            a = P[i][a], b = P[i][b];
    return P[0][a];
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(0);

    forsn(k,1,MAXK) forn(i,n) P[k][i] = P[k-1][P[k-1][i]];

    int m; cin >> m;
    forn(_,m) {
        int a,b; cin >> a >> b; a--, b--;

        int x = lca(a,b);
        if (a == b) cout << n << '\n';
        else {
            int dist = D[a] + D[b] - 2*D[x];
            if (dist&1) cout << "0\n";
            else {
                int half = dist/2;

                if (D[a]-D[x] > D[b]-D[x]) swap(a,b);

                int mid = b;
                forn(i,MAXK) if (half&(1<<i)) mid = P[i][mid];

                int childb = b, auxdist = half-1;
                forn(i,MAXK) if (auxdist&(1<<i)) childb = P[i][childb];

                int childa = a;
                forn(i,MAXK) if (auxdist&(1<<i)) childa = P[i][childa];

                if (D[a]-D[x] == D[b]-D[x]) {
                    cout << n - children[childa] - children[childb] << '\n';
                }
                else {
                    cout << children[mid] - children[childb] << '\n';
                }
            }
        }
    }

    return 0;
}
