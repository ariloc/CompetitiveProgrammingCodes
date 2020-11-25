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

vi G[MAXN]; set<int> col[2];
bitset<MAXN> done;
bool posib = true;

void dfs (int st, bool comp) {
    col[comp].insert(st);
    done[st] = true;

    for (auto &i : G[st]) {
        int tg = abs(i);
        if (done[tg]) {
            bool cond = col[comp].count(tg);
            if ((i < 0 && cond) || (i >= 0 && !cond)) posib = false;
            continue;
        }
        dfs(tg,comp^(i<0));
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        cerr << "OKK" <<endl;
        int n; cin >> n;
        forn(j,n+1) G[j].clear(); done.reset(); posib = true;
        map<int,vector<pair<int,bool>>> cols;
        forn(k,2) {
            forn(j,n) {
                int x; cin >> x;
                if (posib) {
                    if (cols.count(x)) {
                        if ((int)cols[x].size()+1 > 2) {posib = false; continue;}
                        auto ot = cols[x][0];
                        if (ot.snd == k) { // XOR edges
                            G[j+1].pb(-ot.fst-1);
                            G[ot.fst+1].pb(-j-1);
                        } else { // XNOR edges
                            G[j+1].pb(ot.fst+1);
                            G[ot.fst+1].pb(j+1);
                        }
                    }
                    cols[x].pb({j,k});
                }
            }
        }

        vi rta;
        forn(j,n) if (!done[j]) {
            col[0].clear(); col[1].clear();
            dfs(j,0);
            int ind = ((int)col[1].size() < (int)col[0].size());
            for (auto &k : col[ind]) rta.pb(k);
        }
        if (!posib) {cout << "-1\n"; continue;}
        cout << rta.size() << '\n';
        for (auto &j : rta) cout << j << ' '; cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
