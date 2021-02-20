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

int arr[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    forn(i,n) cin >> arr[i];

    sort(arr,arr+n);

    int rta = arr[n/2];
    bool broke = 0;
    forsn(i,(n+1)/2,n) {
        ll calc = (arr[i]-arr[i-1])*(ll)(i-int(n/2));
        if (k-calc >= 0) rta = arr[i], k -= calc;
        else {rta += k/(i-int(n/2)); broke = 1; break;}
    }

    if (!broke) rta += k/((n+1)/2);

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
