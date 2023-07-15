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

int const MAXN = 1e6+5;

int arr[MAXN];
map<int,int> ap;
int dpl[MAXN], dpr[MAXN];
int FT[MAXN];

void setFT (int p, int v) {
    p += 2;
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    p += 2;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) {
        ap[arr[i]]++;
        auto it = ap.find(arr[i]);
        if (it != ap.end()) dpl[i] = (*it).snd;
    }
    ap.clear();
    dforn(i,n) {
        ap[arr[i]]++;
        auto it = ap.find(arr[i]);
        if (it != ap.end()) dpr[i] = (*it).snd;
    }

    ll cnt = 0;
    forn(i,n) setFT(dpr[i],1);
    forn(i,n) {
        setFT(dpr[i],-1);
        cnt += getFT(dpl[i]-1);
    }

    printf("%lld",cnt);

    return 0;
}
