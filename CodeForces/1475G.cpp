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

const int MAXN = 2e5+5;

int histo[MAXN], arr[MAXN], dp[MAXN];

int solve (int st, int step) {
    if (st >= MAXN) return 0;
    if (st == step && dp[st] != -1) return dp[st];

    int v = max(solve(st+step,step),solve(st+step,st+step))+(step == st)*histo[st];
    if (st == step) dp[st] = v;
    return v;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;

        memset(dp,-1,sizeof(dp)); // reset
        forn(j,MAXN) histo[j] = 0;

        forn(j,n) cin >> arr[j], histo[arr[j]]++;
        //sort(arr,arr+n);

        int rta = 0;
        forn(j,n) rta = max(solve(arr[j],arr[j]),rta);

        cout << n-rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
