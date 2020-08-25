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

const int MAXN = 2e5+5;
const int MAXT = 4e5+5; // maximo tour
const int K = (int)log2(MAXT)+1;

vi G[MAXN];
int L[MAXT],E[MAXT],H[MAXN],ind = 0;
ii SpT[MAXT][K];
bitset<MAXN> done1,done2;
int LOG[MAXT+1],pass[MAXN],del[MAXN];

void initLog() {
    LOG[1] = 0;
    forsn(i,2,MAXT+1) LOG[i] = LOG[i/2]+1;
}

void tour (int st, int lvl) {
    done1[st] = true;
    H[st] = ind;
    E[ind] = st;
    L[ind++] = lvl;

    for (auto &i : G[st]) {
        if (done1[i]) continue;
        tour(i,lvl+1);
        E[ind] = st;
        L[ind++] = lvl;
    }
}

void fillSpT (int N) {
    forn(i,N) SpT[i][0] = {L[i],i};

    forsn(j,1,K+1) for(int i = 0; i+(1<<j) <= N; i++)
        SpT[i][j] = min(SpT[i][j-1],SpT[i+(1<<(j-1))][j-1]);
}

int query(int l, int r) {
    int j = LOG[r-l+1];
    return min(SpT[l][j],SpT[r-(1<<j)+1][j]).snd;
}

int dfs(int st) {
    done2[st] = true;
    for (auto &i : G[st]) if (!done2[i]) pass[st] += dfs(i);
    return pass[st]+del[st];
}

int main() {
    initLog();
    int n,m; scanf("%d %d",&n,&m);

    forn(i,n-1) {
        int a,b; scanf("%d %d",&a,&b); a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    tour(0,0);
    fillSpT(ind); // ind, todo el Euler Tour

    forn(i,m) {
        int a,b; scanf("%d %d",&a,&b); a--; b--;

        int x = H[a], y = H[b];
        if (x > y) swap(x,y);
        int v = E[query(x,y)];

        if (a == b) {pass[a]++; del[v]--;}
        else {
            if (v == a or v == b) {pass[(v == a ? b : a)]++; del[v]--;}
            else {pass[a]++; pass[b]++; pass[v]--; del[v]--;}
        }
    }

    dfs(0);
    forn(i,n) printf("%d ",pass[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
