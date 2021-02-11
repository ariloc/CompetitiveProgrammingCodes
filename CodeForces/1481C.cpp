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
const int INF = 1e9+5;

int a[MAXN], b[MAXN], c[MAXN], rta[MAXN];
set<ii> need;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        need.clear(); // reset
        int n,m; cin >> n >> m;

        forn(j,n) cin >> a[j];
        forn(j,n) cin >> b[j];
        forn(j,m) cin >> c[j];

        int ind = -1;
        forn(j,n) if (b[j] == c[m-1]) {ind = j; if (a[j] != b[j]) break;}
        if (ind == -1) {cout << "NO\n"; continue;}
        a[ind] = b[ind]; rta[m-1] = ind;

        forn(j,n) if (a[j] != b[j]) need.insert({b[j],j});

        forn(j,m-1) {
            auto it = need.lower_bound({c[j],-INF});
            if (it == need.end() || (*it).fst != c[j]) rta[j] = ind;
            else {
                int pos = (*it).snd;
                a[pos] = c[j];
                rta[j] = pos;
                need.erase(it);
            }
        }
        bool posib = true;
        forn(j,n) if (a[j] != b[j]) {posib = false; break;}

        if (!posib) cout << "NO\n";
        else {
            cout << "YES\n";
            forn(j,m) cout << rta[j]+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
