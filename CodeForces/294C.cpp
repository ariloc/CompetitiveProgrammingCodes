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
const int MOD = 1e9+7;

int lights[MAXN], fact[MAXN], factInv[MAXN], inv[MAXN], pot2[MAXN];

void precomp() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    factInv[0] = 1;
    forsn(i,1,MAXN) factInv[i] = (factInv[i-1]*(ll)inv[i])%MOD;

    pot2[0] = pot2[1] = 1;
    forsn(i,2,MAXN) pot2[i] = (pot2[i-1]<<1)%MOD;
}

int main() {
    FAST_IO;

    precomp();

    int n,m; cin >> n >> m;
    forn(i,m) {
        int x; cin >> x;
        lights[x-1] = true;
    }
    lights[n] = true;

    int rta = fact[n-m], cnt = 0;
    vi cants;
    forn(i,n+1) { // hasta dummy
        if (lights[i]) rta = (rta * (ll)factInv[cnt])%MOD, cants.pb(cnt), cnt = 0;
        else cnt++;
    }

    forsn(i,1-lights[0],(int)cants.size()-1+lights[n-1]) rta = (rta*(ll)pot2[cants[i]])%MOD;

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
