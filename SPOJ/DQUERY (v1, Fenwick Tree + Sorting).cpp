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

const int MAXQ = 2e5+5;
const int MAXN = 3e4+5;
const int MAXM = MAXQ+MAXN;
const int MAXT = 1e6+5;

struct range {
    int l,r,id;

    bool operator< (const range &o) const{
        if (r == o.r) return l < o.l;
        return r < o.r;
    }
};

int FT[MAXN],posic[MAXT],rta[MAXQ];
range queries[MAXM];

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int main() {
    memset(posic,-1,sizeof(posic));
    int n; scanf("%d",&n);
    forn(i,n) {
        scanf("%d",&queries[i].l);
        queries[i].r = i+2; queries[i].l *= -1;
    }
    int q; scanf("%d",&q);
    forn(i,q) {
        scanf("%d %d",&queries[i+n].l,&queries[i+n].r);
        queries[i+n].l++; queries[i+n].r++;
        queries[i+n].id = i;
    }

    int sz = q+n;
    sort(queries,queries+sz);

    forn(i,sz) {
        if (queries[i].l < 0) {
            if (posic[-queries[i].l] != -1) setFT(posic[-queries[i].l],-1);
            setFT(queries[i].r,1);
            posic[-queries[i].l] = queries[i].r;
        }
        else rta[queries[i].id] = getFT(queries[i].r)-getFT(queries[i].l-1);
    }

    forn(i,q) printf("%d\n",rta[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!

