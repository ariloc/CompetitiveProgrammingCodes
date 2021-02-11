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

const int MAXN = 5002;

struct pt {
    ll x,y;
    pt(){}
    pt(ll xx, ll yy) : x(xx),y(yy){}

    ll norm2() {return (*this) * (*this);} // modulo of vector, squared
    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
    ll operator% (const pt &o) const {return x*o.y - y*o.x;} // cross product
    ll operator* (const pt &o) const {return x*o.x + y*o.y;} // dot product
};

vector<pt> inp;
vi inds;
bitset<MAXN> done;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) {
        int a,b; cin >> a >> b;
        inp.pb({a,b});
    }

    int idx = 0;
    while ((int)inds.size() < n) {
        done[idx] = true; inds.pb(idx);
        if ((int)inds.size() >= n) break;
        ld maxi = 0; int ch = -1;
        forn(j,n) {
            if (done[j]) continue;
            if ((inp[idx]-inp[j]).norm2() > maxi) maxi = (inp[idx]-inp[j]).norm2(), ch = j;
        }
        done[ch] = true;
        idx = ch;
    }

    forsn(j,1,n-1) {
        pt vec1 = (inp[inds[j-1]]-inp[inds[j]]), vec2 = (inp[inds[j+1]]-inp[inds[j]]);
        ll prodEsc = vec1*vec2;

        if (prodEsc <= 0) return cout << -1, 0;
    }

    for (auto &i : inds) cout << i+1 << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
