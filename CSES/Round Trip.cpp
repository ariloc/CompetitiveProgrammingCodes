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

vi G[MAXN];
int done[MAXN];
int fnd = -1; vi path;

void dfs (int st, int lvl, vi &actPath) {
    done[st] = ++lvl;
    actPath.pb(st);

    for (auto &i : G[st]) {
        if (done[i]) {
            if (fnd == -1 and lvl-done[i] >= 2)
                {fnd = i; path = actPath;}
            continue;
        }
        dfs(i,lvl,actPath);
    }
    actPath.pop_back();
}

int main() {
    int n,m; scanf("%d %d",&n,&m);

    forn(i,m) {
        int a,b; scanf("%d %d",&a,&b); a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    forn(i,n) {
        if (fnd != -1) break;
        if (!done[i]) {vi tmp; dfs(i,0,tmp);}
    }

    if (fnd == -1) printf("IMPOSSIBLE");
    else {
        vi prt; bool yes = false;
        for (auto &i : path) {if (i == fnd) yes = true; if (yes) prt.pb(i);} prt.pb(fnd);
        printf("%d\n",(int)prt.size());
        for (auto &i : prt) printf("%d ",i+1);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
