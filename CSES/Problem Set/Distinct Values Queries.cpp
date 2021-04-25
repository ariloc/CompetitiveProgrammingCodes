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

const int MAXN = 2e5+2;
const int MAXA = 2*MAXN;

void fastscan(int &x) {
    int c = 0; x = 0;
    c=getchar_unlocked();
    if (c<'0' || c>'9') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

struct query {
    int l,r,ind;

    bool operator< (const query &o) const{
        if (r == o.r) return ind < o.ind;
        return r < o.r;
    }
};

int FT[MAXN],rta[MAXN],pos[MAXN];
vi compress;
query input[MAXA];

int getFT (int p) {
    int r = 0;
    for(int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, int v) {
    for(int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

void compressVals(int n) {
    sort(all(compress));
    compress.erase(unique(all(compress)),compress.end());
    forn(i,n) if (input[i].ind == -1) input[i].l = (int)(lower_bound(all(compress),input[i].l) - compress.begin()) + 1;
}

int main() {
    int n,q; fastscan(n); fastscan(q);
    forn(i,n) {int x; fastscan(x); input[i] = {x,i+2,-1}; compress.pb(x);}
    forn(i,q) {int a,b; fastscan(a); fastscan(b); input[n+i] = {a+1,b+1,i};}

    compressVals(n);
    sort(input,input+n+q);

    forn(i,n+q) {
        if (input[i].ind == -1) {
            if (pos[input[i].l] > 0) setFT(pos[input[i].l],-1);
            setFT(input[i].r,1); pos[input[i].l] = input[i].r;
        }
        else rta[input[i].ind] = getFT(input[i].r)-getFT(input[i].l-1);
    }

    forn(i,q) printf("%d\n",rta[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
