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

int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        forn(j,n) cin >> arr[j];
        int pref = -1;
        dforn(j,n) if (arr[j] != j+1) {pref = j+1; break;}
        long double act = 0;
        forn(j,m) {
            int r; long double p; cin >> r >> p;
            if (r >= pref) {act = (act+p)-(act*p);}
        }
        cout << max(act,(long double)(pref == -1)) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
