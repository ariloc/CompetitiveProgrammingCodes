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

const int MAXN = 2005;

struct pt {
    int x,y;
    pt (int x, int y) : x(x), y(y){}
    pt(){}

    pt operator+ (const pt &o) const {return pt(x+o.x, y+o.y);}
    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
    bool operator< (const pt &o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
    pt normalize() {
        pt aux = *this;
        int dcm = __gcd(aux.x, aux.y);
        aux.x /= dcm, aux.y /= dcm;
        if (aux.x < 0 || (!aux.x && aux.y < 0))
            aux.x *= -1, aux.y *= -1;
        return aux;
    }
};

vector<pt> lst;

ll nC3 (ll n) {
    return n*(n-1)*(n-2)/6LL;
}

ll nC2 (ll n) {
    return n*(n-1)/2LL;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x,y; cin >> x >> y;
        lst.pb(pt(x,y));
    }

    ll r = nC3(n);

    forn(i,n) {
        map<pt,int> vecs;
        forsn(j,i+1,n) 
            vecs[(lst[j]-lst[i]).normalize()]++;
        for (auto &j : vecs) r -= nC2(j.snd);
    }

    cout << r;

    return 0;
}