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

const int MAXN = 1002;
const int INF = 1e9+5;

int city[MAXN], fuel[MAXN], betterR[MAXN], dists[MAXN];

ll isPosib (ll tmpF, int i) {
    bool posib = true;
    forsn(j,i,betterR[i]) {
        tmpF -= city[j]; // es distancia ya
        if (tmpF < 0) {posib = false; break;}
        if (j != betterR[i]-1) tmpF += fuel[j+1]; // así no sumo lo último
    }
    return (!posib ? -1 : tmpF);
}

int main() {
    FAST_IO;

    int m,k; cin >> m >> k;
    forn(i,m) cin >> city[i];
    forn(i,m) cin >> fuel[i];

    fuel[m] = INF;
    dforn(i,m) {int j; for(j = i+1; fuel[j] <= fuel[i]; j = betterR[j]); betterR[i] = j;} // primero mayor
    int s = 0; forn(i,m) {s += city[i]; dists[i+1] = s;} // TAd

    int rta = 0; ll f = 0;
    forn(i,m) {
        f += fuel[i];
        int low = -1, high = 1e6+2;
        while (high-low > 1) {
            int mid = (high+low)/2;

            if (isPosib(f+fuel[i]*mid,i) != -1) high = mid;
            else low = mid;
        }

        ll v = isPosib(f+fuel[i]*low,i);
        if (low >= 0 && v != -1) {f = v; rta += k*low;}
        else {f = isPosib(f+fuel[i]*high,i); rta += k*high;}
        rta += dists[betterR[i]]-dists[i];
        i = betterR[i]-1; // -1 así después el for le suma 1
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
