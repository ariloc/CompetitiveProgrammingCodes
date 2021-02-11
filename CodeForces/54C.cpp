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

const int MAXN = 1005;
const int MAXP = 19;

ld dp[MAXN][MAXN]; // agarrando el i-ésimo número, teniendo j números con un primer dígito 1
ll pot10[MAXP];
pair<ll,ll> arr[MAXN];

void precomp() {
    pot10[0] = 1;
    forsn(i,1,MAXP) pot10[i] = pot10[i-1]*10LL;
}

ld probRange (ll l, ll r) {
    ll tot = r-l+1;

    int lowcnt = log10(l), topcnt = log10(r);
    ll lowL = pot10[lowcnt]*2-1, topL = pot10[topcnt];

    ll fDig = max(0LL,min(lowL,r)-l+1) + (topcnt != lowcnt ? min(r,topL*2-1)-topL+1 : 0);
    forsn(i,lowcnt+1,topcnt) fDig += pot10[i];

    return fDig/(ld)tot;
}

int main() {
    FAST_IO;

    precomp();

    int n; cin >> n;
    forn(i,n) cin >> arr[i+1].fst >> arr[i+1].snd;
    int k; cin >> k;

    dp[0][0] = 1;
    forsn(i,1,n+1) forn(j,n+1) {
        ld prob = probRange(arr[i].fst,arr[i].snd);

        if (j > 0) dp[i][j] += dp[i-1][j-1]*prob;
        dp[i][j] += dp[i-1][j]*(1-prob);
        //cerr << dp[i][j] << ' ' << i << ' ' << j << ' ' << prob << endl;
    }

    ld rta = 0;
    int bottom =(n*k+99)/100;
    forsn(i,bottom,n+1) rta += dp[n][i];

    cout << fixed << setprecision(15) << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
