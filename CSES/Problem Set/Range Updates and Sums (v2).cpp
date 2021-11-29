#include <bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n)-1; i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
 
const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
 
ll ST[2*MAXST], lazy_add[2*MAXST], lazy_set[2*MAXST];
int L[2*MAXST], R[2*MAXST];
 
void pass_lazy (int i) {
    ll sz = R[i]-L[i];
    if (lazy_set[i]) ST[i] = (lazy_set[i] * sz);
    ST[i] += (lazy_add[i] * sz);
 
    int top = 2*MAXST;
    if (2*i < top) {
        if (lazy_set[i]) lazy_add[2*i] = 0, lazy_set[2*i] = lazy_set[i];
        lazy_add[2*i] += lazy_add[i];
    }
 
    if ((2*i+1) < top) {
        if (lazy_set[i]) lazy_add[2*i+1] = 0, lazy_set[2*i+1] = lazy_set[i];
        lazy_add[2*i+1] += lazy_add[i];
    }
 
    lazy_set[i] = lazy_add[i] = 0;
}
 
void update (int i, int v, int bl, int br, bool op) { // op = 0 -> set || op = 1 -> add
    pass_lazy(i);
    if (L[i] >= br || R[i] <= bl) return;
    if (L[i] >= bl && R[i] <= br) {
        if (!op) lazy_add[i] = 0, lazy_set[i] = v;
        else lazy_add[i] += v;
        pass_lazy(i);
        return;
    }
 
    update(2*i,v,bl,br,op);
    update(2*i+1,v,bl,br,op);
    ST[i] = ST[2*i] + ST[2*i+1];
}
 
ll query (int i, int bl, int br) {
    pass_lazy(i);
    if (L[i] >= br || R[i] <= bl) return 0;
    if (L[i] >= bl && R[i] <= br) return ST[i];
    return query(2*i,bl,br) + query(2*i+1,bl,br);
}
 
int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n) scanf("%lld",&ST[i+MAXST]);
 
    forn(i,MAXST) L[i+MAXST] = R[i+MAXST] = i, ++R[i+MAXST];
    dforsn(i,1,MAXST) { // build
        ST[i] = ST[2*i] + ST[2*i+1];
        L[i] = L[2*i], R[i] = R[2*i+1];
    }
    
    forn(i,q) {
        int mode; scanf("%d",&mode);
        if (mode == 1) {
            int a,b,x; scanf("%d %d %d",&a,&b,&x); a--;
            update(1,x,a,b,1);
        }
        else if (mode == 2) {
            int a,b,x; scanf("%d %d %d",&a,&b,&x); a--;
            update(1,x,a,b,0);
        }
        else { 
            int a,b; scanf("%d %d",&a,&b); a--;
            printf("%lld\n",query(1,a,b));
        }
    }
 
    return 0;
}