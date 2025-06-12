#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

using namespace std;

int const MAXN = 2e5+5;
ll const INFL = 1e18;

pair<ll,ll> prefs[MAXN];

long long cletas(vector<int> &x, vector<int> &c) {
    int n = (int)x.size();

    ll b = 0;
    for (auto &i : c) b += i;
    b /= n;

    vector<ii> stations;
    forn(i,n) stations.pb({x[i],c[i]});
    sort(all(stations));

    ll mini = INFL;

    ll cost = 0, cnt = 0;
    forn(i,n) {
        if (i) 
            cost += abs(cnt) * (ll)(stations[i].fst - stations[i-1].fst);
        cnt += stations[i].snd-b;
        prefs[i] = {cost,cnt};
    }
    mini = min(mini, cost);

    cost = cnt = 0;
    dforn(i,n) {
        if (i < n-1) 
            cost += abs(cnt) * (ll)(stations[i+1].fst - stations[i].fst);
        cnt += stations[i].snd-b;
        if (i) 
            mini = min(mini, cost + prefs[i-1].fst + (ll)(stations[i].fst - stations[i-1].fst) * abs(cnt));
    }
    mini = min(mini, cost);

    return mini;
}
