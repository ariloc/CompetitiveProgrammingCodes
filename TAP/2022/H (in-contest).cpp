
#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+5;

vi G[MAXN];
bitset<MAXN> matched;
int tin[MAXN], actT = 0, cols = 0;
int cmp[MAXN], outDegCmp[MAXN], inDegCmp[MAXN];

vi pila;
int tarjan (int st) {
    pila.pb(st);
    tin[st] = actT++;

    int mini = actT-1;
    for (auto &i : G[st]) {
        if (tin[i] == -1) mini = min(mini, tarjan(i));
        if (!matched[i]) mini = min(mini,tin[i]);
    }

    if (mini >= tin[st]) {
        while (!pila.empty()) {
            auto e = pila.back(); pila.pop_back();
            cmp[e] = cols; matched[e] = true;
            if (e == st) {
                cols++;
                break;
            }
        }
    }

    return mini;
}

int main(){
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) tin[i] = -1;
    
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v);
    }

    forn(i,n) if (tin[i] == -1)
        tarjan(i);

    if (cols <= 1) {
        cout << 0;
        return 0;
    }

    forn(i,n) {
        for (auto &j : G[i])
            if (cmp[i] != cmp[j])
                outDegCmp[cmp[i]]++, inDegCmp[cmp[j]]++;
    }

    int aux1 = 0, aux2 = 0;
    forn(i,cols) {
        aux1 += (outDegCmp[i] == 0);
        aux2 += (inDegCmp[i] == 0);
    }

    cout << max(aux1,aux2);

    return 0;
}
