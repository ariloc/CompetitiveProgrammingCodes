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

const int MAXN = 1e5+2;
const ll INF = 9e18;

ll c[MAXN],a[MAXN],b[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> c[j];
        forn(j,n) cin >> a[j];
        forn(j,n) cin >> b[j];
        forn(j,n) if (a[j] > b[j]) swap(a[j],b[j]);

        ll suf = 0, minS = INF;
        ll maxi = 0;
        b[n] = c[n-1], a[n] = 1;
        dforn(j,n) {
            if (minS != INF) maxi = max(maxi,suf+b[j+1]-a[j+1]-minS);

            //dbg(a[j+1]); dbg(b[j+1]);
            if (b[j+1] == a[j+1]) suf = 0, minS = INF, b[j+1] = c[j], a[j+1] = 1;

            minS = min(minS,suf-b[j+1]+a[j+1]);
            suf += 2+(c[j]-b[j+1]+a[j+1]-1);
            //dbg(suf); dbg(minS);
            //cerr << maxi << ' ' << suf << ' ' << a[j+1] << ' ' << b[j+1] << endl;
        }

        cout << maxi << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
