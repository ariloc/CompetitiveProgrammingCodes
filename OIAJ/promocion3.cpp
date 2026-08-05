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

vector<ii> prices[MAXN];
vi times[MAXN];
int fb[MAXN];
int n,c,q;
int timer = 1;

void inicializar(vector<int> &P, int C, int Q) {
    c = C, q = Q, n = sz(P);
    forn(i,n) prices[i].pb({0, P[i]}), times[i].pb(0);
    fill(fb,fb+c,-1);
}

int comprar(int c, int p) {
    if (fb[c] == -1) {
        fb[c] = timer++;
        return prices[p].back().snd;
    }
    int idx2 = upper_bound(all(times[p]),fb[c])-times[p].begin()-1;
    int idx = lower_bound(all(prices[p]),(ii){times[p][idx2], -INF})-prices[p].begin();
    return prices[p][idx].snd;
}

void cambiar(int p, int v) {
    while (!prices[p].empty() && v <= prices[p].back().snd)
        prices[p].pop_back();
    times[p].pb(timer);
    prices[p].pb({timer++, v});
}
