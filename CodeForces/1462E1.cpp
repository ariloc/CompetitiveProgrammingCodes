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
const int MOD = 1e9+7;

int arr[MAXN];/*, FT[MAXN];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}*/

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

ll fact[MAXN];

void precompFact () {
    fact[0] = 1;
    forsn(i,1,10) fact[i] = (fact[i-1]*(ll)i);
}

ll nCr (int n, int r) {
    return ((ll)n*(n-1)*(n-2))/fact[r];
}

int main() {
    FAST_IO;

    precompFact();

    int t; cin >> t;
    forn(i,t) {
        ll rta = 0;

        int n,m,k; cin >> n /*>> m >> k*/;
        k = 2; m = 3;
        forn(j,n) {cin >> arr[j]; /*setFT(arr[j],1);*/}
        //rta = n; // cuento todos los elementos únicos

        sort(arr,arr+n);

        int r = 0, /*pL = 0,*/ pR = 0;
        forn(l,n) {
            while (r < n && arr[r]-arr[l] <= k) r++;
           // cerr << l << ' ' <<r << endl;
            if (arr[r-1]-arr[l] <= k) {
                if (m <= r-l) rta = (rta + (ll)nCr(r-l,m));
                //cerr <<rta << "!!" << endl;
                int dif = max(0,pR-l);
                if (m <= dif) rta = (rta - (ll)nCr(dif,m));
                //cerr << rta << "!!!!" << dif << endl;
                /*pL = l;*/ pR = r;
            }
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
