// K-th One
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/D
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const int LOGMAXN = 32-__builtin_clz(MAXN);

int FT[MAXN];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int invertFT (int v) {
    int x = 0;
    for (int d = (1<<(31-__builtin_clz(MAXN))); d; d >>= 1) 
        if ((x|d) < MAXN && FT[x|d] < v) x |= d, v -= FT[x];
    return x+1;
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n) {
        int x; scanf("%d",&x);
        if (x) setFT(i+3,1);
    }
    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p; scanf("%d",&p), p--;
            int aux = getFT(p+3)-getFT(p+2);
            setFT(p+3, aux ? -1 : 1);
        }
        else {
            int k; scanf("%d",&k);
            printf("%d\n",invertFT(k)-2);
        }
    }

    return 0;
} 
