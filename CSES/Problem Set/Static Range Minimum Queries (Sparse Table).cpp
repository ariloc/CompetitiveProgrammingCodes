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
const int K = (int)log2(MAXN)+1;
 
int SpT[MAXN][K];
int LOG[MAXN+1];
 
void fillSpT(int N) {
    forsn(j,1,K+1) for(int i = 0; i+(1<<j) <= N; i++)
        SpT[i][j] = min(SpT[i][j-1],SpT[i+(1<<(j-1))][j-1]);
}
 
void initLog() {
    LOG[1] = 0;
    forsn(i,2,MAXN+1) LOG[i] = LOG[i/2]+1;
}
 
int query(int l, int r) {
    int j = LOG[r-l+1];
    return min(SpT[l][j],SpT[r-(1<<j)+1][j]);
}
 
int main() {
    FAST_IO;
 
    initLog();
    int n,q; cin >> n >> q;
 
    forn(i,n) {int x; cin >> x; SpT[i][0] = x;}
    fillSpT(n+1);
 
    forn(i,q) {
        int l,r; cin >> l >> r; l--; r--;
        cout << query(l,r) << '\n';
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!