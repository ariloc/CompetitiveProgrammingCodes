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

struct nodo {
    int v,h; // menor es más bajo -> implica primero pasa agua
};

int cap[MAXN];
vector<nodo> G[MAXN];
bitset<MAXN> done;
vector<ii> D;

int used = 0; int filled = 0;
void dfs(int st) {
    done[st] = true;

    int accum = 0;
    for (auto &i : G[st])
        if (!done[i.v]) {
            int calc = cap[st]-i.h-accum;
            filled += calc; accum += calc;
            D.push_back({filled,++used});
            dfs(i.v);
        }

    if (!st) D.push_back({filled,++used});
    filled += cap[st]-accum;
}

int main() {
    FAST_IO;

    int T; cin >> T;
    forn (i,T) cin >> cap[i];
    forn (i,T-1) {
        int T1,D1,T2;
        cin >> T1 >> D1 >> T2; T1--; T2--;
        G[T1].push_back({T2,D1});
    }

    forn (i,T) sort(all(G[i]),[](const nodo &a, const nodo &b){return a.h > b.h;});
    dfs(0);
    sort(all(D));

    int Q; cin >> Q;
    forn (i,Q) {
        int x; cin >> x;
        auto it = lower_bound(all(D),x,[](const ii &a, const int &b){return a.fst < b;});
        if (it == D.end()) cout << D.back().snd << ' ';
        else cout << D[it-D.begin()].snd << ' ';
    }

    return 0;
}
