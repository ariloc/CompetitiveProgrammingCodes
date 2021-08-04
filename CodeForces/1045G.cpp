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

const int MAXN = 1e5+5;
const int MAXC = 1e9+10; // máxima coord
const int INF = 2e9;

struct robot {
    int x,r,q;

    bool operator< (const robot &o) const {
        if (x != o.x) return x < o.x;
        if (q != o.q) return q < o.q;
        return r < o.r;
    }
};

struct hybrid {
    vector<robot> vec;
    vi FT;
};

robot robots[MAXN];
map<int,hybrid> perIQ;

void setFT (int p, int v, vi &FT) {
    for (int i = p; i < (int)FT.size(); i += i & -i)
        FT[i] += v;
}

int getFT (int p, vi &FT) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) 
        cin >> robots[i].x >> robots[i].r >> robots[i].q;

    forn(i,n) perIQ[robots[i].q].vec.pb(robots[i]);
    for (auto &i : perIQ) {
        sort(all(i.snd.vec)); // el criterio común prioriza x
        i.snd.FT.resize((int)i.snd.vec.size()+2); // 2 más por shift
        forn(j,i.snd.vec.size()) setFT(j+2,1,i.snd.FT); // shifteo en 2 al j+2 por seguridad de Fenwick
    }

    sort(robots,robots+n,[](const robot &lhs, const robot &rhs){
        return lhs.r < rhs.r;
    });

    ll rta = 0;
    forn(i,n) {
        // me borro
        auto it = perIQ.find(robots[i].q);
        int ind = lower_bound(all((*it).snd.vec),robots[i])-((*it).snd.vec.begin());
        setFT(ind+2,-1,(*it).snd.FT);
 
        forsn(j,robots[i].q-k,robots[i].q+k+1) {
            it = perIQ.find(j);
            if (it != perIQ.end()) {
                // busco los bordes
                int l = lower_bound(all((*it).snd.vec),(robot){robots[i].x-robots[i].r,-INF,-INF})-((*it).snd.vec.begin());
                int r = upper_bound(all((*it).snd.vec),(robot){robots[i].x+robots[i].r,INF,INF})-((*it).snd.vec.begin())-1;

                if (r-l >= 0) // si existen coincidencias
                    rta += getFT(r+2,(*it).snd.FT) - getFT(l+1,(*it).snd.FT);
            }
        }
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!