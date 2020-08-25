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

const int MAXN = 1005;
const int K = (int)log2(MAXN)+2;

vi G[MAXN];
int L[2*MAXN],E[2*MAXN],H[MAXN],ind; // LCA
ii SpT[2*MAXN][K];
bitset<MAXN> inDegree;
int LOG[MAXN+1]; // logaritmos precalc

void initLog() { // precomputar
    LOG[1] = 0;
    forsn(i,2,MAXN+1) LOG[i] = LOG[i/2]+1;
}

void dfs(int st, int lvl) {
    H[st] = ind;
    E[ind] = st;
    L[ind++] = lvl;

    for (auto &i : G[st]) {
        dfs(i,lvl+1);
        E[ind] = st;
        L[ind++] = lvl;
    }
}

void fillSpT(int N) {
    forn (i,N) SpT[i][0] = {L[i],i};

    forsn(j,1,K+1) for(int i = 0; i+(1<<j) <= N; i++)
        SpT[i][j] = min(SpT[i][j-1],SpT[i+(1<<(j-1))][j-1]);
}

int query(int &l, int &r) {
    int j = LOG[r-l+1];
    return min(SpT[l][j],SpT[r-(1<<j)+1][j]).snd;
}

int main() {
    //FAST_IO;

    initLog();
    int t; scanf("%d",&t);

    forn(i,t) {
        int n; scanf("%d",&n);
        forn(j,n) {G[j].clear(); H[j] = -1; inDegree[j] = false;} ind = 0; // reset

        forn(j,n) {
            int m; scanf("%d",&m);
            forn(k,m) {int x; scanf("%d",&x); G[j].pb(x-1); inDegree[x-1] = true;}
        }

        int root = 0; forn(j,n) if (!inDegree[j]) {root = j; break;}

        dfs(root,0);
        fillSpT(ind);

        int q; scanf("%d",&q);
        printf("Case %d:\n",i+1);
        forn(j,q) {
            int a,b; scanf("%d %d",&a,&b);
            a = H[a-1]; b = H[b-1];
            if (a > b) swap(a,b);
            printf("%d\n",E[query(a,b)]+1);
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
