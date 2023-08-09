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

int const MAXN = 505;
int const MAXM = MAXN*(MAXN-1)/2;

int deg[MAXN], curdeg[MAXN];
int n,m; 
bitset<MAXM> done;
bool ady[MAXN][MAXN];

bool posib (int k) {
    forn(i,n) curdeg[i] = deg[i];
    vi required;

    queue<int> Q;

    vi auxi;
    forn(i,n) forsn(j,i+1,n) 
        if (!ady[i][j]) {
            if (curdeg[i] + curdeg[j] >= k) Q.push(i*n+j), done[i*n+j] = true;
            required.pb(i*n+j);
        }

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        int u = e%n, v = e/n;
        curdeg[u]++, curdeg[v]++;

        forn(j,n) {
            int a = u, b = j;
            if (a > b) swap(a,b);
            if (a != b && !ady[a][b] && curdeg[a] + curdeg[b] >= k && !done[a*n+b]) Q.push(a*n+b), done[a*n+b] = true;
        }

        forn(j,n) {
            int a = v, b = j;
            if (a > b) swap(a,b);
            if (a != b && !ady[a][b] && curdeg[a] + curdeg[b] >= k && !done[a*n+b]) Q.push(a*n+b), done[a*n+b] = true;
        }
    }

    for (auto &i : required) {
        if (!done[i]) return false;
        done[i] = false; // reset
    }

    return true;
}

int main() {
    scanf("%d %d",&n,&m);

    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v), --u, --v;
        ady[u][v] = ady[v][u] = true;
        deg[u]++, deg[v]++;
    }

    int maxs = 0;
    forn(i,n) forsn(j,i+1,n) if (!ady[i][j]) maxs = max(maxs, deg[i] + deg[j]);

    int low = 0, high = maxs+1;
    while (high - low > 1) {
        int mid = (high + low)/2;
        if (posib(mid)) low = mid;
        else high = mid;
    }

    printf("%d",low);
    
    return 0;
}
