#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef long double ld;

const int MAXN = 2e5+5;

vi G[MAXN];
ll maxToHere[MAXN];
int deg[MAXN];
int scores[MAXN];

pair<ll,ll> dfs (int st, int cant) {
    if (!deg[st]) return {scores[st] * (ll)cant, scores[st]};
    
    int each = cant / deg[st];
    int rest = cant % deg[st];

    ll ret = scores[st] * (ll)cant;
    vector<ll> maxes;
    for (auto &i : G[st]) {
        pair<ll,ll> aux = dfs(i,each);
        ret += aux.fst; 
        maxes.pb(aux.snd);
    }

    sort(all(maxes));
    while (rest--) ret += maxes.back(), maxes.pop_back();

    return {ret, maxes.back() + scores[st]};
}

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n,k; scanf("%d %d",&n,&k);

        forn(i,n) deg[i] = 0, G[i].clear();

        forn(i,n-1) {
            int x; scanf("%d",&x); x--;
            G[x].pb(i+1);
            deg[x]++;
        }

        forn(i,n) scanf("%d",&scores[i]);

        printf("%lld\n",dfs(0,k).fst);
    }

    return 0;
}
