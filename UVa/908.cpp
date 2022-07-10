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

const int INF1 = 1000;
const int INF = 1e9+5;

struct edge {
    int a,b,w;

    bool operator< (const edge &o) const{
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
        p[x] = y; if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS MST;

int main() {
    FAST_IO;

    while (true) {
        vector<edge> edges;
        int n; cin >> n;
        MST.init(n);
        ll orig = 0;
        forn(i,n-1) {
            int a,b,w; cin >> a >> b >> w; a--; b--;
            edges.pb({a,b,w});
            orig += w;
        }
        int k; cin >> k;
        forn (i,k) {
            int a,b,w; cin >> a >> b >> w; a--; b--;
            edges.pb({a,b,w});
        }
        int m; cin >> m; cin.ignore();
        forn(i,m) cin.ignore(INF1,'\n'); // no me importa lo viejo, porque igual no es mejor

        sort(all(edges));

        ll cost = 0;
        forn(i,edges.size()) if(MST.join(edges[i].a,edges[i].b)) cost += edges[i].w;

        cout << orig << '\n' << cost << '\n';
        string tmp;
        if (!getline(cin,tmp)) break;
        else cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
