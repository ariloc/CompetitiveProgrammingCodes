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
typedef pair<ld,ld> pld;
typedef pair<int,int> ii;

const int INF = 1e9+5;

int main() {
    FAST_IO;

    int n,a; cin >> n >> a;
    ld unit = (180-((180*(n-2))/(ld)n))/(ld)2;
    int ind = n; ld dif = abs(a-unit), acc = unit;
    forsn(i,1,n-2) {
        acc += unit;
        ld aux = abs(a-acc);
        if (aux < dif) dif = aux, ind = n-i;
    }

    cout << "1 2 " << ind;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!