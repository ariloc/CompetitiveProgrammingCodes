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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 1005;

int ind[MAXN][MAXN], prox_libre = 0;
int col[MAXN*MAXN];
bitset<MAXN*MAXN> isVert;
vi G[MAXN*MAXN];
int inDeg[MAXN*MAXN], row[MAXN*MAXN];

vector<string> gravitas(vector<string> &g) {
    int n = (int)g.size(), m = (int)g[0].size();

    forn(i,n) forn(j,m) {
        if (g[i][j] == 'V') 
            ind[i][j] = ind[i-1][j] = prox_libre, col[prox_libre] = j, isVert[prox_libre++] = true;
        if (g[i][j] == '<') 
            ind[i][j] = ind[i][j+1] = prox_libre, col[prox_libre] = j, isVert[prox_libre++] = false;
    }

    forn(j,m) {
        int lind = -1;
        dforn(i,n) {
            if (g[i][j] != '.' && g[i][j] != 'A' && lind != -1)
                G[lind].pb(ind[i][j]), inDeg[ind[i][j]]++;
            if (g[i][j] != '.') lind = ind[i][j];
        }
    }

    queue<int> Q;
    forn(i,prox_libre) if (!inDeg[i]) Q.push(i), row[i] = 0;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            row[i] = max(row[i], row[e] + 1 + isVert[e]);
            if (!(--inDeg[i])) Q.push(i);
        }
    }

    vector<string> rta(n, string(m, '.'));
    forn(i,prox_libre) {
        rta[n-1 - row[i]][col[i]] = (isVert[i] ? 'V' : '<');
        rta[n-1 - row[i] - isVert[i]][col[i] + (!isVert[i])] = (isVert[i] ? 'A' : '>');
    }

    return rta;
}
