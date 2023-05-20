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

ll a[MAXN], b[MAXN];

int main() {
    FAST_IO;

    int n,m; ll d; cin >> n >> m >> d;
    forn(i,n) cin >> a[i];
    forn(i,m) cin >> b[i];

    sort(a,a+n);
    sort(b,b+m);

    ll maxi = -1;
    forn(i,n) {
        int ind = lower_bound(b,b+m,a[i]+d+1)-b-1;
        if (ind >= 0) {
            if (abs(a[i]-b[ind]) <= d) {
                maxi = max(maxi,a[i]+b[ind]);
            }
        }
    }

    cout << maxi;
   
    return 0;
}
