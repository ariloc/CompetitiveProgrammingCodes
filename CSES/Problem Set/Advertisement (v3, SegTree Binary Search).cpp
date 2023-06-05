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
 
const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
 
ii arr[MAXN];
int ST[2*MAXST],N;
 
void update(int p, int v) {
    p += N; ST[p] += v;
    while (p > 1)
       p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}
 
int get (int l, int r) {
    int ret = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) ret += ST[l++];
        if (r&1) ret += ST[--r];
    }
    return ret;
}
 
int query (int i, int v, int acc = 0, int tl = 0, int tr = N) {
    if (tr-tl <= 1) return tl;
 
    int mid = (tl+tr)/2;
    if (acc+ST[2*i] < v) return query(2*i+1,v,acc+ST[2*i],mid,tr);
    return query(2*i,v,acc,tl,mid);
}
 
int main() {
    int n; scanf("%d",&n);
 
    forn(i,n) scanf("%d",&arr[i].fst), arr[i].snd = i;
 
    N = (1<<(32-__builtin_clz(n)));
 
    sort(arr,arr+n);
 
    ll rta = 0;
    forn(i,n) {
        int me = get(0,arr[i].snd);
        int r = query(1,me+1);
        int l = query(1,me);
 
        if (!ST[r+N]) r = n;
        if (!ST[l+N]) l = -1;
 
        rta = max(rta, (r-l-1)*(ll)arr[i].fst);
 
        update(arr[i].snd,1);
    }
 
    printf("%lld",rta);
 
    return 0;
}
