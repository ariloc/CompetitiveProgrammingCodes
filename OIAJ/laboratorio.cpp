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

int const MAXN = 2e5+5;
int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};

struct DS {
    vi p,r,tam;
    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        tam.assign(N,1);
        forn(i,N) p[i] = i;
    }
    int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; 
        if (r[x] == r[y]) r[y]++;
        tam[y] += tam[x];
        return true;
    }
};

DS UF;
bitset<MAXN> done;
vi G[MAXN];
set<int> prohib;

void bfs(int st, int onest, vector<string> &mapa) {
    queue<int> Q;
    Q.push(st);
    done[st] = true;
    while (!Q.empty()) {
        int e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            if (prohib.count(i)) continue;
            if (done[i]) continue;

            done[i] = true;
            UF.join(e,i);
            Q.push(i);
        }
    }
}

vector<int> laboratorio(vector<string> mapa, vector<int> perrosF, vector<int> perrosC) {
    int n = (int)mapa.size();
    int m = (int)mapa[0].size();
    UF.init(n*m+5);

    forn(i,perrosF.size())
        prohib.insert(perrosF[i]*m + perrosC[i]);

    int onest = n*m;
    UF.tam[onest] = 0;

    forn(i,n) forn(j,m) forn(k,4) {
        int tx = i + X[k], ty = j + Y[k];
        if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
        if (mapa[tx][ty] == '#') continue;
        G[i*m+j].pb({tx*m+ty});
    }

    forn(i,n) forn(j,m)
        if (mapa[i][j] == 'E') {
            G[i*m+j].pb(onest), G[onest].pb(i*m+j);
        }

    forn(i,n) forn(j,m)
        if (mapa[i][j] != '#' && !prohib.count(i*m+j) && !done[i*m+j])
            bfs(i*m+j,onest,mapa);

    vi rta((int)perrosF.size());
    dforn(i,perrosF.size()) {
        rta[i] = UF.tam[UF.find(onest)];

        int cur = perrosF[i]*m + perrosC[i];
        prohib.erase(cur);
        for (auto &e : G[cur]) 
            if (!prohib.count(e)) UF.join(cur,e);
    }

    return rta;
}


#ifndef EVAL
    #include <iostream>

    int main() {
        int N,M,P;
        cin >> N >> M >> P;
        vector<string> mapa;
        mapa.reserve(N);
        for (int i=0;i<N;i++) {
            string fila; cin >> fila;
            mapa.push_back(fila);
        }
        vector<int> perrosF, perrosC;
        perrosF.reserve(P);
        perrosC.reserve(P);
        for (int i=0;i<P;i++) {
            int f,c; cin >> f >> c;
            perrosF.push_back(f);
            perrosC.push_back(c);
        }
        vector<int> ret = laboratorio(mapa, perrosF, perrosC);
        for (int i=0;i<int(ret.size());i++) {
            if (i > 0)
                cout << " ";
            cout << ret[i];
        }
        cout << endl;
    }
#endif
