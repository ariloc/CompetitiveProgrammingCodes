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
const int LOGMAXN = (32-__builtin_clz(MAXN));
 
int FT[MAXN];
int arr[MAXN];
 
int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}
 
void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}
 
int invertFT (int v) {
    int x = 0;
    for (int d = 1<<(LOGMAXN-1); d; d>>=1) {
        if ((x|d) < MAXN and FT[x|d] < v) {
            x |= d;
            v -= FT[x];
        }
    }
    return x+1;
}
 
int main() {
    int n; scanf("%d",&n);
    forn(i,n) {scanf("%d",&arr[i]); setFT(i+1,1);} // marco todos presentes
    forn(i,n) {
        int x; scanf("%d",&x);
        int p = invertFT(x); // busco aquel punto en el que tengo a todos
        printf("%d ",arr[p-1]); // -1 pues 1-indexed pues uso Fenwick
        setFT(p,-1); // y como lo descart�, lo marco como ausente
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!