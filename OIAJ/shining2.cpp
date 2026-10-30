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
int const MAXN = 1005;

bool obst[MAXN][MAXN],done[MAXN][MAXN];
int recov[MAXN][MAXN];
int n,m;

int heal(int ti, int tj) {
    int s = 0;
    forsn(i,ti-2,ti+3) forsn(j,tj-2,tj+3) {
        if (abs(i-ti) + abs(j-tj) > 2) continue;
        if (i < 0 || i >= n || j < 0 || j >= m) continue;
        if (recov[i][j] == -1) continue;
        s = max(s,min(10,recov[i][j]));
    }
    return s;
}

int bfs(ii st, int d) {
    queue<pair<ii,int>> Q;
    Q.push({st,0});
    done[st.fst][st.snd] = false;
    int maxi = 0;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
    
        if (recov[e.fst.fst][e.fst.snd] == -1)
            maxi = max(maxi,heal(e.fst.fst,e.fst.snd));

        if (e.snd == d) continue;

        forn(k,4) {
            int ti = e.fst.fst + X[k], tj = e.fst.snd + Y[k];
            if (ti < 0 || ti >= n || tj < 0 || tj >= m) continue;
            if (done[ti][tj]) continue;
            if (obst[ti][tj]) continue;
            done[ti][tj] = true;
            Q.push({{ti,tj},e.snd+1});
        }
    }
    return maxi;
}

int shining2(vector<int> &fila, vector<int> &col, vector<int> &vidaInicial, vector<int> &vidaActual, int d, vector<string> &mapa) {
    n = sz(mapa), m = sz(mapa[0]);
    forn(i,n) forn(j,m) recov[i][j] = -1;
    forn(i,n) forn(j,m) obst[i][j] = (mapa[i][j]=='X');
    forsn(i,1,sz(col)) recov[fila[i]][col[i]] = vidaInicial[i]-vidaActual[i];
    return max(bfs({fila[0],col[0]},d), min(10,vidaInicial[0]-vidaActual[0]));
}
