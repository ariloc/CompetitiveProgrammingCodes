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
const int INF = 1e9+5;

int grid[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        forn(j,n) forn(k,m) cin >> grid[j][k];
        ll c = 0;
        forn(j,(n+1)/2) forn(k,(m+1)/2) {
            set<ii> ids {{j,k},{n-j-1,k},{n-j-1,m-k-1},{j,m-k-1}};
            vi num; for (auto &l : ids) num.pb(grid[l.fst][l.snd]);
            sort(all(num));
            int med = num[((int)num.size()-1)/2];
            forn(l,num.size()) c += abs(num[l]-med);
        }
        cout << c << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
