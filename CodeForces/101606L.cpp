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

const double INF = 1e7;
const double EPS = 1e-6; // margin of error
const int MAXN = 1e6+5;

struct pt {
    ll x,y;
    pt(ll xx, ll yy) : x(xx),y(yy){}
    pt(){}

    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
    ll operator* (const pt &o) const {return x*o.x + y*o.y;} // dot product
    ll norm2() {return (*this) * (*this);} // modulo of vector, squared
    bool operator< (const pt &o) const { // chull sort cmp
        return (x < o.x || (x == o.x && y < o.y));
    }

    pt normGcd() {
        ll dcm = __gcd(abs(x),abs(y));
        pt aux = (*this);
        aux.x /= dcm; aux.y /= dcm;
        return aux;
    }
};

map<pt,vector<pair<ll,ll>>> vec;
int LIS[MAXN];

int main() {
    FAST_IO;

    pt tv; cin >> tv.x >> tv.y;
    int n; cin >> n;
    forn(j,n) {
        pt me; cin >> me.x >> me.y;
        int h; cin >> h;
        pt toPush = tv-me;
        vec[toPush.normGcd()].pb({toPush.norm2(),h});
    }

    int cnt = 0;
    for (auto &i : vec) {
        sort(all(i.snd)); // ordenamos

        // y hacemos LIS
        int lis_nd = 0;
        for (auto &j : i.snd) {
            int pos = lower_bound(LIS,LIS+lis_nd,j.snd)-LIS;
            LIS[pos] = j.snd;
            if (pos+1 > lis_nd) lis_nd = pos+1;
        }

        cnt += lis_nd;
    }

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
