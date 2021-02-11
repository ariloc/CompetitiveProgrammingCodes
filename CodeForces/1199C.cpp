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

const int MAXN = 4e5+2;
const int INF = 1e9+5;

int arr[MAXN],mark[MAXN];
vi num;

int minChanged (int n, int K, int I) {
    forn(i,n) mark[i] = 0; // reset

    int k = 0; // ceil(log2 K)
    while ((1<<k) < K) k++;

    int r = 0, mini = INF, diff = 0;
    ll calc = n*k;
    if (calc > I*8LL) return INF;
    forn(l,n) {
        while (r < n && (diff < K || (diff == K && mark[arr[r]])))
            diff += (!mark[arr[r]]), mark[arr[r++]]++;
        if (diff < K) break;
        //cerr << K << ' ' << calc << ' ' << I*8LL << ' ' << l << ' ' << r << ' ' << k << endl;
        mini = min(mini,n-r+l);
        mark[arr[l]]--, diff -= (!mark[arr[l]]);
    }
    //cerr << n << ' ' << K << ' ' << mini << endl;
    return mini;
}

int main() {
    int n,I; scanf("%d %d",&n,&I);
    forn(i,n) scanf("%d",&arr[i]), num.pb(arr[i]);

    sort(arr,arr+n);

    // compress
    sort(all(num));
    num.erase(unique(all(num)),num.end());
    forn(i,n) arr[i] = lower_bound(all(num),arr[i])-num.begin();

    int cntDiff = 1;
    forsn(i,1,n) if (arr[i] != arr[i-1]) cntDiff++;

    int low = 1, high = cntDiff;
    while (high-low > 1) { // determinamos la cantidad de valores distintos
        int mid = (high+low)/2;
        if (minChanged(n,mid,I) != INF) low = mid;
        else high = mid;
    }

    printf("%d",min(minChanged(n,low,I),minChanged(n,high,I)));
    //cerr << minChanged(n,2,I) << endl;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
