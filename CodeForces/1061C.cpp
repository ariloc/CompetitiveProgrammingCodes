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

const int MOD = 1e9+7;
const int MAXN = 1e6+5;

int posic[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    posic[0]++;
    ll rta = 0;
    forn(i,n) {
        int x; cin >> x;
        vector<ii> add;
        for (int j = 1; j*j <= x; j++)
            if (!(x%j)) {
                int prv = posic[j-1];
                if (j <= i+1) rta = (rta+prv)%MOD; else break;
                add.pb({j,prv}); int ot = x/j; int otPrv = posic[ot-1];
                if (ot != j and ot <= i+1) {rta = (rta+otPrv)%MOD; add.pb({ot,otPrv});}
            }
        for (auto &j : add) {
            int me = posic[j.fst];
            posic[j.fst] = (me+j.snd)%MOD;
        }
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
