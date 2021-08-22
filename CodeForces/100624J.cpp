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

const int MAXN = 1e5+5;

int col[MAXN], inDegree[MAXN], inDegree2[MAXN];
int n,m;
vi G[MAXN];

ll topSort (bool me, int inDeg[]) {
    queue<int> Q[2]; // hago todo lo de uno y todo lo de otro lo más que pueda antes de pasar
    bool look = me;
    forn (i,n) if (!inDeg[i]) Q[col[i]-1].push(i);

    ll ch = 0;
    while (!Q[0].empty() or !Q[1].empty()) {
        while (!Q[look].empty()) {
            auto e = Q[look].front(); Q[look].pop();
            for (auto &i : G[e]) if (!(--inDeg[i])) Q[col[i]-1].push(i);
        }
        if(!Q[0].empty() or !Q[1].empty()) ch++;
        look = !look;
    }

    return ch;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        cin >> n >> m;
        forn (j,n) {inDegree[j] = inDegree2[j] = 0; G[j].clear();}// reset

        forn(j,n) cin >> col[j];
        forn(j,m) {
            int a,b; cin >> a >> b; a--; b--;
            inDegree[b]++;
            inDegree2[b]++;
            G[a].pb(b);
        }

        cout << min(topSort(0,inDegree2),topSort(1,inDegree)) << '\n'; // pruebo empezar en ambos
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!