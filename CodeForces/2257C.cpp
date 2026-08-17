#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const INF = 2e9;

int dep[MAXN];
vi G[MAXN];

void dfs(int st, int l = 0) {
    dep[st] = l;
    for (auto &i : G[st])
        dfs(i,l+1);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) G[i].clear(), dep[i] = 0;
        forn(i,n-1) {
            int x; cin >> x; --x;
            G[x].pb(i+1);
        }
        int m; cin >> m;
        vi rta;
        forn(i,m) {
            int x; cin >> x; --x;
            if (x) rta.pb(x);
        }
        dfs(0);

        int mindep = INF;
        vi rta2;
        if (sz(rta) == m) {
            for (auto &i : rta) mindep = min(mindep,dep[i]);
            int idx = 0;
            forn(i,sz(rta)) if (dep[rta[i]] == mindep) idx = i;
            forn(i,sz(rta)) if (i != idx) rta2.pb(rta[i]);
            swap(rta,rta2);
        }

        cout << m-1 << ' ';
        for (auto &i : rta) cout << i+1 << ' ';
        cout << '\n';
    }

    return 0;
}
