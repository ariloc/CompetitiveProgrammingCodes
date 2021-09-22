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

const int MAXN = 101;

bitset<MAXN> col;
bitset<MAXN> done;
vector<ii> G[MAXN];

bool bfs (int st) {
    queue<int> Q;
    col[st] = false; done[st] = true;
    Q.push(st);

    while (not Q.empty()) {
        int e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            if (done[i.fst]) // chequeo si hay conflictos en decisiones que tengo que hacer.
                {if ((col[i.fst]^col[e]) != i.snd) return false; continue;}
            done[i.fst] = true;
            col[i.fst] = col[e]^i.snd;
            // dada la arista, según la cantidad que veces que pinté, hago lo necesario en este vértice
            Q.push(i.fst);
        }
    }
    return true;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b,st; cin >> a >> b >> st; a--; b--;
        G[a].push_back({b, 1^st});
        G[b].push_back({a, 1^st});
        // si esta asfaltado, no debería pintar el nodo, de lo contrario si
        // la operación xor me resuelve la cantidad de operaciones que debo hacer
    }

    forn (i,n) if (!done[i]) if(!bfs(i)) {cout << "Impossible"; return 0;}
    // si el bfs tiró falso, signfica que hay conflicto y no se puede

    vi rta;
    forn (i,n) if (col[i]) rta.pb(i+1); // la cantidad de pasadas se reduce a 0 o 1
    cout << rta.size() << '\n'; for (auto &i : rta) cout << i << ' '; // output

    return 0;
}