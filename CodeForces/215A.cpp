#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 52;

int a[MAXN],b[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) cin >> a[j];
    int m; cin >> m;
    forn(j,m) cin >> b[j];

    int maxi = 0, cnt = 0;
    forn(i,m) forn(j,n) if (!(b[i]%a[j])) {
        int r = b[i]/a[j];
        if (r > maxi) maxi = r, cnt = 0;
        if (r == maxi) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
