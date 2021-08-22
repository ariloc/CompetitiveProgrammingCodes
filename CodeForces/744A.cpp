#include <bits/stdc++.h>

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
const int MAXV = 1005;

bitset<MAXV> gov;
vector<ii> G[MAXV];
vi govt;
bitset<MAXN> edges;
int hab; ll mark = 0;

int dfs(int st) {
    gov[st] = true; hab--; mark++;

    int aristas = 0;
    for (auto &i : G[st]) {
        if (!edges[i.snd]) {aristas++; edges[i.snd] = true;}
        if (!gov[i.fst]) aristas += dfs(i.fst);
    }

    return aristas;
}

int main() {
    FAST_IO;

    int n,m,k; cin >> n >> m >> k;
    hab = n;

    forn (i,k) {int x; cin >> x; govt.pb(x-1);}

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb({b,i});
        G[b].pb({a,i});
    }

    ll toAdd = 0;

    ll maxN = -1, maxAd = 0, maxAr = 0;
    for (auto &i : govt) {
        mark = 0;
        int myAr = dfs(i); // marcar todos "contaminados"
        ll forAd = ((mark*(mark-1))/2)-myAr;
        if (mark > maxN) {maxN = mark; maxAd = forAd; maxAr = myAr;}
        toAdd += forAd;
    }

    mark = 0;
    forn (i,n) if (!gov[i]) maxAr += dfs(i);

    toAdd -= maxAd; mark += maxN;
    toAdd += ((mark*(mark-1))/2) - maxAr;

    cout << toAdd;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!