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

ii knap[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; ll w; cin >> n >> w;
        forn(j,n) {cin >> knap[j].fst; knap[j].snd = j;}

        sort(knap,knap+n);

        vi rta;
        int r = 0; ll s = 0;
        ll tg = (w+1)/2;
        forn(l,n) {
            while (r < n && s < tg) s += knap[r++].fst;
            if (s >= tg && s <= w) {
                forsn(j,l,r) rta.pb(knap[j].snd);
                break;
            }
            s -= knap[l].fst;
        }

        if (rta.empty()) cout << "-1\n";
        else {
            cout << rta.size() << '\n';
            for (auto &j : rta) cout << j+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
