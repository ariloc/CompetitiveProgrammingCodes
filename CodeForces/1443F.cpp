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
const int MOD = 998244353;

int ord[MAXN],pos[MAXN];
bitset<MAXN> dontTouch;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,k; cin >> n >> k;
        forn(j,n) {int x; cin >> x; pos[x] = j;}
        forn(j,k) {int x; cin >> x; dontTouch[pos[x]] = true; ord[j] = pos[x];}

        int rta = 1;
        forn(j,k) {
            int cnt = (ord[j]+1 < n ? !dontTouch[ord[j]+1] : 0)+
                      (ord[j]-1 >= 0 ? !dontTouch[ord[j]-1] : 0);
            rta = (rta*(ll)cnt)%MOD;
            dontTouch[ord[j]] = false;
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
