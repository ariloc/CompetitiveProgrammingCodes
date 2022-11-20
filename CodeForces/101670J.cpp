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

const int X[] = {0,1,-1,0};
const int Y[] = {1,0,0,-1};
const int MAXN = 2005;

vector<ii> coords;
bitset<MAXN> done;
vi G[MAXN];
int match[MAXN];

bool try_kuhn (int st) {
    if (done[st]) return false;
    done[st] = true;

    for (auto &i : G[st]) {
        if (done[i]) continue;
        if (match[i] == -1 || (try_kuhn(match[i]))) {
            match[i] = st;
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    while (scanf("%d",&n) != -1) {
        coords.clear();
        forn(i,n) done[i] = false, G[i].clear(), match[i] = -1;

        forn(i,n) {
            int x,y; scanf("%d %d",&x,&y);
            coords.pb({x,y});
        }

        sort(all(coords));

        forn(i,n) {
            forn(k,4) {
                int tX = coords[i].fst + X[k], tY = coords[i].snd + Y[k];
                ii act = make_pair(tX,tY);
                auto it = lower_bound(all(coords), act);

                if (it == coords.end() || (*it != act)) continue;
                
                int ind = it - coords.begin();
                G[i].pb(ind), G[ind].pb(i);
            }
        }

        int cnt = 0;
        forn(i,n) {
            forn(j,n) done[j] = false;
            if(try_kuhn(i)) cnt++;
        }

        printf("%d\n",n-cnt/2);
    }
 
    return 0;
}
