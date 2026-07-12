#include <vector>
#include <algorithm>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;

int perc;
vi G[MAXN];

int go(int st) {
    vi cnts;
    for (auto &i : G[st]) cnts.pb(go(i));

    if (cnts.empty()) return 1;

    sort(all(cnts));
    int grab = (sz(cnts)*perc + 99)/100;
    int acc = 0;
    forn(i,grab) acc += cnts[i];
    return acc;
}

int petitorios(int T, vector<int> &jefes) {
    perc = T;
    forn(i,sz(jefes)) G[jefes[i]].pb(i+1);
    return go(0);
}
