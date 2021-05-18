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

const int MAXN = 5e5+2;

struct DS {
    vi p,r,cmp;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        cmp.assign(N,1);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    bool join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; cmp[y] += cmp[x];
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS UF;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,m; cin >> n >> m;
        UF.init(3*n+5);

        vi matching,indSet;
        forn(i,m) {
            int u,v; cin >> u >> v; u--, v--;
            
            int id1 = UF.find(u), id2 = UF.find(v);
            if (UF.cmp[id1]+UF.cmp[id2] <= 2) 
                UF.join(id1,id2), matching.pb(i);
        }

        forn(i,3*n) if (UF.cmp[UF.find(i)] == 1) indSet.pb(i);

        if ((int)indSet.size() >= n) {
            cout << "IndSet\n";
            forn(i,n) cout << indSet[i]+1 << ' ';
        }
        else {
            cout << "Matching\n";
            forn(i,n) cout << matching[i]+1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!