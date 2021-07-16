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

ll dp[MAXN][2];
 
int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        string s; cin >> s; 
        int n = s.size();

        forn(i,n+2) dp[i][0] = dp[i][1] = 0;

        forsn(i,1,n+1) forn(j,2)
            if (j+'0' == s[i-1] || s[i-1] == '?') dp[i][j] = dp[i-1][1^j]+1;

        ll r = 0;
        forsn(i,1,n+1) forn(j,2) r += dp[i][j];

        ll cnt = 0;
        forn(i,n) 
            if (s[i] != '?') r -= cnt*(cnt+1)/2, cnt = 0;
            else cnt++;
        r -= cnt*(cnt+1)/2;

        cout << r << '\n';
    }
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!