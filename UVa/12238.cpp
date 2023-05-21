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

struct edge {
    int v,w;
};

vector<edge> G[MAXN];
int P[MAXK][MAXN];
int D[MAXN];
ll sum[MAXN];
bitset<MAXN> done;

void dfs(int st, int lvl = 0, ll s = 0) {
    done[st] = true;
    sum[st] = s;
    D[st] = lvl;
    for (auto &i : G[st])
        if (!done[i.v]) dfs(i.v, lvl+1, s+i.w), P[0][i.v] = st;
}

int lca (int a, int b) {
    if (D[a] > D[b]) swap(a,b);
    int dif = D[b]-D[a];
    forn(i,MAXK) {
        if (dif&(1<<i))
            b = P[i][b];
    }
    if (a == b) return a;
    dforn(i,MAXK) {
        if (P[i][a] != P[i][b]) {
            a = P[i][a];
            b = P[i][b];
        }
    }
    return P[0][a];
}

int main() {
    FAST_IO;

    int n; 
    while(cin >> n) {
        if (!n) break;

        forn(i,n) G[i].clear(), sum[i] = 0, D[i] = 0, done[i] = 0;

        forn(i,n-1) {
            int a,l; cin >> a >> l;
            G[a].pb({i+1,l}), G[i+1].pb({a,l});
        }

        dfs(0);

        forsn(i,1,MAXK) forn(j,n) P[i][j] = P[i-1][P[i-1][j]];

        int q; cin >> q;
        forn(ind,q) {
            int s,t; cin >> s >> t;
            int x = lca(s,t);
            cout << sum[s] + sum[t] - 2*sum[x];
            if (ind+1 < q) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
