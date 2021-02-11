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

const ld EPS = 1e-12;
const ld TOP = 1e16;
const ll MAXOP = 100;
const ll INF = 9e18;
const int MAXN = 1e5+5;

struct pt {
    ld x,y;
    pt (){}
    pt (ld xx, ld yy) : x(xx), y(yy){}
};

pt lairs[MAXN];
int n;

bool allContained (ld r) {
    ld minMax = INF, maxMin = -INF;
    forn(j,n) {
        auto i = lairs[j];
        ld c = 2*r*abs(i.y) - i.y*i.y - i.x*i.x;
        ld d = 2*i.x;

        ld toSqrt = d*d + 4*c;
        if (toSqrt < 0) return false; // no hay intersección;

        ld tSqrt = sqrt(toSqrt);
        ld x1 = (d + tSqrt) / 2, x2 = (d - tSqrt) / 2;
        if (x2 < x1) swap(x1,x2);
        minMax = min(minMax,x2);
        maxMin = max(maxMin,x1);
    }
    return (minMax >= maxMin);
}

int main() {
    scanf("%d",&n);
    ld maxY = 0;
    bool posY = 0, negY = 0;
    forn(i,n) {
        ld x,y; scanf("%Lf %Lf",&x,&y);
        maxY = max(maxY,y);
        if (y < 0) negY = true;
        if (y > 0) posY = true;
        lairs[i] = {x,y};
    }

    if (posY && negY) return puts("-1"), 0;

    ld low = maxY/(ld)2, high = TOP;
    int cnt = MAXOP;
    while (cnt--) {
        ld mid = (high+low)/(ld)2;
        if (allContained(mid)) high = mid;
        else low = mid;
    }

    if (allContained(low)) printf("%.10Lf",low);
    else printf("%.10Lf",high);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
