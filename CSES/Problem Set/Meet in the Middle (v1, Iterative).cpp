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
 
const int MAXK = 20;
const int MAXN = MAXK*2;
const int MAXS = 2e6+5;
 
ll arr[MAXN],aux1[MAXS],aux2[MAXS];
int ap1[MAXS],ap2[MAXS];
 
int compress (ll *src, int n, int *ap) {
    int cnt = 0;
    forsn(i,1,n) {
        if (src[i] != src[i-1])
            ap[cnt]++, src[cnt++] = src[i-1];
        else ap[cnt]++;
    }
    ap[cnt]++, src[cnt++] = src[n-1];
    return cnt;
}
 
int main() {
    int n; ll x; scanf("%d %lld",&n,&x);
 
    forn(i,n) scanf("%lld",&arr[i]);
 
    if (n == 1) return printf("%d",(arr[0] == x)), 0;
 
    int top1 = n/2;
    int top2 = n-top1;
    int top1_mk = (1<<top1), top2_mk = (1<<top2);
 
    forn(i,top1_mk)
        forn(j,top1) if (i & (1<<j)) aux1[i] += arr[j];
    
    forn(i,top2_mk)
        forn(j,top2) if (i & (1<<j)) aux2[i] += arr[j+top1];
 
    sort(aux1,aux1+top1_mk);
    sort(aux2,aux2+top2_mk);
 
    int sz1 = compress(aux1,top1_mk,ap1), sz2 = compress(aux2,top2_mk,ap2);
 
    int l = 0; ll rta = 0;
    dforn(r,sz2) {
        while (l < sz1 && aux1[l]+aux2[r] < x) l++;
        if (aux1[l]+aux2[r] == x) rta += (ll)ap1[l]*ap2[r];
    }
 
    printf("%lld",rta);
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!