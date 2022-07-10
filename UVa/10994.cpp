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

ll sumUpTo (ll x) {
    ll r = 0, div = 1;
    while (div <= x) {
        div *= 10LL;
        r += (x/div)*45LL;
        ll aux = (x%div)/(div/10LL);
        r += (aux*(aux+1))/2LL;
    }
    return r;
}

int main() {
    int p,q;
    while (scanf("%d %d",&p,&q)) {
        if (p < 0 && q < 0) break;
        printf("%lld\n",sumUpTo(q)-(p ? sumUpTo(p-1) : 0));
    }

    return 0;
}