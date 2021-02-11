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

const int MAXN = 1002;
const ld EPS = 1e-10;

int a[MAXN],b[MAXN];

bool canArrive (int n, int rW, ld w) {
    forn(i,n) {
        w -= (rW+w)/(ld)a[i];
        w -= (rW+w)/(ld)b[(i+1)%n];
    }
    return (w >= 0);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[i];

    ld low = 0, high = 1e9+2;
    while (high-low > EPS) {
        ld mid = (high+low)/2;
        if (canArrive(n,m,mid)) high = mid;
        else low = mid;
    }

    if (canArrive(n,m,low)) high = low;
    if (!canArrive(n,m,high)) return cout << -1, 0;
    cout << fixed << setprecision(10) << high;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
