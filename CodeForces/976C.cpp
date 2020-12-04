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

const int MAXN = 6e5+2;
const int INF = 1e9+2;

pair<ii,int> seg[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int l,r; cin >> l >> r;
        seg[i] = {{l,r},i};
    }
    sort(seg,seg+n,[](const pair<ii,int> &lhs, const pair<ii,int> &rhs)
         {if (lhs.fst.fst == rhs.fst.fst) return lhs.fst.snd > rhs.fst.snd;
          return lhs.fst.fst < rhs.fst.fst;});

    set<ii> nds; ii rta = {-2,-2};
    forn(i,n) {
        auto it = nds.lower_bound({seg[i].fst.snd,-INF});
        if (it != nds.end()) {rta = {seg[i].snd,(*it).snd}; break;}
        nds.insert({seg[i].fst.snd,seg[i].snd});
    }

    cout << rta.fst+1 << ' ' << rta.snd+1;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
