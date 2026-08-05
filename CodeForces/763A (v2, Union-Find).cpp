#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN=1e5+5;

const ll INF=10000000007;

int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x,int y){
    x=uf_find(x);y=uf_find(y);
    if(x==y)return false;
    if(uf[x]>uf[y])swap(x,y);
    uf[x]+=uf[y];uf[y]=x;
    return true;
}

vi G[MAXN];
int col[MAXN];

int main(){
    FAST_IO;

    int n; cin >> n;

    forn(i,n-1) {
        int u,v; cin >> u >> v;
        --u, --v;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,n) cin >> col[i];

    uf_init();

    forn(i,n) for (auto &j : G[i]) if (col[i] == col[j]) uf_join(i,j);

    set<int> allcomp;
    forn(i,n) allcomp.insert(uf_find(i));

    int tam = sz(allcomp);

    int rta = -1;
    forn(i,n) {
        set<int> seen;
        for (auto &j : G[i]) seen.insert(uf_find(j));
        seen.insert(uf_find(i));

        if (sz(seen) == tam) {
            rta = i;
            break;
        }
    }

    if (rta == -1) cout << "NO\n";
    else cout << "YES\n" << rta+1 << '\n';

    return 0;
}
