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

int const MAXN = 7e5+5;
int const INF = 2e9+5;

int arr[MAXN];

int solve (vi &a, vi &b, int n) {
    int tg = a[0]+b[0];
    int ind = n-1;
    forn(i,n-1) if (a[i]+b[i] != tg) {
        ind = i; break;
    }
    bool posib = true;
    forn(i,n-1) if (a[i]+b[i+(i>=ind)] != tg) posib = false;
    if (posib && tg-b[ind] > 0) return tg-b[ind];
    return INF;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,2*n-1) cin >> arr[i];

        if (n == 1) {
            cout << "Case #" << o+1 << ": 1\n";
            continue;
        }

        sort(arr,arr+n+n-1);

        int r = INF;

        vi a,b;
        forn(i,n-1) a.pb(arr[i]);
        forsn(i,n-1,2*n-1) b.pb(arr[i]);
        reverse(all(b));

        r = min(r,solve(a,b,n));
        reverse(all(a)); reverse(all(b));
        r = min(r,solve(a,b,n));

        a.clear(); b.clear();
        forn(i,n) a.pb(arr[i]);
        forsn(i,n,2*n-1) b.pb(arr[i]);
        reverse(all(b));

        r = min(r,solve(b,a,n));
        reverse(all(a)); reverse(all(b));
        r = min(r,solve(b,a,n));

        cout << "Case #" << o+1 << ": " << (r == INF ? -1 : r) << '\n';
    }

    return 0;
}
