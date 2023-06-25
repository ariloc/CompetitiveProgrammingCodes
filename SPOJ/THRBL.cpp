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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXK = 17;
const int MAXN = 1<<MAXK;

int SP[MAXK][MAXN];

int query (int l, int r) {
    if (l == r) return SP[0][l];
    int dif = r-l;
    int bit = (31-__builtin_clz(dif));
    return max(SP[bit][l], SP[bit][r-(1<<bit)+1]);
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&SP[0][i]);

    forsn(k,1,MAXK) forn(i,n)
        SP[k][i] = max(SP[k-1][i], SP[k-1][min(i+(1<<(k-1)),MAXN-1)]);

    int cnt = 0;
    forn(i,m) {
        int l,r; scanf("%d %d",&l,&r), l--, r--;
        if (l > r) swap(l,r);
        if (l == r) {cnt++; continue;}
        --r;
        cnt += (query(l,r) <= SP[0][l]);
    }

    printf("%d\n",cnt);
    
    return 0;
}
