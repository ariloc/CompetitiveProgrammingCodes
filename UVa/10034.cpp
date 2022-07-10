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

const int MAXN = 102;

struct pt {
    double x,y;
};

struct edge {
    int a,b;
    double w;

    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }
    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[y] == r[x]) r[y]++;
        return true;
    }
};

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        DS MST;
        vector<pt> freckles;
        vector<edge> edges;

        int n; cin >> n; MST.init(n);
        forn(j,n) {
            double x,y; cin >> x >> y;
            freckles.pb({x,y});
        }

        forn(j,n) forsn(k,j+1,n)
            edges.pb({j,k,hypot(abs(freckles[j].x-freckles[k].x),abs(freckles[j].y-freckles[k].y))});

        sort(all(edges));

        long double trace = 0;
        for (auto &j : edges) if (MST.join(j.a,j.b)) trace += j.w;

        cout << fixed << setprecision(2) << trace << '\n';
        if (i+1 < t) cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
