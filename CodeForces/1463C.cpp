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

const int MAXN = 1e5+2;
const ll INF = 1e18+10;

struct data {
    ll ind, posic, t;
};

pair<ll,ll> comm[MAXN];

int main() {
    FAST_IO;

    int tst; cin >> tst;

    forn(i,tst) {
        int n; cin >> n;
        forn(j,n) {
            int t,x; cin >> t >> x;
            comm[j] = {t,x};
        }
        ll last = -1, ETA = -1, posic = 0;
        vector<data> listened; // lista del recorrido del robot
        forn(j,n) {
            if (comm[j].fst >= ETA) ETA = -1, last = -1;
            if (last == -1) {
                listened.pb({j,posic,comm[j].fst}); last = j;
                ll dist = abs(comm[j].snd-posic);
                posic = comm[j].snd;
                ETA = dist+comm[j].fst;
            }
        }
        comm[n] = {INF,INF};

        int rta = 0;
        forn(j,n) {
            int lastC = upper_bound(all(listened),comm[j].fst,[](const int &rhs,const data &lhs){return rhs < lhs.t;})-listened.begin()-1;
            ll ind = listened[lastC].ind;
            ll myETA = abs(comm[ind].snd-listened[lastC].posic) + comm[ind].fst;
            ll ETAinRange = min(comm[j+1].fst,myETA);

            ll l = listened[lastC].posic + abs(comm[j].fst-comm[ind].fst)*(listened[lastC].posic > comm[ind].snd ? -1 : 1);
            ll r = listened[lastC].posic + abs(ETAinRange-comm[ind].fst)*(listened[lastC].posic > comm[ind].snd ? -1 : 1);
            //cerr << ind << ' ' << myETA << ' ' << ETAinRange << ' ' << l << ' ' << r << ' ' << j << ' ' <<rta << " !!!" <<endl;

            if (r < l) swap(r,l);

            if (comm[j].snd >= l && comm[j].snd <= r) rta++;
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
