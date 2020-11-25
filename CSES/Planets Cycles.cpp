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

const int MAXN = 2e5+2;

void fastscan(int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if(c<'0'||c>'9') c=getchar_unlocked();
    for(; c>='0'&&c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vi GB[MAXN];
int G[MAXN], tin[MAXN], cycleSz[MAXN], rta[MAXN], t = 1;
bitset<MAXN> passed,done;

vi path;
void findCycle(int st) {
    tin[st] = t++;
    path.pb(st);

    int i = G[st];
    if (!tin[i]) findCycle(i);
    else if (!passed[i]) {
        vi tmp;
        while (!path.empty()) {
            auto e = path.back(); path.pop_back();
            tmp.pb(e); if (e == i) break;
        }
        dforn(j,tmp.size()) cycleSz[tmp[j]] = (int)tmp.size();
    }

    if (!path.empty() && path.back() == st) path.pop_back(); // finish emptying
    passed[st] = true;
}

void dfs(int st, int lvl, int thisSz) {
    done[st] = true;
    rta[st] = lvl+thisSz;

    for (auto &i : GB[st])
        if (!done[i] && cycleSz[i] == -1) dfs(i,lvl+1,thisSz); // no veré atrás en el ciclo
}

int main() {
    forn(i,MAXN) cycleSz[i] = -1;
    int n; fastscan(n);

    forn(i,n) {
        int x; fastscan(x); x--;
        G[i] = x;
        GB[x].pb(i);
    }

    forn(i,n) if (!passed[i]) findCycle(i);
    forn(i,n) if (!done[i] && cycleSz[i] != -1) dfs(i,0,cycleSz[i]);

    forn(i,n) printf("%d ",rta[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
