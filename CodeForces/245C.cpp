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

const int MAXN = 105;

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    if (!(n&1) || n == 1) return cout << -1, 0; // nunca puedo vaciar el último, y si es uno tampoco
    forn(i,n) cin >> arr[i];

    int mov = 0;
    for (int i = n-2; i >= 0; i -= 2) {
        int aux = max(arr[i],arr[i+1]); mov += aux;
        arr[i/2] = max(0,arr[i/2]-aux), arr[i] = arr[i+1] = 0;
    }

    cout << mov+arr[0];

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
