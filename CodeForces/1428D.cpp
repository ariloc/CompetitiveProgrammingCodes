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

const int MAXN = 2e5+2;

int arr[MAXN];
set<ii> ord;
vector<ii> rta;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) {int x; cin >> x; arr[j] = x; if (x) ord.insert({x,j});}

    int lvl = n;
    dforn(j,n) {
        if (arr[j] == 1) {
            ord.erase({arr[j],j});
            rta.pb({lvl,j+1});

            int indLook = j;
            auto it = ord.lower_bound({2,indLook}), it2 = ord.lower_bound({3,indLook});
            if (it2 != ord.begin() && it != ord.begin() && (*prev(it2)).snd > (*prev(it)).snd) goto JMP_THREE;

            if (it != ord.begin() && (*prev(it)).fst == 2) {
                indLook = (*prev(it)).snd; ord.erase(prev(it));
                rta.pb({lvl,indLook+1});
            }
            JMP_THREE:
            lvl--;

            while (it2 != ord.begin() && (*prev(it2)).fst == 3) {
                rta.pb({lvl,indLook+1}); indLook = (*prev(it2)).snd;
                rta.pb({lvl,indLook+1});
                ord.erase(prev(it2)); lvl--;
            }
        }
    }

    if (!ord.empty() || lvl+1 < 1) cout << -1;
    else {
        cout << rta.size() << '\n';
        for (auto &i : rta) cout << i.fst << ' ' << i.snd << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
