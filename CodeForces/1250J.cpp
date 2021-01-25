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

const int MAXN = 3e4+5;
const ll MAXC = 2e12+5;

ll h[MAXN],aux[MAXN];

bool posib (ll mid, ll k, int n) {
    ll rows = 0;
    forn(j,n) aux[j] = h[j];
    dforn(j,n) {
        rows += aux[j]/mid, aux[j] %= mid;
        if (j && aux[j]+aux[j-1] >= mid) aux[j-1] -= (mid-aux[j]), aux[j] = 0, rows++;
    }
    return (rows >= k);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; ll k; cin >> n >> k;
        forn(j,n) cin >> h[j];

        ll low = 0, high = MAXC;
        while (high-low > 1) {
            ll mid = (high+low)/2LL;
            if (posib(mid,k,n)) low = mid;
            else high = mid;
        }

        if (posib(high,k,n)) low = high;

        cout << low*k << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
