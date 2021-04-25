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

const int MAXN = 1e5+5;

int compSz[MAXN];
int comp = 0, maxiComp = 1;

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N,0); r.assign(N,0);
        forn(i,N) {p[i] = i; compSz[i] = 1;}
    }
    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    void join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[x] == r[y]) r[y]++;
        compSz[y] += compSz[x];
        maxiComp = max(maxiComp,compSz[y]); comp--;
    }
};

DS UF;
int ind = 0;

int main() {
    UF.init(MAXN);
    int n,m; scanf("%d %d",&n,&m);
    comp = n;

    forn(i,m) {
        int a,b; scanf("%d %d",&a,&b); a--; b--;
        UF.join(a,b);
        printf("%d %d\n",comp,maxiComp);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
