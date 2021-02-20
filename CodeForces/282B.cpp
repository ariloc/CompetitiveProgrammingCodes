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

const int MAXN = 1e6+5;

pair<ii,int> arr[MAXN];
int dp[MAXN];
char rta[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i].fst.fst >> arr[i].fst.snd, arr[i].snd = i;

    dforn(i,n) dp[i] += dp[i+1]+arr[i].fst.snd;
    ll s = 0, cut = -2;
    forn(i,n) {
        s += arr[i].fst.fst;
        if (abs(s-dp[i+1]) <= 500) cut = i;
    }
    if (dp[0] <= 500) cut = -1;

    if (cut == -2) cout << "-1";
    else {
        forn(i,cut+1) rta[arr[i].snd] = 'A';
        forsn(i,cut+1,n) rta[arr[i].snd] = 'G';
        cout << rta; // inicializado global, tiene ya un 0, terminador puesto
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
