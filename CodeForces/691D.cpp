#include <bits/stdc++.h>

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

const int MAXN = 1e6+5;

set<int> comp[MAXN];

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N,-1);
        r.assign(N,-1);
    }

    int find(int x) {return p[x] == -1 ? x : p[x] = find(p[x]);}
    void join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (r[x] > r[y]) {
            p[y] = x;
            for (auto &i : comp[y]) comp[x].insert(i);
        }
        else {
            p[x] = y;
            for (auto &i : comp[x]) comp[y].insert(i);
            if (r[x] == r[y]) r[y]++;
        }
    }
};

DS UF;

int main() {
    FAST_IO;

    UF.init(MAXN-1);
    int n,m; cin >> n >> m;

    forn(i,n) {int x; cin >> x; comp[i].insert(x);}

    forn(i,m) {
        int a,b; cin >> a >> b; a--; b--;
        UF.join(a,b);
    }

    forn (i,n) {
        int myComp = UF.find(i);
        auto it = comp[myComp].rbegin();
        cout << *it << ' ';
        comp[myComp].erase(*it);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
