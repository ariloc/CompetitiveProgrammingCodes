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

const int MAX = (1<<17) + 5;
const int MAXN = 35;

vi A,B;
vector<ll> sums1, sums2;

int main() {
    int n,a,b; scanf("%d %d %d",&n,&a,&b);

    sums1.reserve(MAX);
    sums2.reserve(MAX);
    A.reserve(MAXN);
    B.reserve(MAXN);

    forn(i,n) {
        int x; scanf("%d",&x);
        if (i&1) A.pb(x); else B.pb(x);
    }

    int n1 = (int)A.size(), n2 = (int)B.size();

    forn(i,1<<n1) {
        ll s = 0;
        forn(j,n1) if (i&(1<<j)) s += A[j];
        sums1.pb(s);
    }

    forn(i,1<<n2) {
        ll s = 0;
        forn(j,n2) if (i&(1<<j)) s += B[j];
        sums2.pb(s);
    }

    sort(all(sums1));
    sort(all(sums2));

    ll rta = 0;
    for (auto &i : sums1) {
        int r = upper_bound(all(sums2),b-i)-sums2.begin();
        int l = lower_bound(all(sums2),a-i)-sums2.begin();
        rta += r-l;
    }

    printf("%lld",rta);
   
    return 0;
}
