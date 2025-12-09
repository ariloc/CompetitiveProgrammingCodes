#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

struct DS {
    vi p,r;
    vector<map<int,int>> times;
    vi off,maxi;

    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        off.assign(N,0);
        times.assign(N,{});
        maxi.assign(N,0);
        forn(i,N) p[i] = i;
    }
    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    void merge(int x, int y) {
        int offx = off[x], offy = off[y];
        for (auto &i : times[x]) {
            int idx = i.fst+offx-offy;
            auto it = times[y].find(idx);
            if (it != times[y].end()) {
                (*it).snd += i.snd;
                maxi[y] = max(maxi[y], (*it).snd);
            }
            else {
                times[y][idx] = i.snd;
                maxi[y] = max(maxi[y], i.snd);
            }
        }
    }

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        merge(x,y);
        p[x] = y; 
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS UF;
bitset<MAXN> done, alive;
int col[MAXN], cycidx[MAXN];
vi cyc[MAXN];
int cycs = 0;
vi arr;
vi G[MAXN];
int seen[MAXN];
int rta[MAXN];

vi path;
void dfs(int st) {
    done[st] = true;
    alive[st] = true;
    path.pb(st);

    if (!done[arr[st]]) dfs(arr[st]);
    else if (alive[arr[st]]) {
        dforn(i,path.size()) {
            int x = path[i];
            col[x] = cycs;
            cyc[cycs].pb(x);
            if (path[i] == arr[st])
                break;
        }
        reverse(all(cyc[cycs])); // orden que se pasan pelotas
        cycs++;
    }

    alive[st] = false;
    path.pop_back();
}

void dfs2 (int st) {
    done[st] = true;

    int y = UF.find(st);
    UF.times[y][0] = 1;
    UF.maxi[y] = 1;

    for (auto &i : G[st])
        if (!done[i] && col[i] == -1) { // explorar cada árbol
            dfs2(i);
            UF.off[UF.find(i)]++; // aumentar tiempo
            UF.join(st,i);
        }

    rta[st] = UF.maxi[UF.find(st)];
}

vector<int> payasos3(vector<int> &A) {
    int n = (int)A.size();
    UF.init(n);
    arr = A;

    forn(i,n) col[i] = -1;

    forn(i,n) if (!done[i]) dfs(i);

    forn(i,n) done[i] = false, G[arr[i]].pb(i); // reverse graph
    forn(i,n) if (!done[i] && col[i] != -1) dfs2(i);

    forn(i,cycs) {
        int nc = (int)cyc[i].size();
        forn(j,nc) {
            int idx = UF.find(cyc[i][j]);
            for (auto &k : UF.times[idx]) {
                int auxi = j-(k.fst+UF.off[idx]);
                int mult = (abs(auxi)+nc-1)/nc;
                int idxs = (auxi+nc*mult)%nc;
                seen[idxs] += k.snd;
            }
        }

        int maxi = 0;
        forn(j,nc) maxi = max(maxi,seen[j]);
        forn(j,nc) rta[cyc[i][j]] = max(rta[cyc[i][j]], maxi);

        forn(j,nc) seen[j] = 0;
    }

    vi ret;
    forn(i,n) ret.pb(rta[i]);
    return ret;
}
