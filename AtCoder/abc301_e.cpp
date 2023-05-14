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

const int MAXN = 305;
const int MAXC = 18;
const int MAXC2 = 20;
const int INF = 1e9;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

struct edges {
    int v,w;
};

string mat[MAXN];
vector<edges> G[MAXN];
bool done[MAXN][MAXN];
int D[MAXC2][MAXC2]; // with st + nd
int dp[1<<MAXC][MAXC];
int h,w,t;

int bfs (ii st, ii nd) {
    forn(i,h) forn(j,w) done[i][j] = 0;

    queue<pair<ii,int>> Q;
    Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == nd) return e.snd;

        forn(k,4) {
            int tY = e.fst.fst + Y[k], tX = e.fst.snd + X[k];
            if (tY < 0 || tY >= h || tX < 0 || tX >= w) continue;
            if (mat[tY][tX] == '#') continue;
            if (done[tY][tX]) continue;
            done[tY][tX] = true;
            Q.push({{tY,tX},e.snd+1});
        }
    }

    return INF;
}

int main() {
    FAST_IO;

    cin >> h >> w >> t;

    forn(i,h) cin >> mat[i];

    ii st, nd;
    vector<ii> candy;
    forn(i,h) forn(j,w) if (mat[i][j] == 'S') {
        st = {i,j}; break;
    }
    forn(i,h) forn(j,w) if (mat[i][j] == 'G') {
        nd = {i,j}; break;
    }
    int cnt = 0;
    forn(i,h) forn(j,w) if (mat[i][j] == 'o') {
        candy.pb({i,j}); cnt++;
    }

    // cnt is start, cnt+1 is end
    forn(i,MAXC2) forn(j,MAXC2) D[i][j] = INF;
    D[cnt][cnt+1] = D[cnt+1][cnt] = bfs(st,nd);
    forn(i,candy.size()) {
        D[cnt][i] = D[i][cnt] = bfs(st,candy[i]);
        D[cnt+1][i] = D[i][cnt+1] = bfs(candy[i],nd);
    }
    forn(i,candy.size()) forsn(j,i+1,candy.size()) {
        D[i][j] = D[j][i] = bfs(candy[i],candy[j]);
    }
    forn(i,MAXC2) D[i][i] = 0;

    if (D[cnt][cnt+1] > t) {
        cout << -1;
        return 0;
    }

    forn(i,1<<cnt) forn(j,cnt) dp[i][j] = INF;
    forn(j,cnt) dp[(1<<j)][j] = D[cnt][j];
    
    forn(i,1<<cnt) {
        forn(j,cnt) if (i&(1<<j)) forn(k,cnt) {
            if (i&(1<<k) || j == k) continue;
            int mk = i | (1<<k);
            dp[mk][k] = min(dp[mk][k],dp[i][j]+D[j][k]);
        }
    }

    int maxi = 0;
    forn(i,1<<cnt) forn(j,cnt) {
        if (dp[i][j] + D[j][cnt+1] <= t) maxi = max(maxi, __builtin_popcount(i));
    }

    cout << maxi;

    return 0;
}
