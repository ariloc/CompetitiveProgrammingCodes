#include <bits/stdc++.h>

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

vi G[MAXN];
bitset<MAXN> done;

void bfs (int st) {
    queue<int> Q;
    done[st] = true;
    Q.push(st);

    while (not Q.empty()) {
        int e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            if (done[i]) continue;
            done[i] = true;
            Q.push(i);
        }
    }
}

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    forn (i,k) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    /* Pensando:
    Agarramos una persona cualquiera que come un snack de cierto gusto. Seguro esta comerá de sus
    dos colores favoritos por dato. Sabiendo esto, me fijo todos aquellos que luego vendran dsps
    de esa persona y solo comerán su otro color favorito. Así hasta que no puedo más.
    Entonces queda como que por persona resulta comen: 2 1 1 1 1...
    De esta forma, la cantidad que personas satisfechas de todo esto resulta el total de caramelos
    menos cada una de estas cadenas, pues restaría las veces que uno llegó a comer 2.
    Así sabiendo los satisfechos, sé los tristes.
    */

    int cnt = 0;
    forn (i,n) if (!done[i]) {cnt++; bfs(i);}

    cout << k - (n - cnt);

    return 0;
}