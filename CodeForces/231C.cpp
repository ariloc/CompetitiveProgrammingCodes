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

const int MAXN = 1e5+5;

int arr[MAXN];
ll dp[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i+1];

    sort(arr+1,arr+n+1);
    forn(i,n) dp[i+1] = arr[i+1];
    forsn(i,1,n+1) dp[i] += dp[i-1];

    ll l = 1, maxi = 1, num = arr[1];
    forsn(r,1,n+1) {
        while( (((r-l+1) * (ll)arr[r]) - dp[r] + dp[l-1]) > k )
            l++;
        int cnt = r-l+1;
        if (cnt > maxi) maxi = cnt, num = arr[r];
    }

    cout << maxi << ' ' << num;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!