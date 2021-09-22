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

const int MAXM = 1e5+5;
const int MAXN = 2*MAXM;
const int MOD = 1e9+7;

vi buses_end[MAXN];
int dp[MAXN],dpL[MAXN];
vector<ii> inp;
vi stops;

void update (int &x, vi &lst) {
    x = lower_bound(all(lst),x)-lst.begin();
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int s,t; cin >> s >> t;
        inp.pb({s,t});
        stops.pb(s), stops.pb(t);
    }

    stops.pb(0), stops.pb(n); // me agrego los extremos por casos borde

    sort(all(stops));
    stops.erase(unique(all(stops)),stops.end());
    for (auto &i : inp) update(i.fst,stops), update(i.snd,stops);

    forn(i,m) buses_end[inp[i].snd+1].pb(inp[i].fst+1); // +1 por seguridad dp

    int cnt_stops = stops.size();

    dp[1] = dpL[1] = 1;
    forsn(i,2,cnt_stops+1) {
        for (auto &j : buses_end[i])
            dp[i] = ((((dp[i] + dpL[i-1])%MOD) - dpL[j-1])%MOD + MOD)%MOD;
        dpL[i] = (dpL[i-1] + dp[i])%MOD;
    }

    cout << dp[cnt_stops];

    return 0;
}