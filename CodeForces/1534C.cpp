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

const int MAXN = 4e5+5;
const int MOD = 1e9+7;

int a[MAXN][2];
int pos[MAXN][2];
bitset<MAXN> done;

int binExp (int b, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)b)%MOD;
        b = (b*(ll)b)%MOD; k >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) done[i] = 0;
        forn(i,n) cin >> a[i][0], pos[a[i][0]][0] = i;
        forn(i,n) cin >> a[i][1], pos[a[i][1]][1] = i;

        int cntCmp = 0;
        forn(i,n) {
            if (!done[i]) {
                int nxt = pos[a[i][1]][0];
                done[i] = true;
                while (nxt != i) {
                    done[nxt] = true;
                    nxt = pos[a[nxt][1]][0];
                }
                cntCmp++;
            }
        }

        cout << binExp(2,cntCmp) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!