#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;
const int INF = 2e9+2;

vi G[MAXN];
int colors[MAXN], colAdy[MAXN];
bitset<MAXN> done, done2;
int posib[MAXN]; // cantidad de disparidades

int dfs (int st) {
    done[st] = true;

    int cant = 0, ady = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            cant += dfs(i);
            ady += (colors[i] != colors[st]);
        }

    posib[st] = cant;
    colAdy[st] += ady;

    return cant + ady;
}

void dfs2 (int st, int prev) {
    done2[st] = true;

    if (prev != -1)
        posib[st] += (posib[prev]-posib[st]);
    if (prev > 0) colAdy[st] += (colors[st] != colors[prev]);

    for (auto &i : G[st])
        if (!done2[i])
            dfs2(i,st);
}

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (i,n-1) {
        int a,b; cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    G[0].pb(1);

    forsn (i,1,n+1) cin >> colors[i];

    dfs(0); dfs2(0,-1);

    forsn (i,1,n+1)
        if (posib[i]-colAdy[i] <= 0) {cout << "YES\n" << i; return 0;}
    cout << "NO";

    return 0;
}