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
const ll INF = 9e18;

ll arr[MAXN],n;

int main() {
    FAST_IO;

    ll k; cin >> n >> k;
    forn(i,n) cin >> arr[i];

    sort(arr,arr+n);
    int med = arr[n/2]; ll acc = 0;
    forn(i,n) acc += abs(arr[i]-med);
    if (acc <= k) return cout << 0, 0; // caso que puedo hacer todos iguales, mínimo movs es la mediana

    ll l = 0, r = n-1, maxi = arr[n-1], mini = arr[0];
    ll costL = 1, costR = 1;
    while (k > 0 && l < r) {
        if (costL < costR) {
            int tmp = min(k/costL,arr[l+1]-arr[l]);
            mini += tmp; k -= tmp*costL;
            if (tmp == arr[l+1]-arr[l]) costL++;
            l++;
        }
        else {
            int tmp = min(k/costR,arr[r]-arr[r-1]);
            maxi -= tmp; k -= tmp*costR;
            if (tmp == arr[r]-arr[r-1]) costR++;
            r--;
        }
    }

    cout << maxi-mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
