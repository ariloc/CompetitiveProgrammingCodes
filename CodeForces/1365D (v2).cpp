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

const int MAXN = 54;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

char mat[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        forn(i,MAXN) forn(j,MAXN) done[i][j] = false;
        int n,m; cin >> n >> m;
        forn(i,n) forn(j,m) cin >> mat[i+1][j+1];

        forn(i,n) forn(j,m) {
            if (mat[i+1][j+1] == 'B') {
                forn(k,4) {
                    int tY = i+1+Y[k], tX = j+1+X[k];
                    if (tY <= 0 || tX <= 0 || tY > n || tX > m) continue;
                    if (mat[tY][tX] == '.') mat[tY][tX] = '#';
                }
            }
        }

        queue<ii> Q; // (y,x)
        if (mat[n][m] != '#') Q.push({n,m}), done[n][m] = true;

        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();

            forn(k,4) {
                auto tY = e.fst+Y[k], tX = e.snd+X[k];
                if (tY <= 0 || tX <= 0 || tX > m || tY > n) continue;
                if (done[tY][tX]) continue;
                if (mat[tY][tX] == '#') continue;

                done[tY][tX] = true;
                Q.push({tY,tX});
            }
        }

        bool posib = true;
        forn(i,n) forn(j,m) {
            if (mat[i+1][j+1] == 'G' && !done[i+1][j+1]) posib = false;
            if (mat[i+1][j+1] == 'B' && done[i+1][j+1]) posib = false;
        }

        cout << (posib ? "Yes" : "No") << '\n';
    }

    return 0;
}