#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 202;
const int INF = 1e9+5;

int arr[MAXN],dp[MAXN][2*MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,MAXN) forn(k,2*MAXN) dp[j][k] = INF;
        forn(j,n) cin >> arr[j];
        sort(arr,arr+n);
        forsn(j,1,2*MAXN) dp[0][j] = abs(arr[0]-j);
        forsn(j,1,n) forn(t2,2*MAXN) dforn(t1,t2) dp[j][t2] = min(dp[j][t2],dp[j-1][t1]+abs(arr[j]-t2));

        int mini = INF;
        forn(j,2*MAXN) mini = min(mini,dp[n-1][j]);
        cout << mini << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
