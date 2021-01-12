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

struct pt {
    int x,y;
    pt(int xx, int yy) : x(xx), y(yy){}
    pt(){}

    pt normMod() {
        int dcm = __gcd(abs(x),abs(y));
        return {x/dcm,y/dcm};
    }

    bool operator< (const pt &o) const {
        if (o.x == x) return y < o.y;
        return x < o.x;
    }
};

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;

        map<pt,int> vec;
        forn(j,n) {
            int x,y,u,v; cin >> x >> y >> u >> v;
            pt me = {u-x,v-y};
            me = me.normMod();
            vec[me]++;
        }
        ll r = 0;
        for (auto &j : vec) {
            pt op = {-j.fst.x,-j.fst.y};
            if (!vec.count(op)) continue;
            r += (ll)j.snd*vec[op];
        }

        cout << r/2LL << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
