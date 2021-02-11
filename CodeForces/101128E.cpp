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

const int MAXN = 2010;
const ll MOD = (1LL<<31)-1;
ll ranges[MAXN][2][2],arr[MAXN]; // 0 is left, 1 is right || el segundo parámetro es un switch

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n+1) cin >> arr[i];

    ranges[arr[0]][0][1]++, ranges[arr[1]][1][1]++;

    ll rta = 0;
    forsn(i,2,n+2) {
        ll mult = 0;
        forn(j,MAXN) ranges[j][0][i&1] = ranges[j][1][i&1] = 0; // reset del siguiente
        forn(j,arr[i]) {
            ranges[j][0][i&1] += ranges[j][0][!(i&1)],  ranges[j][0][i&1] %= MOD;
            ranges[arr[i]][1][i&1] += ranges[j][0][!(i&1)], ranges[arr[i]][1][i&1] %= MOD;
            mult = (mult+ranges[j][0][!(i&1)])%MOD;
        }
        forsn(j,arr[i]+1,MAXN) {
            ranges[j][1][i&1] += ranges[j][1][!(i&1)], ranges[j][1][i&1] %= MOD;
            ranges[arr[i]][0][i&1] += ranges[j][1][!(i&1)], ranges[arr[i]][0][i&1] %= MOD;
            mult = (mult+ranges[j][1][!(i&1)])%MOD;
        }
        rta = mult;
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
