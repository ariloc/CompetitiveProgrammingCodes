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

const int MAXN = 1e5+5;
const double EPS = 1e-8L;

int flags[MAXN];
long double dpL[MAXN],dpR[MAXN];
int n,l;

long double calcL (long double mid) {
    int ind = upper_bound(dpL,dpL+n+2,mid) - dpL;
    ind = max(0,ind-1);
    return flags[ind]+(mid-dpL[ind])*(long double)(ind+1);
}

long double calcR (long double mid) {
    int ind = upper_bound(dpR,dpR+n+2,mid) - dpR;
    ind = max(0,ind-1);
    return flags[n-ind+1]-(mid-dpR[ind])*(long double)(ind+1);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        cin >> n >> l;
        forn(j,n) cin >> flags[j+1];

        flags[n+1] = l;
        forsn(j,1,n+2) dpL[j] = dpL[j-1] + (flags[j]-flags[j-1])/(long double)j;
        dforn(j,n+1) dpR[n-j+1] = dpR[n-j] + (flags[j+1]-flags[j])/(long double)(n-j+1);

        long double low = 0, high = min(dpL[n+1],dpR[n+1]);
        while (high-low > EPS) {
            long double mid = low + (high-low)/2.0L;

            if (calcR(mid)-calcL(mid) > EPS) low = mid;
            else high = mid;
        }

        long double a = abs(calcR(high)-calcL(high)), b = abs(calcR(low)-calcL(low));
        long double rta = (a < b ? high : low);
        cout << fixed << setprecision(10) << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
