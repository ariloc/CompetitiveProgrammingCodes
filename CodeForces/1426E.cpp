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

const int INF = 1e9+5;

int main() {
    FAST_IO;

    int n; cin >> n;
    vi a(3), b(3);
    forn(i,3) cin >> a[i];
    forn(i,3) cin >> b[i];

    vector<ii> comb;
    forn(i,3) comb.pb({i,i});
    comb.pb({1,0}); comb.pb({2,1}); comb.pb({0,2});
    sort(all(comb));

    int rta = INF;
    do {
        vi tA = a, tB = b;
        forn(i,comb.size()) {
            int mini = min(tA[comb[i].fst],tB[comb[i].snd]);
            tA[comb[i].fst] -= mini; tB[comb[i].snd] -= mini;
            rta = min(rta,tA[0]+tA[1]+tA[2]);
        }
    } while(next_permutation(all(comb)));

    cout << rta << ' ' << min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
