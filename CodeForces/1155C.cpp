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

const int MAXN = 3e5+5;
const ll INF = 9e18;

ll event[MAXN], interval[MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);

    forn(i,n) scanf("%lld",&event[i]);
    forn(i,m) scanf("%lld",&interval[i]);

    ll dcm = 0;
    forsn(i,1,n) dcm = __gcd(dcm,event[i]-event[i-1]);
    int ind = -1;
    forn(i,m) if (!(dcm%interval[i])) ind = i;

    if (ind == -1) return printf("NO"), 0;

    forn(i,n) if ((event[i]-event[0])%interval[ind]) return printf("NO"), 0;
    printf("YES\n%lld %d",event[0],ind+1);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!