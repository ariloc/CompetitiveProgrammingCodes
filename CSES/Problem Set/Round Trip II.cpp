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

void fastscan (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if (c<'0'||c>'9') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vi G[MAXN];
int tin[MAXN], actT = 1;
bitset<MAXN> done;

vi path,rta;
void dfs(int st) {
    done[st] = true;
    tin[st] = actT++; path.pb(st);

    for (auto &i : G[st])
        if (!done[i]) dfs(i);
        else if (rta.empty() && tin[i])
            forsn(j,tin[i]-1,path.size()) rta.pb(path[j]);

    path.pop_back();
    tin[st] = 0; actT--;
}

int main() {
    int n,m; fastscan(n); fastscan(m);

    forn(i,m) {
        int u,v; fastscan(u); fastscan(v); u--; v--;
        G[u].pb(v);
    }

    forn(i,n) if (!done[i]) {
        dfs(i);
        if (!rta.empty()) {
            printf("%d\n",(int)rta.size()+1);
            for(auto &i : rta) printf("%d ",i+1);
            printf("%d",rta[0]+1); return 0;
        }
    }
    printf("IMPOSSIBLE");

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
