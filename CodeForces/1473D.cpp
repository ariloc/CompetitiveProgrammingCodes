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
const int INF = 1e9+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct segT {
    int s,minPref,maxPref;

    segT operator+ (const segT &o) const  {
        return { s+o.s, min(minPref,s+o.minPref), max(maxPref,s+o.maxPref) };
    }
};

segT ST[2*MAXST];

segT query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {0,0,0};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        int N = (1<<(32-__builtin_clz(n)));
        string s; cin >> s;
        dforn(j,N) ST[j+N] = {0,0,0};
        forn(j,s.size()) {
            ST[j+N].s = (s[j] == '+' ? 1 : -1);
            ST[j+N].maxPref = max(0,(s[j] == '+' ? 1 : -1));
            ST[j+N].minPref = min(0,(s[j] == '+' ? 1 : -1));
        }

        // build
        dforsn(j,1,N) ST[j] = ST[2*j] + ST[2*j+1];

        forn(j,m) {
            int l,r; cin >> l >> r; l--;
            segT a = query(1,0,N,0,l);
            segT b = query(1,0,N,r,N);
            segT me = (a+b);
            //cout << a.maxPref << ' ' << a.minPref << ' ' << b.maxPref << ' ' << b.minPref << endl;
            cout << me.maxPref-me.minPref+1 << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
