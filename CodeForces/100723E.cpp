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

const int MAXD = 1005;
const int TOPP = 1e6+5;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

struct nodoBFS {
    ii v; int len;
};

int dists[MAXD][MAXD],D[MAXD][MAXD],N,Xdim,Ydim;
bool done[MAXD][MAXD];

int minDist (int mid, ii st, ii nd) {
    forn(i,Ydim) forn(j,Xdim) done[i][j] = 0; // reset
    if (dists[st.fst][st.snd] < mid) return -1;
    queue<pair<ii,int>> Q; Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst.fst == nd.fst && e.fst.snd == nd.snd) return e.snd;

        forn(k,4) {
            int tY = e.fst.fst+Y[k], tX = e.fst.snd+X[k];
            if (tY < 0 || tX < 0 || tY >= Ydim || tX >= Xdim) continue;
            if (done[tY][tX] || dists[tY][tX] < mid) continue;
            done[tY][tX] = true;
            Q.push({{tY,tX},e.snd+1});
        }
    }
    return -1;
}

int main() {
    int t; scanf("%d",&t);

    forn(o,t) {
        scanf("%d %d %d",&N,&Xdim,&Ydim);

        forn(i,Ydim) forn(j,Xdim) dists[i][j] = D[i][j] = -1;

        ii st,nd; scanf("%d %d %d %d",&st.fst,&st.snd,&nd.fst,&nd.snd);
        swap(st.fst,st.snd), swap(nd.fst,nd.snd); // así lo tengo (y,x)

        queue<pair<ii,int>> Q;
        forn(i,N) {
            int auxx,auxy; scanf("%d %d",&auxx,&auxy);
            Q.push({{auxy,auxx},0}), dists[auxy][auxx] = 0;
        }

        // BFS
        while (!Q.empty()) { // min dists a base enemiga
            auto e = Q.front(); Q.pop();

            forn(k,4) {
                int tY = e.fst.fst+Y[k], tX = e.fst.snd+X[k];
                if (tY < 0 || tX < 0 || tY >= Ydim || tX >= Xdim) continue;
                if (dists[tY][tX] != -1) continue;
                dists[tY][tX] = e.snd+1;
                Q.push({{tY,tX},e.snd+1});
            }
        }

        // binary search en el costo
        int low = 0, high = TOPP;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (minDist(mid,st,nd) != -1) low = mid;
            else high = mid;
        }
        if (minDist(high,st,nd) != -1) low = high;
        cout << low << ' ' << minDist(low,st,nd) << '\n';
    }


    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
