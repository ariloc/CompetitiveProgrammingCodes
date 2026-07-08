#include<bits/stdc++.h>
#include<cassert>

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
int const INF = 2e9;

int cap[MAXN], pos[MAXN], typ[MAXN], stat[MAXN];
vi stations[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;

        forn(i,n) stations[i].clear();

        forn(i,n) cin >> cap[i];
        forn(i,m) {
            cin >> pos[i];
            cin >> typ[i];
            --typ[i];
            stations[typ[i]].pb(i);
        }
        forn(i,n) reverse(all(stations[i]));
        
        forn(i,n) stat[i] = cap[i];

        int curpos = 0;
        set<ii> avail;
        set<int> every;
        forn(i,n) if (!stations[i].empty()) {
            int prim = stations[i].back();
            avail.insert({pos[prim], typ[prim]});
        }
        forn(i,n) every.insert(i);
        forn(i,m) {
            while (curpos < pos[i]) {
                auto it = avail.lower_bound({pos[i], -INF});
                int curtyp;
                if (it != avail.end()) {
                    curtyp = (*it).snd;
                }
                else if (!every.empty()) {
                    auto it2 = every.begin();
                    curtyp = *it2;
                }
                else break;

                int take = min(pos[i]-curpos, stat[curtyp]);
                curpos += take;
                stat[curtyp] -= take;
                
                if (!stat[curtyp]) {
                    if (it != avail.end()) avail.erase(it);
                    every.erase(curtyp);
                }
            }
            if (curpos == pos[i]) {
                every.insert(typ[i]);
                stat[typ[i]] = cap[typ[i]];

                avail.erase({pos[i], typ[i]});
                stations[typ[i]].pop_back();
                if (!stations[typ[i]].empty()) {
                    int prim = stations[typ[i]].back();
                    avail.insert({pos[prim], typ[prim]});
                }
            }
            else break;
        }

        ll rta = curpos;
        if (rta == pos[m-1])
            forn(i,n) rta += stat[i];

        cout << rta << '\n';
    }
   
    return 0;
}
