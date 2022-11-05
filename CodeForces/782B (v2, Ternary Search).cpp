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

const double EPS = 1e-7;
const int MAXC = 1e9;
const int MAXN = 60005;

int n;
int coords[MAXN], speeds[MAXN];

ld check (ld mid) {
    ld maxi = 0;
    forn(i,n) maxi = max(maxi, abs(mid-coords[i])/speeds[i]);
    return maxi;
}

int main() {
    scanf("%d",&n);

    forn(i,n) scanf("%d",&coords[i]);
    forn(i,n) scanf("%d",&speeds[i]);

    ld low = 1, high = MAXC;
    while (high-low > EPS) {
        ld mid = (high+low)/2;
        if (check(mid) > check(mid+EPS))
            low = mid;
        else high = mid;
    }

    printf("%Lf",check(high));

    return 0;
}
