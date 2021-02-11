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

const int MAXN = 2e5+2;

int arr[MAXN],dp[MAXN],idx[MAXN],P[MAXN];
vi toCompress;

int getPos (int v) {
    return lower_bound(all(toCompress),v)-toCompress.begin();
}

int main() {
    FAST_IO;

    forn(i,MAXN) dp[i] = 1, P[i] = idx[i] = -1; // init;

    int n; cin >> n;
    forn(j,n) cin >> arr[j], toCompress.pb(arr[j]);

    // compression
    sort(all(toCompress));
    toCompress.erase(unique(all(toCompress)),toCompress.end());

    for (auto &i : toCompress) cerr << i << ' ';
    cerr << endl;

    forn(i,n) {
        int pos = getPos(arr[i]);
        if (idx[pos] == -1) idx[pos] = i;

        if (!pos || toCompress[pos-1] != arr[i]-1 || idx[pos-1] == -1) continue;
        if (dp[pos-1]+1 > dp[pos]) {
            dp[pos] = dp[pos-1]+1;
            P[i] = idx[pos-1];
            idx[pos] = i;
        }
    }

    int maxi = -1, pos = -1;
    forn(i,MAXN) if (dp[i] > maxi) maxi = dp[i], pos = idx[i];

    vi path;
    for (int i = pos; i != -1; i = P[i]) path.pb(i+1);

    cout << path.size() << '\n';
    dforn(j,path.size()) cout << path[j] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
