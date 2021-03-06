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
 
int ST[2*MAXST];
int N;
 
void update(int i, int tl, int tr, const int &pos, const int &val) {
    if (tr-tl == 1) {ST[i] = val;}
    else {
        int mid = (tl+tr)/2;
        if (pos < mid)
            update(2*i,tl,mid,pos,val);
        else update(2*i+1,mid,tr,pos,val);
        ST[i] = min(ST[2*i],ST[2*i+1]);
    }
}
 
int query(int i, int tl, int tr, const int &L, const int &R) {
    if (tl >= R or tr <= L) return INF;
    if (tl >= L and tr <= R) return ST[i];
 
    int mid = (tl+tr)/2;
    return min(query(2*i,tl,mid,L,R),query(2*i+1,mid,tr,L,R));
}
 
int main() {
    FAST_IO;
 
    int n,q; cin >> n >> q;
    N = (1<<(32-__builtin_clz(n)));
    forn(i,n) {int x; cin >> x; ST[i+N] = x;}
    dforsn(i,1,N) ST[i] = min(ST[2*i],ST[2*i+1]);
    forn(i,q) {
        int typ; cin >> typ;
        if (typ == 1) {
            int k,u; cin >> k >> u;
            update(1,0,N,k-1,u);
        }
        else {
            int l,r; cin >> l >> r;
            cout << query(1,0,N,l-1,r) << '\n';
        }
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!