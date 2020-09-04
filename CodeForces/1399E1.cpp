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

const int INF = 1e9+5;
const int MAXN = 1e5+5;

vi G[MAXN];
int children[MAXN], tin[MAXN], actT = 0;
bool done[MAXN];

int dfs (int st) {
    done[st] = true;
    tin[st] = actT++;
    int sum = 0;
    for (auto &i : G[st]) if (!done[i]) sum += dfs(i);
    sum += (!sum);
    return children[st] = sum;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; ll S; cin >> n >> S;
        forn(j,n) {G[j].clear(); done[j] = 0;} actT = 0;
        vector<pair<ii,int>> myEdges;
        forn(j,n-1) {
            int a,b,w; cin >> a >> b >> w; a--; b--;
            G[a].pb(b); G[b].pb(a);
            myEdges.pb({{a,b},w});
        }
        dfs(0);

        auto comp = [](const ii &a, const ii &b)
            {return (((ll)a.fst*a.snd)-(ll(a.fst/2LL)*a.snd)) < (((ll)b.fst*b.snd)-(ll(b.fst/2LL)*b.snd)) ;}; // aquel que más conviene
        priority_queue<ii, vector<ii>, decltype(comp)> Q(comp);
        ll sum = 0;
        for (auto &o : myEdges) {
            if (tin[o.fst.fst] > tin[o.fst.snd]) swap(o.fst.fst,o.fst.snd);
            Q.push({o.snd,children[o.fst.snd]}); // peso e hijos
            sum += (ll)children[o.fst.snd]*o.snd; // sumo
        }

        ll moves = 0;
        while (sum > S) {
                //cerr << Q.top() << ' ';
            auto e = Q.top();
            ll v = Q.top().fst/2LL;
            sum -= ((e.fst*(ll)e.snd)-(v*e.snd)); Q.pop(); Q.push({v,e.snd}); moves++;
        //cerr << sum << ' ' << e << ' ' << i << "!!" << endl;
        }
        cout << moves << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
