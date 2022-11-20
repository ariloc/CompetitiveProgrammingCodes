#include <algorithm>
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

vi G[MAXN], G2[MAXN];
vi inDegCmp[MAXN];
bitset<MAXN> done, done2;
int col[MAXN], conn[MAXN], inDeg[MAXN];
int prox_libre = 0;

void dfs (int st) {
    done[st] = true;
    col[st] = prox_libre;

    for (auto &i : G[st])
        if (!done[i]) dfs(i);
}

void dfs2 (int st) {
    done2[st] = true;

    for (auto &i : G2[st])
        if (!done2[i]) dfs2(i);
        else if (conn[col[st]] == -1) conn[col[st]] = i;
}

int main() {
    int n; scanf("%d", &n);

    forn(i,n) conn[i] = -1;

    forn(i,n) {
        int v; scanf("%d", &v), v--;
        G[i].pb(v), G[v].pb(i);
        inDeg[v]++;
        G2[i].pb(v);
    }

    forn(i,n) if (!done[i]) dfs(i), prox_libre++;

    forn(i,n) if (!done2[i]) dfs2(i);

    forn(i,n) if (!inDeg[i]) inDegCmp[col[i]].pb(i);

    vector<ii> rta;
    if (prox_libre > 1) {
        forn(i,prox_libre) {
            int nxt = (i+1)%prox_libre;
            vi &proxvec = inDegCmp[nxt];
            int prox = conn[nxt];
            if (!proxvec.empty()) prox = proxvec.back(), proxvec.pop_back();

            rta.pb({conn[i], prox});
        }
    }

    forn(i,prox_libre)
        while (!inDegCmp[i].empty()) {
            auto e = inDegCmp[i].back(); inDegCmp[i].pop_back();
            rta.pb({conn[i], e});
        }

    printf("%d\n", (int)rta.size());
    for (auto &i : rta) printf("%d %d\n", i.fst+1, i.snd+1);
 
    return 0;
}
