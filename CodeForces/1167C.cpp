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

const int MAXN = 5e5+5;

int comp[MAXN];

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N,-1);
        r.assign(N,-1);
        forn (i,N) comp[i] = 1;
    }

    int find(int x) {return p[x] == -1 ? x : p[x] = find(p[x]);}

    void join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        if (r[x] > r[y]) {p[y] = x; comp[x] += comp[y];}
        else {
            p[x] = y; comp[y] += comp[x];
            if (r[x] == r[y]) r[y]++;
        }
    }
};

DS UF;

int main() {
    FAST_IO;

    UF.init(MAXN);
    int n,m; cin >> n >> m;

    forn (i,m) {
        int N; cin >> N;
        int prv = -1;
        forn (j,N) {
            int x; cin >> x; x--;
            if (prv != -1) UF.join(x,prv);
            prv = x;
        }
    }

    forn (i,n) cout << comp[UF.find(i)] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!