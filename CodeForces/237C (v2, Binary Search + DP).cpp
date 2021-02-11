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
const int INF = 1e9+5;

int dp[MAXN];
bitset<MAXN> done;

void criba() {
    for (int i = 4; i < MAXN; i+=2) done[i] = true;
    for (int i = 3; i*i <= MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true;

    forsn(i,2,MAXN) if (!done[i]) dp[i]++;
}

int primesCnt (int a, int b, int l) {
    int mini = INF;
    forsn(i,a,b-l+2) mini = min(mini,dp[i+l-1]-dp[i-1]);
    return mini;
}

int main() {
    FAST_IO;

    criba();
    forsn(i,1,MAXN) dp[i] += dp[i-1];

    int a,b,k; cin >> a >> b >> k;

    int low = 1, high = b-a+1;
    while (high-low > 1) {
        int mid = (high+low)/2;
        if (primesCnt(a,b,mid) >= k) high = mid;
        else low = mid;
    }

    if (primesCnt(a,b,low) >= k) high = low;
    if (!(primesCnt(a,b,high) >= k)) return cout << -1, 0;
    cout << high;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
