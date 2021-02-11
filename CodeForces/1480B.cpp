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

const int MAXN = 1e5+5;

ii monst[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int A,B,n; cin >> A >> B >> n;
        forn(j,n) cin >> monst[j].fst;
        forn(j,n) cin >> monst[j].snd;
        ll auxB = B; int maxi = 0;
        forn(j,n) {
            int cnt = (monst[j].snd+A-1)/A;
            auxB -= (ll)cnt*monst[j].fst;
            maxi = max(maxi,monst[j].fst);
        }
        cout << ((auxB + maxi) > 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
