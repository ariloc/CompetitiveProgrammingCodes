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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

struct pers {
    int h,w,id;

    bool operator< (const pers &o) const {
        if (h == o.h) return w < o.w;
        return h < o.h;
    }
};

pers pep[MAXN],ord[MAXN];
int rta[MAXN];

void solve (int n) {
    int ind = 0; set<int> histo; map<int,int> pos;
    forn(j,n) {
        while (ind < n && ord[ind].h < pep[j].h) {
            histo.insert(ord[ind].w);
            pos[ord[ind].w] = ord[ind].id;
            ind++;
        }
        auto it = histo.lower_bound(pep[j].w);
        if (it == histo.begin()) continue;
        it = prev(it);
        rta[pep[j].id] = pos[(*it)]+1;
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) rta[j] = -1; // reset
        forn(j,n) {
            int h,w; cin >> h >> w;
            pep[j] = ord[j] = {h,w,j};
        }
        sort(ord,ord+n);
        sort(pep,pep+n);

        solve(n);
        forn(j,n) swap(ord[j].w,ord[j].h);
        sort(ord,ord+n);
        solve(n);

        forn(j,n) cout << rta[j] << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
