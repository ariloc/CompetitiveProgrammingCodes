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
const int INF = 1e9+2;

vi G[MAXN];
bitset<MAXN> done;

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    forn (i,n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    vi Q[2];
    int lvls = 0;
    forn (i,n) if (G[i].size() == 1) {done[i] = true; Q[0].pb(i);}

    int ind = 0, choose = -1;
    while (not Q[0].empty() or not Q[1].empty()) {
        lvls++;
        while (not Q[ind].empty()) {
            auto e = Q[ind].back(); Q[ind].pop_back();

            for (auto &i : G[e]) {
                if (done[i]) continue;
                done[i] = true;
                Q[(ind+1)%2].pb(i);
            }
        }
        ind++; ind %= 2;
        if (Q[ind].size() == 1) choose = Q[ind].back();
    }
    if (choose == -1) {cout << "No"; return 0;}

    forn (i,n) if (G[i].size() < 3 and G[i].size() != 1) {cout << "No"; return 0;}
    if (lvls-1 != k) cout << "No";
    else cout << "Yes";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!