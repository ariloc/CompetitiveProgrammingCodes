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

const int MAXN = 1005;
const int INF = 1e9+5;

int dp[MAXN][2]; // 0 is C, 1 is J

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(o,t) {
        int x,y; cin >> x >> y;
        string s; cin >> s;

        forn(i,s.size()+2) dp[i][0] = dp[i][1] = INF;
        dp[0][0] = dp[0][1] = 0;

        int rta[2][2] = { {0,x}, {y,0} };

        int n = s.size();
        forsn(i,1,n) {
            vi ip,jp;
            ip.pb(s[i-1] == 'J');
            jp.pb(s[i] == 'J');
            if (s[i-1] == '?') ip.pb(1);
            if (s[i] == '?') jp.pb(1);

            for (auto &j : ip) for (auto &k : jp)
                dp[i][k] = min(dp[i][k],dp[i-1][j]+rta[j][k]);
        }

        cout << "Case #" << o+1 << ": " << min(dp[n-1][0],dp[n-1][1]) << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
