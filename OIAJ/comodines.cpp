#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};
int const MAXC = 1005;

struct DS {
    vi p,r,tam,com;

    void init(int N) {
        r.assign(N,0);
        p.assign(N,0);
        tam.assign(N,1);
        com.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y;
        tam[y] += tam[x];
        com[y] += com[x];
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

vector<vector<bool>> done;
vector<vi> tab;
int last[MAXC];
int n,m;
DS UF;

void bfs(int si, int sj) {
    int cur = tab[si][sj];
    queue<ii> Q;
    done[si][sj] = true;
    Q.push({si,sj});
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        UF.join(si*m+sj, e.fst*m+e.snd);

        forn(k,4) {
            int ti = e.fst + X[k], tj = e.snd + Y[k];
            if (ti < 0 || ti >= n || tj < 0 || tj >= m) continue;
            if (tab[ti][tj] != cur) continue;
            if (done[ti][tj]) continue;
            done[ti][tj] = true;
            Q.push({ti,tj});
        }
    }
}

void merge(int si, int sj) {
    queue<ii> Q;
    done[si][sj] = true;
    Q.push({si,sj});
    vector<ii> seen;
    int cnt = 0;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        ++cnt;

        forn(k,4) {
            int ti = e.fst + X[k], tj = e.snd + Y[k];
            if (ti < 0 || ti >= n || tj < 0 || tj >= m) continue;
            if (tab[ti][tj]) {
                if (last[tab[ti][tj]] == -1) {
                    last[tab[ti][tj]] = ti*m+tj;
                    seen.pb({tab[ti][tj],ti*m+tj});
                }
                UF.join(ti*m+tj,last[tab[ti][tj]]);
                continue;
            }
            if (done[ti][tj]) continue;
            done[ti][tj] = true;
            Q.push({ti,tj});
        }
    }
    for (auto &j : seen) {
        UF.com[UF.find(j.snd)] += cnt;
        last[j.fst] = -1;
    }
}

int comodines(vector<vector<int> > grilla) {
    n = sz(grilla), m = sz(grilla[0]);
    tab = grilla;
    done = vector<vector<bool>>(n,vector<bool>(m,false));
    UF.init(n*m);
    forn(i,n) forn(j,m) if (!done[i][j] && tab[i][j]) bfs(i,j);
    fill(last,last+MAXC,-1);
    forn(i,n) forn(j,m) if (!done[i][j] && !tab[i][j]) merge(i,j);
    int maxi = 0;
    forn(i,n) forn(j,m) {
        int cmp = UF.find(i*m+j);
        maxi = max(maxi,UF.tam[cmp]+UF.com[cmp]);
    }
    return maxi;
}
