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

bool overHalf (ll n, ll take) {
    bool turn = 0;
    ll a = 0, b = 0;
    while (n) {
        if (!turn) a += min(n,take), n -= min(n,take);
        else {
            if (n/10 <= 0) {a += n; break;}
            b += n/10, n -= n/10;
        }
        turn = !turn;
    }
    return (a >= b);
}

int main() {
    FAST_IO;

    ll n; cin >> n;

    ll low = 1, high = n;
    while (high-low > 1) {
        ll mid = (high+low)/2;
        if (overHalf(n,mid)) high = mid;
        else low = mid;
    }

    if (overHalf(n,low)) high = low;

    cout << high;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
