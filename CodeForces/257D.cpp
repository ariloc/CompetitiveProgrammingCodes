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

ll arr[MAXN];
bool mark[MAXN];
multiset<ll> num;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) cin >> arr[j];

    bool flip = false;
    ll s = 0;
    forn(j,n) s += arr[j];

    forn(j,n) num.insert(arr[j]);
    dforn(j,n) {
        if (abs(s) <= arr[0]) break;
        num.erase(num.find(arr[j]));
        ll calc = s - arr[j]*2LL;
        if (abs(calc) <= arr[0] || (calc-((*num.begin())*2)) >= -arr[0]) s = calc, mark[j] = true;
    }
    if (s < 0) flip = true;

    forn(j,n) cout << ((mark[j]^flip) ? '-' : '+');

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
