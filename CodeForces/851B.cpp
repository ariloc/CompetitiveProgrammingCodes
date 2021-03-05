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

struct pt {
    ll x,y;
    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    ll operator% (const pt &o) const {return x*o.y - y*o.x;}
    bool colineal (const pt &a, const pt &b) {
        return !((b-a)%(*this-a));
    }
};

int main() {
    FAST_IO;

    pt a,b,c; cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    pt vec1 = (b-a), vec2 = (c-b); // pensé que también tenía que ir también de c->a, oops
    cout << (a.colineal(b,c) || (vec1.x*vec1.x + vec1.y*vec1.y) != (vec2.x*vec2.x + vec2.y*vec2.y)  ? "No" : "Yes");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
