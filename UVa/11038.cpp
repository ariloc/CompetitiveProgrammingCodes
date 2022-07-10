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
typedef pair<int,int> ii;

ll getOs (ll x) {
    ll div = 10, r = 0;
    while (x/div) {
        r += (x/div - 1)*(div/10) + ((x%div)/(div/10LL) > 0 ? (div/10) : (x%div)+1);
        div *= 10LL;
    }
    return r;
}

int main() {
    ll m,n;
    while (scanf("%lld %lld",&m,&n)) {
        if (m < 0) break;
        printf("%lld\n",getOs(n)-(m ? getOs(m-1) : -1));
    }

    return 0;
}