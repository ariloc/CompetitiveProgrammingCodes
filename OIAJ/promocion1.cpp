#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1005;
int const MAXC = 1005;
int const INF = 2e9;

vector<ii> prices[MAXN];
int fb[MAXC];

int n,c;
int timer;

void inicializar(vector<int> &P, int C, int Q) {
    n = (int)P.size();
    timer = 1;
    forn(i,n) prices[i].pb({0,P[i]});
    c = C;
    forn(i,c) fb[i] = -1;
}

int comprar(int c, int p) {
    if (fb[c] == -1) {
        fb[c] = timer++;
        return prices[p].back().snd;
    }
    int mini = INF;
    int idx = (int)prices[p].size();
    forn(i,prices[p].size()) {
        if (prices[p][i].fst > fb[c]) {
            idx = i; break;
        }
    }
    forsn(i,max(0,idx-1),prices[p].size()) {
        mini = min(mini, prices[p][i].snd);
    }
    
    return mini;
}

void cambiar(int p, int v) {
    prices[p].pb({timer++, v});
}
