#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+5;

struct edges {
    int v, id;
};

vector<edges> G[MAXN];
bitset<MAXN> done;
int T_val = -1;

int dfs (int st) {
    done[st] = true;

    int ret = st;
    for (auto &i : G[st])
        if (!done[i.v])
            ret = dfs(i.v);

    return ret;
}

vi rta;
int dfs2(int st) {
    done[st] = true;

    int cnt = 1;
    for (auto &i : G[st])
        if (!done[i.v]) {
            int aux = dfs2(i.v);
            if ((aux % T_val) == 0) {
                rta.pb(i.id);
            }
            else cnt += aux;
        }

    return cnt;
}

int cortarbol(vector<int> &a, vector<int> &b, int T, vector<int> &lineas) {
    int n = (int)a.size() + 1;
    T_val = T;

    forn(i,n-1) {
        int u = a[i], v = b[i]; u--, v--;
        G[u].pb({v,i}), G[v].pb({u,i});
    }

    int leaf = dfs(0);
    forn(i,n) done[i] = 0;

    dfs2(leaf);

    lineas = rta;
    return (int)rta.size() + 1;
}
