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
#define M_PI 3.14159265358979323846

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int INF = 1e9+2;
const int MAX = 1e6+5;
const int MAXN = (1<<(int(log2(MAX))+1));
const int LOGMAXN = 32-__builtin_clz(MAX);

int FT[MAXN];

void setFT(int p, int v) {
    for (int i = p; i < MAXN; i += i & -i) {
        FT[i] += v;
    }
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int invertFT (int v) { // binary search in Fenwick Tree O(log n)
    int x = 0;
    for (int i = (1<<LOGMAXN-1); i; i >>= 1) {
        if (FT[x|i] < v) {
            x |= i;
            v -= FT[x];
        }
    }
    return x+1;
}

int main() {
    FAST_IO;

    int n,q; scanf("%d %d",&n,&q);

    forn (i,n) {int x; scanf("%d",&x); setFT(x,1);}
    forn (i,q) {
        int x; scanf("%d",&x);
        if (x < 0) setFT(invertFT(abs(x)),-1);
        else setFT(x,1);
    }

    if (!getFT(MAXN-1)) printf("0");
    else printf("%d",invertFT(1));

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!