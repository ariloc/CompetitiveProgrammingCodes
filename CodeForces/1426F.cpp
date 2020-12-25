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

const int MAXN = 2e5+2;
const int MOD = 1e9+7;

int dp[MAXN][4];

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    string s; cin >> s;

    s = " "+s; n++; // desfase
    forsn(i,1,n) dp[i][(s[i] == '?' ? 3 : int(s[i]-'a'))]++;
    forsn(i,1,n+1) forn(k,4) dp[i][k] += dp[i-1][k];

    int cnt = 0;
    forsn(i,1,n) if (s[i] == 'b' || s[i] == '?')
        forn(j,4)
            cnt = (cnt + ((((dp[i-1][(j&1) ? 3 : 0] * (ll)(binExp(3, max(0, dp[n][3]-(j&1)-((j&2) > 0)-(s[i] == '?')) )))%MOD) * (ll)(dp[n][(j&2) ? 3 : 2]-dp[i][(j&2) ? 3 : 2]))%MOD))%MOD;

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
