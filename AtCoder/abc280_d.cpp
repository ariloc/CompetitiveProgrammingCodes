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

ll cantPrim(ll x, ll k) {
    ll cnt = 0, curr = k;
    while (curr <= x)
        cnt += x / curr, curr *= k;
    return cnt;
}

int main() {
    ll x; scanf("%lld",&x);

    map<ll,ll> F;
    for(ll i = 2; i*i <= x; i++) {
        while (!(x%i)) F[i]++, x /= i;
    }
    if (x > 1) F[x]++;

    ll rta = (*prev(F.end())).fst;
    cerr << rta << endl;

    for (auto &i : F) {
        bool prim = 1;
        while (cantPrim(rta, i.fst) < i.snd) {
            if (prim) {
                ll rest = rta % i.fst;
                rta += (i.fst - rest)%i.fst;
                prim = false;
            }
            else {
                rta += i.fst;
            }
        }
    }

    printf("%lld", rta);

    return 0;
}


