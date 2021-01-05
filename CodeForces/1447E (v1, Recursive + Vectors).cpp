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
const int INF = 1e9+5;

int solve (vi &x, int lvl) {
    if (lvl < 0) return x.size();
    vi b0,b1;
    forn(j,x.size())
        if ((x[j]&(1<<lvl))) b1.pb(x[j]);
        else b0.pb(x[j]);
    if (b0.empty() || b1.empty()) return solve(x,lvl-1);
    return max(solve(b0,lvl-1), solve(b1,lvl-1)) + 1;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    vi arr;
    forn(j,n) {int x; cin >> x; arr.pb(x);}

    cout << n-solve(arr,29);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
