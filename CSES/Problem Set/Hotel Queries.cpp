#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
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
 
int update (int i, int tl, int tr, const int &v) {
    if (tr-tl == 1) {
        ST[i] -= v;
        return tl;
    }
    else {
        int mid = (tl+tr)/2;
        int ret = -1;
        if (ST[2*i] >= v) ret = update(2*i,tl,mid,v);
        else if (ST[2*i+1] >= v) ret = update(2*i+1,mid,tr,v);
        if (ret != -1) ST[i] = max(ST[2*i],ST[2*i+1]);
        return ret;
    }
}
 
int main() {
    FAST_IO;
 
    int n,m; cin >> n >> m;
    int N = (1<<(32-__builtin_clz(n)));
    forn(i,n) {int x; cin >> x; ST[i+N] = x;}
    dforsn(i,1,N) ST[i] = max(ST[2*i],ST[2*i+1]);
    forn(i,m) {
        int x; cin >> x;
        cout << update(1,0,N,x)+1 << ' ';
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!