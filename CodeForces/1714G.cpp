#include <algorithm>
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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 2e5+5;

struct edge {
    int v,a,b;
};

vector<edge> G[MAXN];
int rta[MAXN];

vector<ll> pila;
void dfs (int st, ll acc) {
    int ind = upper_bound(all(pila), acc)-pila.begin()-1;
    rta[st] = ind;

    for (auto &i : G[st]) {
        pila.pb(pila.back() + i.b);
        dfs(i.v, acc + i.a);
    }

    pila.pop_back();
}

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n) G[i].clear();

        forn(i,n-1) {
            int p,a,b; scanf("%d %d %d",&p,&a,&b); p--;
            G[p].pb({i+1,a,b});
        }
        
        pila.clear(); pila = {0};
        dfs(0,0);

        forsn(i,1,n) printf("%d ",rta[i]);
        printf("\n");
    }

    return 0;
}
