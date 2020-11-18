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

const int MAXN = 102;

int a[MAXN],b[MAXN],c[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int n; cin >> n;
        forn(j,n) cin >> a[j];
        forn(j,n) cin >> b[j];
        forn(j,n) cin >> c[j];
        vi r(MAXN,0);
        r[0] = a[0]; // init
        forsn(j,1,n) {
            if (a[j] != r[j-1] && a[j] != r[(j+1)%n]) r[j] = a[j];
            else if (b[j] != r[j-1] && b[j] != r[(j+1)%n]) r[j] = b[j];
            else r[j] = c[j];
        }
        forn(j,n) cout << r[j] << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
