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

int const MAXN = 2e5+5;
int const MOD = 1e9+7;

int arr[MAXN], FT[MAXN];
vi pts;

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void setFT (int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] = sumMod(FT[i],v);
}

int getFT (int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r = sumMod(r,FT[i]);
    return r;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]), pts.pb(arr[i]);

    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());

    forn(i,n) {
        int ind = lower_bound(all(pts),arr[i])-pts.begin();
        arr[i] = ind+1;
    }
    setFT(0,1);

    int rta = 0;
    forn(i,n) {
        int cnt = getFT(arr[i]-1);
        rta = sumMod(rta, cnt);
        setFT(arr[i],cnt);
    }

    printf("%d",rta);

    return 0;
}
