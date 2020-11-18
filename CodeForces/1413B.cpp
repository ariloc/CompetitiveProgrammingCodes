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

const int MAXN = 500*500+10;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        vi posib(n*m+5,-1);
        vector<vi> cols(m,vi(n));
        vi ord(m,-1);

        forn(j,n) forn(k,m) {int x; cin >> x; posib[x] = k;}
        forn(j,m) forn(k,n) {int x; cin >> x; cols[j][k] = x; ord[posib[x]] = j;}
        forn(i,n) {
            forn(j,m) cout << cols[ord[j]][i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
