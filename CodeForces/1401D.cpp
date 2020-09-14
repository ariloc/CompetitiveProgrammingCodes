
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

const int MAXN = 1e5+5;
const ll MOD = 1e9+7;

struct edges {
    int v,id;
};

vector<edges> G[MAXN];
pair<ll,int> passMe[MAXN];
bitset<MAXN> done;
int n;

int dfs(int st) {
    done[st] = true;
    vector<edges> ramas; int s = 0;
    for (auto &i : G[st]) {
        if(done[i.v]) continue;
        int v = dfs(i.v);
        s += v; ramas.pb({v,i.id});
    }
    for(auto &i : ramas) {passMe[i.id].fst += (ll)(n-i.v)*i.v;}
    return s+1; // hijos y yo
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        cin >> n;
        done.reset();
        forn(j,MAXN) {G[j].clear(); passMe[j] = {0,j};}
        forn(j,n-1) {
            int a,b; cin >> a >> b; a--; b--;
            G[a].pb({b,j}); G[b].pb({a,j});
        }
        int f; cin >> f;
        priority_queue<int> fact;
        forn(j,f) {
            int x; cin >> x;
            fact.push(x);
        }

        // combino factores
        ll big = fact.top(); fact.pop();
        int cnt = 0;
        while (f-cnt > (n-1)) {
            cnt++;
            big = (big*fact.top())%MOD;
            fact.pop();
        }

        while ((int)fact.size() < n-1) fact.push(1);

        dfs(0);
        sort(passMe,passMe+n-1,greater<pair<ll,int>>());
        ll rta = 0;
        forn(j,n-1) {
            //cerr << passMe[j].snd << ' ' << passMe[j].fst << ' '  << fact[j] << endl;
            ll factB = (!j ? big : fact.top());
            if (j) fact.pop();
            rta = (rta+factB*(passMe[j].fst%MOD))%MOD;
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
