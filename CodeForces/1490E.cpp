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

ii arr[MAXN];
ll dp[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i].fst, arr[i].snd = i;

        sort(arr,arr+n);
        forn(i,n) dp[i] = arr[i].fst;
        forsn(i,1,n) dp[i] += dp[i-1];

        vi prob; prob.pb(arr[n-1].snd);
        dforn(i,n-1) {
            if (dp[i] >= arr[i+1].fst) prob.pb(arr[i].snd); // mejor caso cuando a todos los que seguro gano, acumulo para el más grande
            else break;
        }

        sort(all(prob));
        cout << prob.size() << '\n';
        for (auto &i : prob) cout << i+1 << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
