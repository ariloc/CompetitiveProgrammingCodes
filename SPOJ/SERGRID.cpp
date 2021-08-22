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

const int MAXN = 505;

char grid[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%s",grid[i]);
    forn(i,n) forn(j,m) grid[i][j] -= '0';

    queue< pair<ii,int> > Q;
    Q.push({{0,0},0});

    int rta = -1;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        ii c = e.fst;

        if (c.fst == n-1 && c.snd == m-1) {rta = e.snd; break;}

        int val = grid[c.fst][c.snd];
        int X[] = {0,val,0,-val};
        int Y[] = {val,0,-val,0};

        forn(k,4) {
            int tY = c.fst + Y[k], tX = c.snd + X[k];
            if (tY < 0 || tY >= n || tX >= m || tX < 0) continue;
            if (done[tY][tX]) continue;
            done[tY][tX] = true;
            Q.push({{tY,tX},e.snd+1});
        }
    }

    cout << rta;

    return 0;
}