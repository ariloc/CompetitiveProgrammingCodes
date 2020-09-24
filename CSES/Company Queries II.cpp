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
const int MAXM = 2*MAXN;
const int MAXK = 19;

vi G[MAXN];
int T[MAXM],L[MAXM],A[MAXN],LOG[MAXM];
int actT = 0;
ii SpT[MAXM][MAXK];

void tour(int st, int lvl) {
    A[st] = actT;
    T[actT] = st;
    L[actT++] = lvl;

    for (auto &i : G[st]) {
        tour(i,lvl+1);
        T[actT] = st;
        L[actT++] = lvl;
    }
}

void precompLog() {
    LOG[1] = 0;
    forsn(i,2,MAXM) LOG[i] = LOG[i/2]+1;
}

void fillSpT() {
    forn(i,actT) SpT[i][0] = {L[i],i};

    forsn(j,1,MAXK) for(int i = 0; i+(1<<(j-1)) < actT; i++)
        SpT[i][j] = min(SpT[i][j-1],SpT[i+(1<<(j-1))][j-1]);
}

int query(int l, int r) {
    int j = LOG[r-l+1];
    return min(SpT[l][j],SpT[r-(1<<j)+1][j]).snd;
}

int main() {
    precompLog();
    int n,q; scanf("%d %d",&n,&q);

    forn(i,n-1) {
        int x; scanf("%d",&x);
        G[x-1].pb(i+1);
    }
    tour(0,0); fillSpT();
    forn(i,q) {
        int a,b; scanf("%d %d",&a,&b);
        a = A[a-1]; b = A[b-1]; if (a > b) swap(a,b);
        printf("%d\n",T[query(a,b)]+1);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
