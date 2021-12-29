// Decreasing Minimum in Prefix
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/J
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
const int INF = 2e9;

// caso espcial Fenwick: los minimos funcionan en prefijos con updates decrecientes
int FT[MAXN];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] = min(FT[i],v);
}

int getFT (int p) {
    int r = INF;
    for (int i = p; i; i -= i & -i)
        r = min(r,FT[i]);
    return r;
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,MAXN) FT[i] = INF;
    forn(i,n) {
        int x; scanf("%d",&x);
        setFT(i+3,x);
    }

    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p,x; scanf("%d %d",&p,&x), p--;
            setFT(p+3,x);
        }
        else {
            int r; scanf("%d",&r), r--;
            printf("%d\n",getFT(r+3));
        }
    }

    return 0;
}