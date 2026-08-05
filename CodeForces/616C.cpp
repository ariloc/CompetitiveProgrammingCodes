#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;

int const MAXN = 1005;
int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};

char mat[MAXN][MAXN];
char rta[MAXN][MAXN];

struct DS {
    vi p,r;
    vi cnt;

    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        cnt.assign(N,1);
        forn(i,N) p[i] = i;
    }

    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join(int a, int b){
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y;
        cnt[y] += cnt[x];
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS UF;
int n,m;

int id(int i, int j) { return i*m + j; }

int main() {
    FAST_IO;

    cin >> n >> m;

    forn(i,n) forn(j,m) cin >> mat[i][j];

    UF.init(n*m);

    forn(i,n) forn(j,m) {
        if (mat[i][j] == '*') continue;
        forn(k,4) {
            int ti = i + X[k], tj = j + Y[k];
            if (ti < 0 || tj < 0 || ti >= n || tj >= m) continue;
            if (mat[ti][tj] == '*') continue;
            UF.join(id(i,j),id(ti,tj));
        }
    }

    forn(i,n) forn(j,m) rta[i][j] = '.';

    forn(i,n) forn(j,m) {
        if (mat[i][j] == '*') {
            set<int> seen;
            int cnt = 1;
            forn(k,4) {
                int ti = i + X[k], tj = j + Y[k];
                if (ti < 0 || tj < 0 || ti >= n || tj >= m) continue;
                if (mat[ti][tj] == '*') continue;
                if (!seen.count(UF.find(id(ti,tj)))) {
                    cnt += UF.cnt[UF.find(id(ti,tj))];
                    seen.insert(UF.find(id(ti,tj)));
                }
            }
            rta[i][j] = (cnt%10)+'0';
        }
    }

    forn(i,n) {
        forn(j,m) cout << rta[i][j];
        cout << '\n';
    }
    
    return 0;
}
