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
 
int FT[MAXN];
 
void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] ^= v;
}
 
int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r ^= FT[i];
    return r;
}
 
int main() {
    FAST_IO;
 
    int n,q; cin >> n >> q;
    forn(i,n) {int x; cin >> x; setFT(i+1,x);}
    forn(i,q) {
        int l,r; cin >> l >> r;
        cout << (getFT(r)^((l-1) ? getFT(l-1) : 0)) << '\n';
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!