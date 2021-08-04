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

const int MAXN = 105;
const int MAXL = 3005;
const int MOD = 1e9+7;

int arr[MAXN][2];
int dp[MAXL][MAXN][2];

int main() {
    FAST_IO;

    int n,l; cin >> n >> l;
    forn(i,n) cin >> arr[i+1][0] >> arr[i+1][1];

    forn(i,n) {
        dp[arr[i+1][1]][i+1][0] = 1;
        if (arr[i+1][0] != arr[i+1][1]) dp[arr[i+1][0]][i+1][1] = 1;
    }
    forsn(i,1,l+1) forsn(j,1,n+1) forn(k,2-(arr[j][0] == arr[j][1])) 
        forsn(o,1,n+1) forn(m,2-(arr[o][0] == arr[o][1])) 
            if (o != j && arr[j][k] == arr[o][m^1] && i-arr[j][1^k] >= 0) 
                dp[i][j][k] = (dp[i][j][k] + dp[i-arr[j][1^k]][o][m])%MOD;

    int rta = 0;
    forsn(j,1,n+1) forn(k,2) rta = (rta + dp[l][j][k])%MOD;

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!