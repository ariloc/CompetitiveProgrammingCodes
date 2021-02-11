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
const ll TOP = 3e9;
const ll INF = 9e18;

int h[MAXN];
ll tmp[MAXN],w,n;

ll blockCnt (ll myH) {
    forn(i,MAXN) tmp[i] = 0; // reset

    int minR = w, maxL = -1;

    ll add = 0, r = 0;
    forn(l,w) {
        while (r < w && myH-r+l > h[r])
            add +=(myH-r+l)-h[r], r++;
        if (r >= w) break;
        maxL = l; // si sigo siendo válido
        tmp[l] += add;
        add -= max(0LL,myH-h[l]);
        add += r-l-1;
    }

    ll l = w-1; add = 0;
    dforn(rr,w) {
        while (l >= 0 && myH-rr+l > h[l])
            add += (myH-rr+l)-h[l], l--;
        if (l < 0) break;
        minR = rr; // si sigo siendo válido
        tmp[rr] += add - myH + h[rr]; // ya conté mi dif en el anterior así que no repito
        add -= max(0LL,myH-h[rr]);
        add += rr-l-1;
    }

    ll mini = INF;
    forsn(i,minR,maxL+1) mini = min(mini,tmp[i]);// cerr << myH << ' ' << tmp[i] << endl;
    return mini;
}

int main() {
    FAST_IO;

    freopen("landscape.in","r",stdin);
    freopen("landscape.out","w",stdout);

    cin >> w >> n;
    int maxi = -1;
    forn(i,w) cin >> h[i], maxi = max(maxi,h[i]);

    ll low = maxi, high = TOP;
    while (high-low > 1) {
        ll mid = (low+high)/2LL;
        if (blockCnt(mid) <= n) low = mid;
        else high = mid;
    }

    // la rta es low
    if (blockCnt(high) <= n) low = high;

    cout << low;

    //cerr << blockCnt(5);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
