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

const int MAXN = 1005;

ii lst[MAXN], edges[MAXN];
int ind = 0;
set<int> avail;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) cin >> lst[i].fst >> lst[i].snd, lst[i].fst--, lst[i].snd--;

    sort(lst,lst+n-1);

    forn(i,n-1) if (lst[i].snd != n-1) return cout << "NO", 0; // check

    forn(i,n-1) avail.insert(i); // el último descartadísimo
    forn(i,n-1) if (avail.count(lst[i].fst)) avail.erase(lst[i].fst);

    int cnt = 1; lst[n-1].fst = n-1; // dummy conector final
    forsn(i,1,n) { // voy siempre de los más chicos a los más grandes
        if (lst[i].fst != lst[i-1].fst) {
            vi interm = {lst[i].fst};
            while ((--cnt) > 0) { // cnt-1 vueltas
                if (avail.empty() || *avail.begin() < lst[i-1].fst) {
                    int grab = *avail.begin(); // lo agarro a el más chico
                    interm.pb(grab); // lo pongo en medio
                    avail.erase(avail.begin()); // descarto porque lo usé
                }
                else return cout << "NO", 0; // los del medio tienen que ser más chicos
            }
            interm.pb(lst[i-1].fst);
            forn(j,interm.size()-1) edges[ind++] = {interm[j],interm[j+1]};
        }
        cnt++;
    }

    cout << "YES\n";
    forn(i,ind) cout << edges[i].fst+1 << ' ' << edges[i].snd+1 << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!