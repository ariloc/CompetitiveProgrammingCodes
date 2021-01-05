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

const int MAXN = 1e5+2;

int degree[MAXN], vert[MAXN];
ii order[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; ll s = 0; cin >> n;

        forn(j,n) degree[j] = 0; // reset

        forn(j,n) {cin >> vert[j]; s += vert[j];}
        forn(j,n-1) {
            int u,v; cin >> u >> v; u--; v--;
            degree[u]++; degree[v]++;
        }
        forn(j,n) order[j] = {vert[j],degree[j]-1};

        sort(order,order+n);

        cout << s << ' ';
        int cnt = 1;
        dforn(j,n) {
            if (order[j].snd) {
                cnt++;
                if (cnt >= n) break;
                s += order[j].fst; cout << s << ' ';
                order[j].snd--; j++; continue;
            }
        }
        while ((++cnt) < n) cout << s << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
;
