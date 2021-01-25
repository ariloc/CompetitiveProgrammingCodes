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

const int MAXN = 1e4+5;
const int INF = 2e9;

vector<ii> gen[MAXN];
int rta[MAXN];

int main() {
    freopen("generators.in","r",stdin);
    freopen("generators.out","w",stdout);
    FAST_IO;

    int n,k; cin >> n >> k;

    forn(i,n) {
        int x0,a,b,c; cin >> x0 >> a >> b >> c;

        set<int> passed; int cnt = 0;
        while (!passed.count(x0)) {
            passed.insert(x0); gen[i].pb({x0,cnt++});
            x0 = ((x0*a)+b)%c;
        }

        sort(all(gen[i]));
    }

    ll s = 0;
    forn(i,n) s += gen[i].back().fst, rta[i] = gen[i].back().snd;

    if (!(s%k)) {
        int dif = INF, genCh = -1, indCh = -1;
        forn(i,n) {
            forn(j,gen[i].size()) {
                if (j == gen[i].back().fst) break;
                int tmpDif = gen[i].back().fst-gen[i][j].fst;
                if (tmpDif%k && tmpDif < dif) dif = tmpDif, genCh = i, indCh = j;
            }
        }
        if (genCh == -1) return cout << -1, 0;
        rta[genCh] = gen[genCh][indCh].snd; s -= dif;
    }

    cout << s << '\n';
    forn(i,n) cout << rta[i] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
