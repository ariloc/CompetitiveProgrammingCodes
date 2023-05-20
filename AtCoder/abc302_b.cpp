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

const string STR = "snuke";
const int MAXN = 105;
const int X[] = {1,0,-1,0,1,-1,1,-1};
const int Y[] = {0,1,0,-1,1,1,-1,-1};

string grid[MAXN];

int h,w;

bool isOk (int i, int j) {
    return i >= 0 && j >= 0 && i < h && j < w;
}

vector<ii> search (int i, int j, int k) {
    vector<ii> ret;
    forn(l,5) {
        if (!isOk(i,j)) return {};
        if (grid[i][j] != STR[l]) return {};
        ret.pb({i,j});
        i += Y[k], j += X[k];
    }
    return ret;
}

int main() {
    FAST_IO;

    cin >> h >> w;
    forn(i,h) cin >> grid[i];

    forn(i,h) forn(j,w) {
        forn(k,8) {
            vector<ii> aux = search(i,j,k);
            if (!aux.empty()) {
                for (auto &o : aux) {
                    cout << o.fst+1 << ' ' << o.snd+1 << '\n';
                }
                return 0;
            }
        }
    }
   
    return 0;
}
