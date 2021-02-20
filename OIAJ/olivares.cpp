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

const int MAXN = 1205;

pair<ll,bool> radios[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x,y; cin >> x >> y;
        radios[i] = {x*x+y*y,(x>0)};
    }

    sort(radios,radios+n);

    int acc = 0, cnt = 0; ll rta = 0;
    forn(i,n) {
        if (i && radios[i].fst != radios[i-1].fst && acc > cnt)
            cnt = acc, rta = radios[i-1].fst;
        acc += (radios[i].snd ? 1 : -1);
    }
    if (acc > cnt) rta = radios[n-1].fst;

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
