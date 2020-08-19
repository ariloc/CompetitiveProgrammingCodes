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

const int MAXN = 1e5+5;

int peop[MAXN],happy[MAXN],children[MAXN],goodM[MAXN];
bool done[MAXN],done2[MAXN];
vi G[MAXN];
bool posib = true;

int dfs(int st) {
    done[st] = true;

    int child = 0;
    for (auto &i : G[st])
        if (!done[i]) child += dfs(i);

    children[st] = child+peop[st];
    goodM[st] = children[st]-((children[st]-happy[st])/2);
    return children[st];
}

int dfs2(int st, int parent) {
    done2[st] = true;

    int myGood = 0;
    for (auto &i : G[st])
        if (!done2[i]) myGood += dfs2(i,st);

    if (abs(happy[st]) > children[st]) posib = false;
    if ((abs(happy[st]) % 2) != (abs(children[st]) % 2)) posib = false;
    if (parent != -1 and (goodM[st] < 0 or goodM[st] > goodM[parent])) posib = false;
    if (myGood > goodM[st]) posib = false;

    return goodM[st];
}


int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        int n,m; cin >> n >> m;

        posib = true;
        forn(j,n) {children[j] = goodM[j] = 0; done[j] = done2[j] = false; G[j].clear();}
        forn(j,n) cin >> peop[j];
        forn(j,n) cin >> happy[j];

        forn(j,n-1) {
            int a,b; cin >> a >> b; a--; b--;
            G[a].pb(b);
            G[b].pb(a);
        }

        dfs(0); // cuento hijos
        if (abs(happy[0]) > m) posib = false; // si ya no da del principio
        dfs2(0,-1);

        if (posib) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!