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

int const MAXN = 1005;
int const XD[] = {0,1,0,-1};
int const YD[] = {1,0,-1,0};

vi X,Y;
int id[MAXN][MAXN];
int nxtid = 1;
vector<vi> G;
vector<bool> done;

int update(int x, vi &vec) {
    // duplicamos coords para dejar gaps entre murallas y pasar
    return 2 * (lower_bound(all(vec), x)-vec.begin());
}

void explore(int i, int j) {
    queue<ii> Q;
    Q.push({i,j});
    id[i][j] = nxtid;
    while(!Q.empty()) {
        ii e = Q.front(); Q.pop();
        forn(k,4) {
            int tendX = e.fst + XD[k], tendY = e.snd + YD[k];
            if (tendX < 0 || tendY < 0 || tendX >= MAXN || tendY >= MAXN)
                continue;
            if (id[tendX][tendY]) 
                continue;
            id[tendX][tendY] = nxtid;
            Q.push({tendX,tendY});
        }
    }

    ++nxtid;
}

ii bfs(int id) {
    queue<ii> Q;
    Q.push({id,0});
    done[id] = true;
    int cntmarked = 0, maxtim = 0;
    while (!Q.empty()) {
        ii e = Q.front(); Q.pop();
        ++cntmarked;
        maxtim = max(maxtim, e.snd);
        for (auto &i : G[e.fst])
            if (!done[i]) {
                done[i] = true;
                Q.push({i, e.snd+1});
            }
    }
    return {maxtim, cntmarked};
}

vector<int> herculano(vector<int> &x, vector<int> &y, vector<int> &a, vector<int> &b, vector<int> &t) {
    for (auto &i : x) X.pb(i);
    for (auto &i : y) Y.pb(i);
    X.pb(-1); Y.pb(-1); // dummys para que no queden pegados a la pared (región infinita)
    sort(all(X));
    sort(all(Y));
    X.erase(unique(all(X)), X.end());
    Y.erase(unique(all(Y)), Y.end());

    for (auto &i : x) i = update(i,X);
    for (auto &i : y) i = update(i,Y);

    forn(i,a.size()) {
        int p = a[i], q = b[i];
        ii pc = {x[p],y[p]}, qc = {x[q],y[q]};
        if (pc.fst == qc.fst) {
            if (qc.snd < pc.snd) swap(pc,qc);
            while (pc.snd < qc.snd) {
                id[pc.fst][pc.snd] = -1 - t[i];
                ++pc.snd;
            }
        }
        else {
            if (qc.fst < pc.fst) swap(pc,qc);
            while (pc.fst < qc.fst) {
                id[pc.fst][pc.snd] = -1 - t[i];
                ++pc.fst;
            }
        }
    }

    forn(i,MAXN) forn(j,MAXN)
        if (!id[i][j])
            explore(i,j);

    G = vector<vi>(nxtid);

    // Repetimos lo de antes, pero ahora chequeamos conexiones a ambos lados
    forn(i,a.size()) {
        int p = a[i], q = b[i];
        ii pc = {x[p],y[p]}, qc = {x[q],y[q]};
        if (t[i]) continue; // descartar piedra
        if (pc.fst == qc.fst) {
            if (qc.snd < pc.snd) swap(pc,qc);
            while (pc.snd < qc.snd) {
                ii l1 = {pc.fst-1,pc.snd}, l2 = {pc.fst+1,pc.snd};
                int n1,n2;
                if (l1.fst >= 0 && l1.fst < MAXN && l2.fst >= 0 && l2.fst < MAXN && (n1 = id[l1.fst][l1.snd]) > 0 && (n2 = id[l2.fst][l2.snd]) > 0) {
                    G[n2].pb(n1), G[n1].pb(n2);
                    break;
                }
                ++pc.snd;
            }
        }
        else {
            if (qc.fst < pc.fst) swap(pc,qc);
            while (pc.fst < qc.fst) {
                ii l1 = {pc.fst,pc.snd-1}, l2 = {pc.fst,pc.snd+1};
                int n1,n2;
                if (l1.snd >= 0 && l1.snd < MAXN && l2.snd >= 0 && l2.snd < MAXN && (n1 = id[l1.fst][l1.snd]) > 0 && (n2 = id[l2.fst][l2.snd]) > 0) {
                    G[n2].pb(n1), G[n1].pb(n2);
                    break;
                }
                ++pc.fst;
            }
        }
    }

    // Limpiar grafo
    forn(i,nxtid) {
        sort(all(G[i]));
        G[i].erase(unique(all(G[i])),G[i].end());
    }

    done = vector<bool>(nxtid);
    ii rta = bfs(id[MAXN-1][MAXN-1]);

    vi ret = {rta.fst, nxtid - rta.snd - 1}; // cuántas regiones NO fueron afectadas, y nxtid está enumerado en 1
    return ret;
}
