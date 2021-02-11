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

const ll TOP = 1e12;
const ld EPS = 1e-10;

ld calc (ll x, ll c, ll h) {
    return (x*h+(x-1)*c)/(ld)(x*2-1);
}

int main() {
    FAST_IO;

    int T; cin >> T;
    forn(i,T) {
        ll h,c,t; cin >> h >> c >> t;

        ld dif = abs(t-h); ll cnt = 1;
        if (abs(((c+h)/(ld)2)-t) < dif) dif = abs(((c+h)/(ld)2)-t), cnt = 2;

        ll low = 1, high = TOP;
        while (high-low > 1) {
            ll mid = (high+low)/2;
        //cerr << calc(mid,c,h) << ' ' << t << ' ' << dif << ' ' << mid << endl;
            if ( calc(mid,c,h) > t) low = mid;
            else high = mid;
        }

        if (abs(calc(low,c,h)-t) < dif) dif = abs(calc(low,c,h)-t), cnt = 2*low-1;
        if (abs(calc(high,c,h)-t) < dif) cnt = 2*high-1;

        cout << cnt << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
