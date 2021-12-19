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
typedef long double ld;

const int MAXN = 1e5+5;
const ll INF = 9e18;

ll h[MAXN], w[MAXN];

int main() {
    int n; ll H; scanf("%d %lld",&n,&H);
    forn(i,n) scanf("%lld %lld",&h[i+1],&w[i+1]);

    forsn(i,1,n+1) h[i] += h[i-1]; // dp

    multiset<ll> act;
    int r = 1;
    ll mini = INF;
    forsn(l,1,n+1) {
        while (r <= n && h[r-1] - h[l-1] < H) act.insert(w[r++]);
        if (h[r-1] - h[l-1] >= H)
            mini = min(mini,(*act.rbegin()));
        act.erase(act.find(w[l]));
    }

    printf("%lld",mini);

    return 0;
}