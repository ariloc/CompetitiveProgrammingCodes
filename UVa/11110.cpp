#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int MAXN = 105;
const int INF = 1e9+5;

int part[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int n;
    while (cin >> n) {
        if (!n) break; cin.ignore();
        memset(done,0,sizeof(done));
        memset(part,0,sizeof(part));
        forn(i,n-1) {
            int cnt = 0;
            string s; stringstream ss;
            getline(cin,s);
            ss << s; vi val;
            while (ss) {
                int x; if (!(ss >> x)) continue;
                val.pb(x-1);
                if (val.size() == 2) {
                    cnt++;
                    part[val[0]][val[1]] = i+1;
                    val.clear();
                }
            }
        }
        int div = 0;
        forn(i,n) forn(j,n) {
            if(!done[i][j]) {
                int cnt = 0; div++;
                queue<ii> Q; done[i][j] = true;
                Q.push({i,j});

                while (not Q.empty()) {
                    auto e = Q.front(); Q.pop(); cnt++;

                    forn(k,4) {
                        int tY = e.fst+Y[k], tX = e.snd+X[k];
                        if (tY < 0 or tX < 0 or tY >= n or tX >= n) continue;
                        if (done[tY][tX]) continue;
                        if (part[tY][tX] != part[i][j]) continue;
                        done[tY][tX] = true;
                        Q.push({tY,tX});
                    }
                }
                if (cnt != n) div = -INF; // lo invalidamos
            }
        }
        if (div != n) cout << "wrong\n";
        else cout << "good\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
