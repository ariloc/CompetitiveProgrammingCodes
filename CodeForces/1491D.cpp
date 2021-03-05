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

const int MAXB = 31;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int a,b; cin >> a >> b;
        int idx = 0; bool posib = true;
        forn(i,MAXB) {
            bool done = false;
            if (b&(1<<i)) {
                while (!done && idx <= i) {if (a&(1<<idx)) done = true; idx++;}
                if (!done) {posib = false; break;}
            }
        }
        int v1 = __builtin_clz(a), v2 = __builtin_clz(b);
        if (v1 < v2) posib = false;

        dforn(i,MAXB) {
            if (a&(1<<i)) {
                if (!(b&(1<<i))) posib = false;
            } else if (b&(1<<i)) break;
        }
        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
