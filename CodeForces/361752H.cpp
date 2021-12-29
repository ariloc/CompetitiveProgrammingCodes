// Alternated Sum Range Queries
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/H
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

ll FT[MAXN];

void setFT (int p, ll v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n) {
        int x; scanf("%d",&x);
        setFT(i+3, x * (i&1 ? -1LL : 1LL));
    }
    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p; ll x; scanf("%d %lld",&p,&x), p--;
            x *= (p&1 ? -1LL : 1LL);
            setFT(p+3, x-getFT(p+3)+getFT(p+2));
        }
        else {
            int l,r; scanf("%d %d",&l,&r), l--, r--;
            printf("%lld\n",(getFT(r+3)-getFT(l+2)) * (l&1 ? -1LL : 1LL));
        }
    }

    return 0;
}