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

const int MAXN = 2e5+5;

ii apps[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        ll ss = 0;
        forn(j,n) cin >> apps[j].fst, ss += apps[j].fst;
        forn(j,n) cin >> apps[j].snd;

        if (ss < m) {cout << "-1\n"; continue;} // caso imposible

        sort(apps,apps+n);

        ll acc = 0, rta = 0; int idx = n-1;

        vector<ll> imp,reg;
        dforn(j,n) {
            if (acc >= m) break;
            idx = j;
            acc += apps[j].fst, rta += apps[j].snd;
            if (apps[j].snd == 2) imp.pb(apps[j].fst);
        }

        dforn(j,idx) {
            if (apps[j].snd == 2) continue;
            reg.pb(apps[j].fst);
        }

        reverse(all(imp));
        forsn(j,1,imp.size()) imp[j] += imp[j-1];

        ll s = 0; int maxDif = 0;
        forn(j,reg.size()) {
            s += reg[j];
            int ind = upper_bound(all(imp),s+acc-m)-imp.begin()-1;
//            cerr << imp[0] << endl;
            //cerr << s << ' ' << ind << endl;
            maxDif = max(maxDif,(ind+1)*2-j-1);
        }

        cout << rta-maxDif << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
