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

const int MAXN = 2e5+10;

ll FT_a[MAXN], FT_b[MAXN];

ll getFT (int p, ll *FT) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, int v, ll *FT, int top) {
    ll actV = getFT(p,FT) - getFT(p-1,FT); // les resto porque ya sumé

    ll target = min((ll)top,actV+v);
    ll val = target-actV;

    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += val;
}

int main() {
    int n,k,a,b,q; scanf("%d %d %d %d %d",&n,&k,&a,&b,&q);

    forn(i,q) {
        int typ; scanf("%d",&typ);

        if (typ == 1) {
            int di,ai; scanf("%d %d",&di,&ai); di += 2; // seguridad FT
            setFT(di,ai,FT_a,a);
            setFT(di,ai,FT_b,b);
        }
        else {
            int pi; scanf("%d",&pi); pi += 2, // seguridad FT
            printf("%lld\n",getFT(pi-1,FT_b)+(getFT(MAXN-2,FT_a)-getFT(pi+k-1,FT_a)));
        }
    }

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!