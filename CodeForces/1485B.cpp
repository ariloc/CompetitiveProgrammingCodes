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

const int MAXN  = 1e5+5;

int arr[MAXN];
ll dp[MAXN],dp2[MAXN];

int main() {
    FAST_IO;

    int n,q,k; cin >> n >> q >> k;
    forn(i,n) cin >> arr[i];

    forn(i,n-1) dp[i+1] = (arr[i+1]-arr[i]-1);
    dforsn(i,1,n) dp2[i+1] += (arr[i]-arr[i-1]-1);
    forsn(i,1,n+2) dp[i] += dp[i-1];
    forsn(i,1,n+2) dp2[i] += dp2[i-1];

    forn(i,q) {
        int l,r; cin >> l >> r; l--, r--;
        ll aux = max(0LL,dp[r]-dp[l]), aux2 = max(0LL,dp2[r+1]-dp2[l+1]);
        //cerr << k-arr[r] <<  ' ' << aux << ' ' << arr[l]-1 << endl;

        cout << (ll)(arr[l]-1) + (ll)(k-arr[r]) + aux + aux2 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
