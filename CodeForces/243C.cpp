#include <algorithm>
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

const string URDL = "URDL";
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int INF = 2e9;
const int MAXN = 4005;

vector<ii> walk;
vi ptsx, ptsy;
bool spray[MAXN][MAXN], done[MAXN][MAXN];
ll rta = 0;

void dfs (int y, int x) {
    if (y < 0 || x < 0 || y >= (int)(ptsy.size()+2) || x >= (int)(ptsx.size()+2)) return;
    if (done[y][x] || spray[y][x]) return;
    done[y][x] = true;
    forn(k,4) dfs(y+Y[k],x+X[k]);
}

void dfs2 (int y, int x) {
    if (y < 0 || x < 0 || y >= (int)(ptsy.size()+2) || x >= (int)(ptsx.size()+2)) return;
    if (done[y][x]) return;
    done[y][x] = true;
    rta += abs(ptsx[x]-ptsx[x-1]) * (ll)abs(ptsy[y]-ptsy[y-1]);
    forn(k,4) dfs2(y+Y[k],x+X[k]);
}

void update (int &x, vi &arr) {
    x = lower_bound(all(arr),x)-arr.begin();
}

int main() {
    FAST_IO;

    int n; cin >> n;

    ii act = {0,0};
    walk.pb(act);
    ptsx.pb(0), ptsy.pb(0);
    ptsx.pb(-1), ptsy.pb(-1); // edge cases
    ptsx.pb(-INF), ptsy.pb(-INF); // slack for coords, now 0,0 is outside
    forn(i,n) {
        char c; int x; cin >> c >> x;
        forn(k,4) {
            if (c == URDL[k]) {
                act.fst += Y[k]*x, act.snd += X[k]*x;
                walk.pb(act);
                ptsy.pb(act.fst), ptsx.pb(act.snd);
                
                // THIS makes edge cases easier: now points of rectangle are exactly one height
                ptsy.pb(act.fst-1), ptsx.pb(act.snd-1);
            }
        }
    }

    sort(all(ptsx));
    ptsx.erase(unique(all(ptsx)),ptsx.end());

    sort(all(ptsy));
    ptsy.erase(unique(all(ptsy)),ptsy.end());

    for (auto &i : walk) update(i.fst,ptsy), update(i.snd,ptsx);

    forsn(i,1,walk.size()) {
        int dy = (walk[i].fst-walk[i-1].fst), dx = (walk[i].snd-walk[i-1].snd);
        if(dy) dy /= abs(dy);
        if(dx) dx /= abs(dx);
        ii aux = walk[i-1];
        spray[aux.fst][aux.snd] = true;
        do {
            aux.fst += dy, aux.snd += dx;
            spray[aux.fst][aux.snd] = true;
        }
        while (aux.fst != walk[i].fst || aux.snd != walk[i].snd);
    }

    dfs(0,0);
    dfs2(walk[0].fst,walk[0].snd);

    cout << rta;

    return 0;
}
