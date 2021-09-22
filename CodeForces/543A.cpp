#include <bits/stdc++.h>

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

const int MAXN = 502;

int prog[MAXN];
ll dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m,b,mod; cin >> n >> m >> b >> mod;
    forn (i,n) cin >> prog[i];

    dp[0][0] = 1; // primera linea sin bugs
    forn (i,n) forsn (j,1,m+1) forn (k,b+1) { // por c/prog, por c/linea, viniendo de una linea de k bugs
        ll kN = k + prog[i]; // bugs totales a este punto (por los que introdujo el i tipo)
        if (kN <= b) dp[j][kN] = (dp[j][kN]+dp[j-1][k])%mod;
    }

    ll r = 0;
    forn (i,b+1) r = (r+dp[m][i])%mod;
    cout << r;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!