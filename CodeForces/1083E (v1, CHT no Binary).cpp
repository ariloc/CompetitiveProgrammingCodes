#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e6+5;

struct rect {
    int x,y;
    ll a;

    bool operator< (const rect &o) const {
        return x < o.x;
    }
};

struct ln {
    ll m,h;
    ln(ll a, ll b) : m(a), h(b){}
    ll eval(ll x)  { return m*x + h; }
    ld intersectX (ln &o) { return (o.h-h) / (ld)(m-o.m); }
};

rect rectang[MAXN];
deque<ln> cht;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x,y; ll a; cin >> x >> y >> a;
        rectang[i] = {x,y,a};
    }
    
    // sorted by increasing x -> sorted by decreasing y (no nested rectangles)
    sort(rectang,rectang+n);

    ll rta = 0;
    cht.push_front({0,0});
    forn(i,n) {
        ll act = rectang[i].x * (ll)rectang[i].y - rectang[i].a;
        while ((int)cht.size() >= 2 && cht.back().eval(rectang[i].y) <= cht[(int)cht.size()-2].eval(rectang[i].y)) cht.pop_back();
        ll cur = act + cht.back().eval(rectang[i].y);
        rta = max(rta, cur);
        ln curln = {-rectang[i].x,cur};
        while ((int)cht.size() >= 2 && curln.intersectX(cht.front()) >= cht.front().intersectX(cht[1])) cht.pop_front();
        cht.push_front(curln);
    }

    cout << rta << '\n';

    return 0;
}
