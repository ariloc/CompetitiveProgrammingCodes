#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;
const int INF = 1e9+5;

vi G[MAXN];
int stTime[MAXN], col[MAXN];
bitset<MAXN> matched;
int prox_libre = 1, actTime = 0;

vi pila;
int tarjan (int st) {
    stTime[st] = actTime++;
    pila.pb(st);

    int mini = actTime-1;
    for (auto &i : G[st]) {
        if (stTime[i] == -1) mini = min(mini,tarjan(i));
        if (!matched[i]) mini = min(mini,stTime[i]);
    }

    //cerr << mini << ' ' << stTime[st] << ' ' << st << endl;
    if (mini >= stTime[st])
        while (not pila.empty()) {
            int e = pila.back(); pila.pop_back();
            col[e] = prox_libre; matched[e] = true;
            if (e == st) {prox_libre++; break;}
        }

    return mini;
}

int main() {
    FAST_IO;

    memset(stTime,-1,sizeof(stTime));

    int n,m; cin >> n >> m;
    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
    }

    forn(i,n) if (stTime[i] == -1) tarjan(i);

    cout << prox_libre-1 << '\n';
    forn (i,n) cout << col[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
