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
 
const int MAXN = 2e5+5;
const int INF = 1e9+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
 
ll ST[2*MAXST];
int N;
 
void update(int i, int tl, int tr, int bl, int br, const int &val) {
    if (br <= bl) return;
    if (tl == bl and tr == br) {ST[i] += val; return;}
 
    int mid = (tl+tr)/2;
    update(2*i,tl,mid,bl,min(br,mid),val);
    update(2*i+1,mid,tr,max(bl,mid),br,val);
}
 
ll query (int pos) {
    ll r = 0;
    pos += N;
    r += ST[pos];
    while (pos > 1) {
        pos /= 2;
        r += ST[pos];
    }
    return r;
}
 
int main() {
    FAST_IO;
 
    int n,q; cin >> n >> q;
    N = (1<<(32-__builtin_clz(n)));
    forn(i,n) {int x; cin >> x; ST[i+N] = x;}
    forn(i,q) {
        int typ; cin >> typ;
        if (typ == 1) {
            int l,r,v; cin >> l >> r >> v;
            update(1,0,N,l-1,r,v);
        }
        else {
            int k; cin >> k;
            cout << query(k-1) << '\n';
        }
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!