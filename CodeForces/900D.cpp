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

const int MOD = 1e9+7;
const int MAXN = 2005;

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

vi divs;
int dp[MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int x,y; cin >> x >> y;
    if (y%x) return cout << 0,0;

    for (int i = 1; i*i <= y; i++) {
        if (!(y%i)) {
            divs.pb(i);
            int aux = y/i;
            if (aux != i) divs.pb(aux);
        }
    }

    sort(all(divs));

    int n = divs.size();

    dforn(i,n) {
        dp[i] = binExp(2,y/divs[i]-1);
        forsn(j,i+1,n) {
            if (done[i][j]) continue;
            int mcm = ((ll)divs[i]*divs[j])/__gcd(divs[i],divs[j]);
            int ind = lower_bound(all(divs),mcm)-divs.begin();
            if (divs[ind] != mcm) continue;
            if (done[i][ind]) continue;
            done[i][ind] = true;
            dp[i] = (dp[i] - dp[ind] + MOD)%MOD;
        }
    }

    int myInd = lower_bound(all(divs),x)-divs.begin();
    cout << dp[myInd];

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
