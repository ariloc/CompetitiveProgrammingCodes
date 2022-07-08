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

const int MAXN = 1e5+5;

vi G[MAXN];
int P[MAXN], dep[MAXN];
int n,m,k;

vi rta;
void dfs (int st, int lvl = 0)  {
    dep[st] = lvl;

    for (auto &i : G[st]) {
        if (rta.empty() && dep[i] != -1 && dep[st]-dep[i]+1 >= k+1) {
            int aux = st;
            while (aux != P[i]) {
                rta.pb(aux);
                aux = P[aux];
            }
        }
        if (dep[i] == -1) {
            P[i] = st;
            dfs(i, lvl+1);
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&m,&k);

    forn(i,n) P[i] = dep[i] = -1;

    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(0);

    printf("%d\n",(int)rta.size());
    for (auto &i : rta)
        printf("%d ",i+1);

    return 0;
}
