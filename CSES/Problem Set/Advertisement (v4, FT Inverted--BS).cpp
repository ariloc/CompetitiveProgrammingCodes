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
const int LOGMAXN = (31-__builtin_clz(MAXN));
 
ii arr[MAXN];
int FT[MAXN],live[MAXN];
 
int getFT (int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}
 
void setFT (int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}
 
int invertFT (int v) {
    int x = 0;
    for (int d = 1<<LOGMAXN; d; d >>= 1) {
        if ((x|d) < MAXN && FT[x|d] < v) {
            x |= d;
            v -= FT[x];
        }
    }
    return x+1 - 2;
}
 
int main() {
    int n; scanf("%d",&n);
 
    forn(i,n) scanf("%d",&arr[i].fst), arr[i].snd = i;
 
    sort(arr,arr+n);
 
    ll rta = 0;
    forn(i,n) {
        int me = getFT(arr[i].snd);
        int r = invertFT(me+1);
        int l = invertFT(me);
 
        if (!live[r]) r = n;
        if (!live[l]) l = -1;
 
        rta = max(rta, (r-l-1)*(ll)arr[i].fst);
        setFT(arr[i].snd,1), live[arr[i].snd] = 1;
    }
 
    printf("%lld",rta);
 
    return 0;
}
