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

const int MAXN = 2e5+5;

vi G[MAXN];
ll rta = 0;
bitset<MAXN> done,centroid;
int dep[MAXN];
ll cur[MAXN];
int md = 0, mc = 0;
int cent = -1;
int N,K1,K2;
vi pass;

int find_centroid (int st, int n) {
    done[st] = true;
    pass.pb(st);

    bool posib = true;
    int s = 0;
    for (auto &i : G[st]) {
        if (!done[i] && !centroid[i]) {
            int aux = find_centroid(i,n);
            if (aux > n/2) posib = false;
            s += aux;
        }
    }

    if (n-s-1 > n/2) posib = false;
    if (posib) cent = st;

    return s+1;
}

int dfs2 (int st) {
    done[st] = true;
    pass.pb(st);

    int acc = 1;
    for (auto &i : G[st])
        if (!done[i] && !centroid[i]) acc += dfs2(i);

    return acc;
}

void dfs (int st, int lvl = 0) {
    done[st] = true;
    pass.pb(st);
    
    if (lvl) {
        dep[lvl]++;
        if (lvl+1 > md) md = lvl+1;
    }

    for (auto &i : G[st]) {
        if (!done[i] && !centroid[i]) {
            dfs(i,lvl+1);

            if (!lvl) {
                forn(j,md) {
                    int a = min(mc-1, K1 - j - 1), b = min(mc-1, K2 - j);
                    rta += (ll)dep[j] * ((b >= 0 ? cur[b] : 0) - (a >= 0 ? cur[a] : 0));
                }

                if (md > mc) {
                    forsn(j,mc,md) cur[j] = cur[j-1];
                    mc = md;
                }

                ll aux = 0;
                forn(j,mc) {
                    if (j < md) {
                        aux += dep[j];
                        dep[j] = 0;
                    }
                    cur[j] += aux;
                }
                md = 0;
            }
        }
    }
}

void reset() {
    for (auto &i : pass) done[i] = 0;
    pass.clear();
}

void solve (int st) {
    reset();
    int n = dfs2(st);

    reset();
    find_centroid(st,n);

    forn(i,mc) cur[i] = 0;
    cur[0] = 1, mc = 1;

    reset();
    dfs(cent);
    
    centroid[cent] = true;

    for (auto &i : G[cent])
        if (!centroid[i])
            solve(i);
}

int main() {
    scanf("%d %d %d",&N,&K1,&K2);

    forn(i,N-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    solve(0);

    printf("%lld\n",rta);
    
    return 0;
}
