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

const int MAXN = 3005;

vi GD[MAXN],GI[MAXN]; // llego a, llegan a mi
int gotToMe[MAXN][MAXN]; // al primero, del segundo
bitset<MAXN> getMeInter;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,m) {
        int a,b; cin >> a >> b; a--; b--;
        GD[a].pb(b);
        GI[b].pb(a);
    }

    forn(i,n) {
        getMeInter.reset();
        for (auto &j : GI[i]) getMeInter[j] = true;
        for (auto &j : GD[i])
            forn (k,n) gotToMe[j][k] += (int)getMeInter[k];
    }

    ll rta = 0;
    forn(i,n) forn(j,n) {
        if (i == j) continue;
        if (gotToMe[i][j] >= 2) rta += (gotToMe[i][j]*(gotToMe[i][j]-1))/2;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!