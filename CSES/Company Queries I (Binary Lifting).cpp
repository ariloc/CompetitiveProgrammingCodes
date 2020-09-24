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

const int MAXN = 2e5+5;
const int MAXK = log2(MAXN)+2;

int P[MAXN][MAXK];

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,n-1) cin >> P[i+2][0];

    forsn(i,1,MAXK) forsn(j,1,n+1) P[j][i] = P[P[j][i-1]][i-1];

    forn(i,q) {
        int x,k; cin >> x >> k;
        forn(i,MAXK) {
            if (k&(1<<i)) x = P[x][i];
        }
        cout << (x?x:-1) << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
