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

const int MAXN = 5005;
const int MOD = 1e9+7;

int dp[MAXN][MAXN],cnt[MAXN]; // n-ésima posic, haciendo el k-ésimo mov
int arr[MAXN];

int main() {
    FAST_IO;

    int n,k,q; cin >> n >> k >> q;

    forn(j,n) dp[j+1][0] = 1;
    forsn(i,1,k+1) forsn(j,1,n+1)
        dp[j][i] = (dp[j+1][i-1]+dp[j-1][i-1])%MOD;
    forn(i,k+1) forsn(j,1,n+1) cnt[j] = ((ll)cnt[j] + (((ll)dp[j][i]*dp[j][k-i])%MOD))%MOD;

    forn(j,n) cin >> arr[j+1];

    int sum = 0;
    forsn(j,1,n+1) sum = (sum + (((ll)cnt[j]*arr[j])%MOD))%MOD;

    forn(i,q) {
        int idx,x; cin >> idx >> x;
        sum = (sum - (((ll)cnt[idx]*arr[idx])%MOD))%MOD;
        arr[idx] = x;
        sum = (sum + (((ll)cnt[idx]*arr[idx])%MOD))%MOD;
        cout << (sum+MOD)%MOD << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
