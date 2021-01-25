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

const int MAXN = 1e6+5;

bitset<MAXN> doneR, doneC;

int main() {
    FAST_IO;

    freopen("adjustment.in","r",stdin);
    freopen("adjustment.out","w",stdout);

    int n,q; cin >> n >> q;

    ll cntC = 0, cntR = 0, sR = 0, sC = 0;
    forn(i,q) {
        char c; ll v; cin >> c >> v;
        if (c == 'R') {
            if (!doneR[v]) {
                cout << (n+v)*(n+v+1)/2 - v*(v+1)/2 - sC - cntC * (v-1) << '\n';
                doneR[v] = true, sR += v+1, cntR++;
            }
            else cout << "0\n";
        }
        else {
            if (!doneC[v]) {
                cout << (n+v)*(n+v+1)/2 - v*(v+1)/2 - sR - cntR * (v-1) << '\n';
                doneC[v] = true, sC += v+1, cntC++;
            }
            else cout << "0\n";
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
