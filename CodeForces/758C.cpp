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

int main() {
    FAST_IO;

    ll n,m,k,x,y; cin >> n >> m >> k >> x >> y;

    if (n == 1) {
        ll pass = k/(n*m), rest = (k%(n*m));
        cout << pass+(rest > 0) << ' ' << pass << ' ' << ((rest%m) >= y ? pass+1 : pass) << '\n';
    } else {
        ll pass = max(0LL,(k-(n*m)))/((n-1)*m), rest = max(0LL,(k-(n*m)))%((n-1)*m);
        //cerr << (pass&1) << ' ' << rest/m << ' ' <<rest%m <<' ' << x-1 << ' ' << n-x-1 << ' ' << pass << endl;
        ll serg = (k >= n*m ? 1 : (k/m > (x-1) || (k/m == (x-1) && (k%m) >= y))) +
                  (pass/(1+(x == 1 || x == n))) +
                  ((pass&1) && (x==1)) +
                  ( !(pass&1) ? (x == n ? 0 : ( (rest/m) > (n-x-1) || ( ((rest/m) == (n-x-1)) && (rest%m) >= y ) ) ) :
                                (x == 1 ? 0 : (((rest/m) > (x-2)) || (((rest/m) == (x-2)) && ((rest%m) >= y)) ) ) );

        cout << max(1+pass/2+(pass&1 || rest>0),(1+pass+(rest>0))*(n!=2)) << ' ' << (k>=(n*m))+pass/2 << ' ' << serg << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
