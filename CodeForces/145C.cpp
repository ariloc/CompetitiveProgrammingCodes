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

const int MAXN = 1e5+2;
const int MOD = 1e9+7;

int fact[MAXN],factInv[MAXN],inv[MAXN];

void precomp() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    factInv[0] = 1;
    forsn(i,1,MAXN) factInv[i] = (factInv[i-1]*(ll)inv[i])%MOD;
}

int nCr (int n, int r) {
    if (r > n) return 0;
    return (((fact[n]*(ll)factInv[r])%MOD)*(ll)factInv[n-r])%MOD;
}

bool isLucky (int x) {
    while (x) {
        int d = x%10;
        if (d != 4 && d != 7) return false;
        x /= 10;
    }
    return true;
}

void sumMod (int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int dp[MAXN];
map<int,int> cnt;

int main() {
    precomp();

    int n,k; scanf("%d %d",&n,&k);
    int bl = 0;
    forn(i,n) {
        int x; scanf("%d",&x);
        if (isLucky(x)) cnt[x]++;
        else bl++;
    }

    for (auto &i : cnt) {
        dforsn(j,2,k+1) sumMod(dp[j],(dp[j-1]*(ll)(i.snd))%MOD);
        sumMod(dp[1],i.snd);
    }

    int rta = 0;
    dp[0] = 1;
    forn(j,k+1) sumMod(rta,((ll)dp[j]*nCr(bl,k-j))%MOD);

    printf("%d",rta);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
