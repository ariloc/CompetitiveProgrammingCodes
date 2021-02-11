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

const int MAXN = 2e5+2;

int boys[MAXN], girls[MAXN];
ii pairs[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int a,b,k; cin >> a >> b >> k;
        forn(j,k) {int x; cin >> x; x--; pairs[j].fst = x; boys[x]++;}
        forn(j,k) {int x; cin >> x; x--; pairs[j].snd = x; girls[x]++;}

        ll rta = 0;
        int auxK = k;
        forn(j,k) {rta += auxK-boys[pairs[j].fst]-girls[pairs[j].snd]+1; boys[pairs[j].fst]--, girls[pairs[j].snd]--, auxK--;}

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
