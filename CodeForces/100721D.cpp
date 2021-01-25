#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 9;
const ld INF = 1e9+5;

struct bowl {
    int h,r,R;
    ld cte;

    bowl() {
        h = r = R = cte = 0;
    }

    bool operator< (const bowl &o) const {
        if (h == o.h) {
            if (r == o.r) return R < o.R;
            return r < o.r;
        }
        return h < o.h;
    }
};

bowl lst[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> lst[j].h >> lst[j].r >> lst[j].R;
        forn(j,n) lst[j].r *= 2, lst[j].R *= 2, lst[j].cte = (lst[j].R-lst[j].r)/(ld)lst[j].h;

        sort(lst,lst+n);

        ld minH = INF;
        do {
            ld thisH = lst[0].h;
            vector<pair<int,ld>> toComp = {{0,0}}; // comparar con el índice cuya base se encuentra a cierta altura

            forsn(j,1,n) {
                ld myH = 0; // altura de la base
                for (auto &k : toComp) {
                    int idx = k.fst;
                    ld h = (lst[idx].R-lst[j].r)/(ld)lst[j].cte;
                    ld h_top = max((ld)0,(lst[j].R-lst[idx].r)/(ld)lst[idx].cte), h_bottom = max((ld)0,(lst[j].r-lst[idx].r)/(ld)lst[idx].cte);

                    if (h_bottom >= lst[idx].h) myH = max(myH,k.snd+lst[idx].h);
                    else if (lst[idx].r+lst[idx].cte*(lst[j].h+h_bottom) < lst[j].R)
                        myH = max(myH, min(k.snd+h_top-lst[j].h, k.snd+lst[idx].h-h) );
                    else myH = max(myH,k.snd+h_bottom);
                }
                thisH = max(thisH,myH+lst[j].h);
                toComp.pb({j,myH});
            }

            minH = min(minH,thisH);
        } while(next_permutation(lst,lst+n));

        cout << (ll)minH << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
