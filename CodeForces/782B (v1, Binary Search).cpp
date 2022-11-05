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

const int MAXN = 60005;
const ld EPS = 1e-8;
const ld TOP = 1e9+5;

ld a[MAXN],s[MAXN],n;

pld genRange (int ind, ld x) {
    return {a[ind]-x*s[ind], a[ind]+x*s[ind]};
}

pld rangeIntersect (pld x, pld y) {
    return {max(x.fst,y.fst),min(x.snd,y.snd)};
}

bool isPosib (ld x) {
    pld meetRange = genRange(0,x);
    forsn(i,1,n)
        meetRange = rangeIntersect(meetRange,genRange(i,x));

    return (meetRange.fst <= meetRange.snd);
}

int main() {
    FAST_IO;

    cin >> n;
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> s[i];

    ld low = 0, high = TOP;
    while (high-low > EPS) {
        ld mid = (high+low)/(ld)2;

        if (isPosib(mid)) high = mid;
        else low = mid;
    }

    if (isPosib(low)) high = low;
    cout << fixed << setprecision(8) << high;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!