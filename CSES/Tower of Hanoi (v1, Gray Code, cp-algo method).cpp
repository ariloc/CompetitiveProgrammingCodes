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

const int indOd[] = {2,0,1}; // indice goto
const int indEv[] = {1,2,0};
const int INF = 1e9;
const int MAXN = 20;

int pos[MAXN]; // 0,1,2 --> left, middle, right
vi towers[3]; // tops of towers

int main() {
    FAST_IO;

    int n; cin >> n;
    vector<ii> mov;

    dforn(j,n) towers[0].pb(j);

    int prv = 0;
    forsn(i,1,(1<<n)) {
        int Gc = i^(i>>1);
        forn(j,n) if ((prv&(1<<j)) != (Gc&(1<<j))) {
            if (!j) {
                if (n&1) {
                    mov.pb({pos[0]+1,indOd[pos[0]]+1});
                    towers[pos[0]].pop_back(); towers[indOd[pos[0]]].pb(0);
                    pos[0] = indOd[pos[0]];
                }
                else {
                    mov.pb({pos[0]+1,indEv[pos[0]]+1});
                    towers[pos[0]].pop_back(); towers[indEv[pos[0]]].pb(0);
                    pos[0] = indEv[pos[0]];
                }
            }
            else {
                towers[pos[j]].pop_back();
                forn(k,3) if (k != pos[j] && (towers[k].empty() || towers[k].back() > j)) {
                    towers[k].pb(j);
                    mov.pb({pos[j]+1,k+1});
                    pos[j] = k;
                    break;
                }
            }
            break;
        }
        prv = Gc;
    }

    cout << mov.size() << '\n';
    for (auto &i : mov) cout << i.fst << ' ' << i.snd << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
