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

const int MAXN = 3e5+5;
const int INF = 2e9;

ll pos[MAXN], pop[MAXN];
ll dp[MAXN];

int main() {
    FAST_IO;
    
    int n; cin >> n;
    forn(i,n) cin >> pos[i+1];
    forn(i,n) cin >> pop[i+1];

    forsn(i,1,n+1) dp[i] = pop[i];
    forsn(i,1,n+1) dp[i] += dp[i-1];

    ll calc = 0;
    forsn(i,2,n+1) calc += pop[i] * abs(pos[i] - pos[1]);

    ll mini = calc, choose = 1;
    forsn(i,2,n+1) {
        ll dist = abs(pos[i]-pos[i-1]);
        calc -= dist * (dp[n] - dp[i-1]);
        calc += dist * dp[i-1];
        if (calc < mini) mini = calc, choose = i;
    }

    cout << choose-1;

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!