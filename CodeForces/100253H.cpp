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

const int MAXN = 5002;
const int MAXA = 26;

bool dp[MAXN][MAXA];
int P[MAXN][MAXA];

int main() {
    FAST_IO;
    memset(P,-1,sizeof(P));

    int n; string s; cin >> n >> s;

    forn(i,n) dp[0][i] = true;
    forsn(i,1,s.size()+1) forn(j,n) {
        if (s[i-1] == '=') {dp[i][j] |= dp[i-1][j]; if (dp[i-1][j]) P[i][j] = j;}
        else if (s[i-1] == '<')
            forsn(k,j+1,n) {
                dp[i][k] |= dp[i-1][j];
                if (dp[i-1][j]) P[i][k] = j;
            }
        else forn(k,j) {
            dp[i][k] |= dp[i-1][j];
            if (dp[i-1][j]) P[i][k] = j;
        }
    }

    int st = -1;
    forn(j,MAXA) if (dp[(int)s.size()][j]) {st = j; break;}

    if (st == -1) cout << -1;
    else {
        string rta; int ind = s.size();
        for (int j = st; j != -1; j = P[ind--][j]) rta += j+'a';
        reverse(all(rta));
        cout << rta;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
