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

const int MAXN = 5e5+10;

vi G[MAXN];
int topics[MAXN];
ii topicsAux[MAXN];
bitset<MAXN> done,mark;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    forn (i,n) {cin >> topics[i]; topicsAux[i] = {topics[i],i};}
    sort(topicsAux,topicsAux+n);

    forn (i,n) {
        mark[topicsAux[i].snd] = true;
        set<int> posib;
        bool reg = false;
        for (auto &j : G[i]) {
            if (!mark[j]) break;
            if (topics[j] == topics[i]) {cout << -1; return 0;}
            if (topics[j] < topics[i]) posib.insert(j);
        }
        if (posib.size() != topics[i]-1) {cout << -1; return 0;}
    }

    forn (i,n) cout << topicsAux[i].snd+1 << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!