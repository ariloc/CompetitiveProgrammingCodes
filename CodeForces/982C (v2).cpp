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

const int MAXN = 1e5+5;

vi G[MAXN];
bitset<MAXN> done;
bool posib = true;
int cnt = 0;

int dfs (int st) {
    done[st] = true;
    int acc = 0;
    for (auto &i : G[st])
        if (!done[i]) acc += dfs(i);
    if (!((acc+1)&1)) {cnt++; return 0;}
    return acc+1;
}

int main() {
    FAST_IO;

    int n; cin >> n; n--;
    forn(i,n) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    if (dfs(0)) posib = false;
    cout << (posib ? cnt-1 : -1);

    return 0;
}