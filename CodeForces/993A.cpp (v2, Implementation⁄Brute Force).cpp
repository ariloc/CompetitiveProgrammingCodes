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

const int INF = 1e9+5;

struct pt {
    ld x,y;

    ld operator% (const pt &o) const {return x*o.y - y*o.x;}
    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    int side (const pt &a, const pt &b) {
        ld v = ((b-a)%(*this-a));
        if (!v) return 0;
        if (v > 0) return 1;
        return 2;
    }
};

pt sq1[4], sq2[4];

pt centerPoint (pt a[]) {
    ld miniX = INF, maxiX = -INF, miniY = INF, maxiY = -INF;
    forn(i,4) {
        miniX = min(miniX,a[i].x);
        maxiX = max(maxiX,a[i].x);
        miniY = min(miniY,a[i].y);
        maxiY = max(maxiY,a[i].y);
    }
    return {(miniX+maxiX)/2.0,(maxiY+miniY)/2.0};
}

bool touch (pt x, pt b[]) {
    int cnt[3] = {0,0,0};
    forn(j,4) cnt[x.side(b[j],b[(j+1)%4])]++;
    if (cnt[1] && cnt[2]) return 0;
    return 1;
}

int main() {
    FAST_IO;

    forn(i,4) cin >> sq1[i].x >> sq1[i].y;
    forn(i,4) cin >> sq2[i].x >> sq2[i].y;

    bool cond = 0;
    forn(i,4) cond |= touch(sq1[i],sq2)|touch(sq2[i],sq1);
    pt ctr1 = centerPoint(sq1), ctr2 = centerPoint(sq2);
    cond |= touch(ctr1,sq2)|touch(ctr2,sq1);

    cout << (cond ? "YES" : "NO");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
