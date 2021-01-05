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
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 1e9+5;

struct segT {
    int mini,maxi;

    segT operator+ (const segT &o) const {
        return {min(mini,o.mini),max(maxi,o.maxi)};
    }
};

int arr[MAXN], primMenor[MAXN][2]; // 0 es el de la izquierda, 1 el de la derecha
segT ST[2*MAXST];
vi nums, aparic[MAXN];

segT query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {INF,-INF};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br)+query(2*i+1,mid,tr,bl,br);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        int N = (1<<(32-__builtin_clz(n)));

        forn(j,2*N+2) ST[j] = {INF,-INF}; // asi no me rompe, reset
        forn(j,n) aparic[j].clear(); // reset peor caso
        nums.clear(); // reset

        forn(j,n) {
            int x; cin >> x;
            arr[j+1] = x; ST[j+N] = {x,x};
            nums.pb(x);
        }
        arr[0] = arr[n+1] = -INF;

        // calculo primero menor hacia ambos lados
        forsn(j,1,n+1) {int k; for (k = j-1; arr[k] >= arr[j]; k = primMenor[k][0]); primMenor[j][0] = k;}
        dforsn(j,1,n+1) {int k; for (k = j+1; arr[k] >= arr[j]; k = primMenor[k][1]); primMenor[j][1] = k;}

        // build segtree
        dforsn(j,1,N) ST[j] = ST[2*j]+ST[2*j+1];

        // compression
        sort(all(nums));
        nums.erase(unique(all(nums)),nums.end());

        forsn(j,1,n+1) {
            arr[j] = lower_bound(all(nums),arr[j])-nums.begin(); // actualizo con el comprimido
            aparic[arr[j]].pb(j); // guardo aparición
        }

        pair<ii,int> rta = {{-1,-1},-1};
        forn(j,nums.size()) { // solo me fijo los únicos
            if (aparic[j].size() < 3) continue;
            int fa = aparic[j][0], la = aparic[j].back();
            forsn(k,1,aparic[j].size()-1) {
                int meInd = aparic[j][k];
                int l1 = 0, r1 = max(fa,primMenor[meInd][0])-1;
                int l2 = r1+1, r2 = min(la-1,primMenor[meInd][1]-1)-1;
                int l3 = r2+1, r3 = n-1;

                segT q1 = query(1,0,N,l1,r1+1), q2 = query(1,0,N,l2,r2+1), q3 = query(1,0,N,l3,r3+1);

                if (q1.maxi == q3.maxi && q2.mini == q1.maxi) {
                    rta = {{r1-l1+1,r2-l2+1},r3-l3+1};
                    break;
                }
            }
        }

        if (rta.snd == -1) cout << "NO\n";
        else cout << "YES\n" << rta.fst.fst << ' ' << rta.fst.snd << ' ' << rta.snd << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
