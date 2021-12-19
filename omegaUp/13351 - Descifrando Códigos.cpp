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
typedef long double ld;

const int MAXN = 1e6+5;
const int INF = 2e9;

struct turing {
    int pow,energy,id;

    bool operator< (const turing &o) const {
        if (pow != o.pow) return pow < o.pow; // primero a menor a mayor en poder
        if (energy != o.energy) return energy > o.energy; // y luego mayor a menor en energía, para después mejorar
        return id < o.id;
    }
};

turing byPow[MAXN];
vi probPow_list[MAXN];
int codes[MAXN], rta[MAXN];
bitset<MAXN> isFull;

bool tryDays (int days, int n, int e) {

    isFull.reset();
    set<int> isFree;
    forn(i,n) isFree.insert(i);
    int last = -1, acc = 0;
    dforn(i,n) {
        if (!probPow_list[i].empty() && last == -1) last = i;
        acc += (int)probPow_list[i].size();

        while (acc > days) {
            auto it = isFree.lower_bound(last);
            if (it == isFree.end()) return false;

            isFull[*it] = true, isFree.erase(it);
            last = i; 
            acc -= days;
        }
    }

    if (acc > 0) { // si es por eso, estoy por debajo o igual a days
        auto it = isFree.lower_bound(last);
        if (it == isFree.end()) return false;
        isFull[*it] = true;
    }

    // vamos a ir moviendo las cubas a mejores lugares
    set<ii> cubasFull;
    forn(i,n) {
        if (isFull[i]) cubasFull.insert({byPow[i].energy, i});
        else if (!cubasFull.empty()) {
            auto it = prev(cubasFull.end());
            auto elem = (*it);
            if (elem.fst > byPow[i].energy) {
                isFull[elem.snd] = false, isFull[i] = true;
                cubasFull.erase(it);
                cubasFull.insert({byPow[i].energy, i});
            }
        }
    }

    ll acc_energy = 0;
    for (auto &i : cubasFull) acc_energy += i.fst;

    if (acc_energy > e) return false;
    return true;
}

int main() {
    int n,m,e; scanf("%d %d %d",&n,&m,&e); 
    forn(i,n) scanf("%d",&byPow[i].pow);
    forn(i,n) scanf("%d",&byPow[i].energy), byPow[i].id = i;
    forn(i,m) scanf("%d",&codes[i]);

    sort(byPow,byPow+n);

    forn(i,m) { // asigno al mas cercano los costos
        int ind = lower_bound(byPow, byPow+n, (turing){codes[i], INF, -INF}) - byPow;
        if (ind >= n) return printf("Imposible"), 0; // si alguno se pasa de todas las maquinas, es imposible.
        probPow_list[ind].pb(i);
    }

    int low = 0, high = m;
    while (high-low > 1) { // suponiendo una cantidad de dias
        int mid = (high+low)/2;
        if (tryDays(mid,n,e)) high = mid;
        else low = mid;
    }
    int rta_days = high;
    if (!tryDays(high,n,e)) return printf("Imposible"), 0; // si con la mejor no puedo, es imposible.

    // con isFull puedo reconstruir ̣{

    queue<int> rta_pending;
    forn(i,n) {
        for (auto &j : probPow_list[i]) rta_pending.push(j);
        if (isFull[i]) {
            int act_pending_sz = (int)rta_pending.size();
            forn(o, min(rta_days, act_pending_sz)) {
                int auxi = rta_pending.front(); rta_pending.pop();
                rta[auxi] = byPow[i].id+1;
            }
        }
    }

    forn(i,m) printf("%d ",rta[i]);
    
    return 0;
}