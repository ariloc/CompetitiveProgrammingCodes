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

const int MAXN = 3e5+5;

set<int> G[MAXN];
bitset<MAXN> alone;

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;

    int rta = n;
    forn(i,n) alone[i] = true;

    forn(i,q) {
        int type; cin >> type;
        if (type == 1) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].insert(v);
            G[v].insert(u);
            if (alone[u]) alone[u] = false, rta--;
            if (alone[v]) alone[v] = false, rta--;
        } else {
            int v; cin >> v; v--;
            for (auto &j : G[v]) {
                G[j].erase(v);
                if (G[j].empty() && !alone[j]) alone[j] = true, rta++;
            }
            if (!alone[v]) alone[v] = true, rta++;
            G[v].clear();
        }
        cout << rta << '\n';
    }
   
    return 0;
}
