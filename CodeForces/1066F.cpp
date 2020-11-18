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

const int MAXN = 2e5+2;
const ll INF = 1e18+5;

struct pt {
    int fst,snd;
    bool operator< (const pt &o) const {
        if (fst == o.fst) {
            if (snd < o.snd) return true;
            return false;
        }
        if (fst > o.fst) return true;
        return false;
    }
};

map<int,map<bool,pt>> mini; // si veo el anillo desde abajo hacia arriba a la derecha, guardo mínimo y máximo
map<int,map<bool,ll>> dp; // si salgo por el 0 o por el 1
set<int> inds;

ll manhattan (pt a, pt b) {
    return (abs(b.fst-a.fst)+(ll)abs(b.snd-a.snd));
}

int main() {
    FAST_IO;

    mini[0][0] = mini[0][1] = {0,0};
    int n; cin >> n;
    forn(i,n) {
        int x,y; cin >> x >> y;
        int ind = max(x,y); inds.insert(ind);
        if (!mini[ind].count(0)) {mini[ind][0] = {-1,ind}; mini[ind][1] = {ind,-1};}
        mini[ind][0] = min(mini[ind][0],{x,y});
        mini[ind][1] = max(mini[ind][1],{x,y});
    }

    mini[0][0] = mini[0][1] = {0,0};
    dp[0][0] = dp[0][1] = 0;
    inds.insert(0);
    for (auto it = next(inds.begin()); it != inds.end(); it++) {
        int i = *it, pr = *(prev(it));
        dp[i][0] = dp[i][1] = INF; // reset
        forn(j,2) forn(k,2) // para cada salida, para cada entrada
            dp[i][j] = min(dp[i][j],dp[pr][k]+manhattan(mini[pr][k],mini[i][!j])+manhattan(mini[i][j],mini[i][!j]));
    }

    cout << min(dp[*prev(inds.end())][0],dp[*prev(inds.end())][1]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
